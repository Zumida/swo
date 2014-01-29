#include "swoconfig.hpp"
#include "string.hpp"
#include "swomain.hpp"
#include "application.hpp"
#include "logger.hpp"

using namespace swo;

class DebugStream : public std::basic_streambuf<TCHAR> {
private:
	String tag;
	String message;

public:
	DebugStream() {}
	DebugStream(const String& tag) : tag(L"<" + tag + L"> ") {}

	~DebugStream() {
		flush();
	}

	void setTag(const String& tag) {
		this->tag = tag + L" ";
	}

	virtual int_type overflow(int_type c = WEOF) {
		switch (c) {
		case '\n':
		case WEOF:
			flush();
			break;

		default:
			message += c;
			break;
		}
		return c;
	}

	void flush(void) {
		if (!message.empty()) {
			::OutputDebugString((tag + message).c_str());
			message.clear();
		}
	}
};

int WINAPI _tWinMain(
	HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR pCmdLine, int showCmd) {

	DebugStream dout(L"stdout");
	DebugStream derr(L"stderr");
	DebugStream dlog;
	Stdout.rdbuf(&dout);
	Stderr.rdbuf(&derr);
	Stdlog.rdbuf(&dlog);

	Application& app = Application::getInstance();

	try {
		LOG_I(app.getProcessName() + L" is initializing.");
		app.initialize();
		dlog.setTag(app.getProcessName());

		LOG_I(app.getProcessName() + L" is running.");
		app.run();

	} catch (const swo::exception::Exception &e) {
		LOG_EX(e);
		app.terminate(-1);

	} catch (const std::exception &e) {
		LOG_EX(e);
		app.terminate(-1);

	} catch (...) {
		LOG_E(L"Catch an unexpected exception! : "
			  L"result=" + app.getResult());
		app.terminate(-1);
	}

	try {
		LOG_I(app.getProcessName() + L" is finalizing.");
		app.finalize();

	} catch (const swo::exception::Exception &e) {
		LOG_EX(e);

	} catch (const std::exception &e) {
		LOG_EX(e);

	} catch (...) {
		LOG_E(L"Catch an unexpected exception!");
	}

	try {
		dout.flush();
		derr.flush();
		dlog.flush();
	} catch (...) {}

	try {
		Stdout.rdbuf(nullptr);
		Stderr.rdbuf(nullptr);
		Stdlog.rdbuf(nullptr);
	} catch (...) {}

	return app.getResult();
}

int main(const int argc, const char* argv[]) {
	::_tsetlocale(LC_ALL, L"");

	return _tWinMain(::GetModuleHandle(nullptr), nullptr, nullptr, SW_SHOW);
}
