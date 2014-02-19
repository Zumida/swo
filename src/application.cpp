/*
 * application.cpp
 *
 * Last modified: <2014/02/17 23:29:31 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "application.hpp"
#include "instance.hpp"
#include "uri.hpp"
#include <windows.h>

namespace swo {
	inline namespace core {

		Application* Application::instance;

		Application::Application(const Runner* runner)
		: processName(L"Application"), runner(const_cast<Runner*>(runner)),
		status(Status::BOOT), terminated(false), result(0) {

			if (runner == nullptr) {
				throw std::runtime_error("Runner instance is null.");
			}

			if (instance == nullptr) {
				instance = this;
			} else {
				throw std::runtime_error("Application instance is not null.");
			}
		}

		Application::~Application() {}

		Application& Application::getInstance() {
			return *instance;
		}

		void Application::initialize(HINSTANCE handle) {
			status = Status::INITIALIZE;
			this->handle = handle;

			// コマンドライン引数の取得
			int argc = 0;
			WCHAR **argv = ::CommandLineToArgvW(::GetCommandLineW(), &argc);

			if (argv != nullptr) {
				for (int i = 0; i < argc; ++i) {
					arguments.push_back(argv[i]);
				}
				::GlobalFree(argv);

				if (arguments.size() > 0) {
					processName = swo::uri::filename(arguments.front());
				}
			}
		}

		void Application::run() {
			status = Status::RUN;

			// ランナーの実行
			runner->run();

			if (Instance::getControls().size() > 0) {

				// メッセージループ
				MSG msg;
				while (!isTerminated()) {
					// 更新予約コントロールを更新
					ControlPtrList &controls = Instance::getControls();
					for (auto it = controls.begin(); it != controls.end(); ) {

						Control* c = *it;
						if (c->isTerminated()) {
							it = controls.erase(it);
							delete c;
							continue;
						}
						if (c->getParent() != nullptr && c->isUpdated()) {
							c->refresh();
						}
						it++;
					}

					// メッセージ取得失敗、終了メッセージ受信時はループ終了
					int result = GetMessage(&msg, nullptr, 0, 0);
					if (result == 0 || result == -1) break;

					// メッセージを処理する
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}

				if (!isTerminated()) {
					this->result = static_cast<int>(msg.wParam);
				}
			}
		}

		void Application::finalize() {

			status = Status::FINALIZE;

			// 登録されたインスタンスを破棄
			Instance::discard();
		}

		void Application::terminate(int result) {
			Application& app = getInstance();
			app.result = result;
			app.terminated = true;
			::PostQuitMessage(result);
		}

		const HINSTANCE Application::getHandle() const {
			return handle;
		}

		const String& Application::getProcessName() const {
			return processName;
		}

		StringList& Application::getArguments() {
			return arguments;
		}

		int Application::getResult() const {
			return result;
		}

		const Application::Status& Application::getStatus() const {
			return status;
		}

		bool Application::isRunning() const {
			return (status == Status::RUN);
		}

		bool Application::isTerminated() const {
			return terminated;
		}

		void Application::addListener(
			const HWND hWnd, const EventListener* listener) {

			WndMap& map = getInstance().wndMap;

			map.insert(
				std::make_pair(const_cast<HWND>(hWnd),
							   const_cast<EventListener*>(listener)));
		}

		void Application::removeListener(HWND hWnd) {
			getInstance().wndMap.erase(hWnd);
		}

		EventListener* Application::findListener(HWND hWnd) {
			Application& app = getInstance();

			if (app.isRunning()) {
				WndMap& map = app.wndMap;
				WndMap::iterator it = map.find(hWnd);
				return (it == map.end())? nullptr: it->second;
			} else {
				return nullptr;
			}
		}

		LRESULT CALLBACK Application::WndProc(
			HWND hWnd, UINT msg, WPARAM wp, LPARAM lp) {

			EventListener* listener = findListener(hWnd);

			if (listener != nullptr && listener->wndproc(msg, wp, lp))
				return 0;
			else
				return ::DefWindowProc(hWnd, msg, wp, lp);
		}
	};
};
