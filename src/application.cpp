/*
 * application.cpp
 *
 * Last modified: <2014/01/10 02:57:19 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "application.hpp"
#include "instance.hpp"
#include <windows.h>

namespace swo {
	inline namespace core {

		Application Application::instance;

		Application::Application()
		: status(Status::BOOT), terminated(false), result(0) {}

		Application::~Application() {}

		Application& Application::getInstance(void) {
			return instance;
		}

		void Application::initialize(void) {
			status = Status::INITIALIZE;

			// コマンドライン引数の取得
			int argc = 0;
			WCHAR **argv = ::CommandLineToArgvW(::GetCommandLineW(), &argc);

			if (argv != nullptr) {
				for (int i = 0; i < argc; ++i) {
					arguments.push_back(argv[i]);
				}
				::GlobalFree(argv);
			}
		}

		void Application::run(void) {
			status = Status::RUN;

			// ランナーの実行
			runner->run();

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

		void Application::finalize(void) {

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

		StringList& Application::getArguments(void) {
			return arguments;
		}

		int Application::getResult(void) const {
			return result;
		}

		Application::Status Application::getStatus(void) const {
			return status;
		}

		bool Application::isRunning(void) const {
			return (status == Status::RUN);
		}

		bool Application::isTerminated(void) const {
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

		void Application::setRunner(const Runner* runner) {

			if (runner == nullptr) {
				throw std::runtime_error("Runner instance is null.");
			}

			Application& app = getInstance();

			if (app.runner == nullptr) {
				app.runner = const_cast<Runner*>(runner);
			} else {
				throw std::runtime_error(
					"Application runner instance is not null.");
			}
		}
	};
};
