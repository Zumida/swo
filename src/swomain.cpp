#include "swoconfig.hpp"
#include "string.hpp"
#include "swomain.hpp"
#include "application.hpp"

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
		Stdlog << "Application is booting." << std::endl;
		app.boot();

		Stdlog << "Application is initializing." << std::endl;
		app.initialize();

		if (!app.isTerminated()) {
			Stdlog << "Application is running." << std::endl;
			app.run();
		}

	} catch (const std::exception &e) {
		Stderr << "Catch a std::exception! : " << e.what() << std::endl;
		app.terminate(-1);

	} catch (...) {
		Stderr << "Catch an unexpected exception! : "
			<< "result=" << app.getResult() << std::endl;
		app.terminate(-1);
	}

	try {
		Stdlog << "Application is finalizing." << std::endl;
		app.finalize();

	} catch (const std::exception &e) {
		Stderr << "Catch a std::exception! : " << e.what() << std::endl;

	} catch (...) {
		Stderr << "Catch an unexpected exception!" << std::endl;
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
