#include "swomain.hpp"
#include "application.hpp"
#include <stdio.h>

using namespace swo;

class DbgStreamBuf : public std::basic_streambuf<TCHAR> {
private:
	String tag;
	String line;

public:
	DbgStreamBuf() {}

	DbgStreamBuf(const String& tag) {
		this->tag = L"[" + tag + L"] ";
	}

	~DbgStreamBuf() {
		flush();
	}

	virtual int_type overflow(int_type c = WEOF) {
		switch (c) {
		case '\n':
			line += c;
			//not break;
		case WEOF:
			flush();
			break;
		default:
			line += c;
			break;
		}
		return c;
	}

	void flush(void) {
		if (!line.empty()) {
			::OutputDebugString((tag + line).c_str());
			line.clear();
		}
	}
};

int WINAPI _tWinMain(
	HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR pCmdLine, int showCmd) {

	DbgStreamBuf dout(L"stdout");
	DbgStreamBuf derr(L"stderr");
	DbgStreamBuf dlog;
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

	Stdlog << "Application is finalizing." << std::endl;
	app.finalize();

	Stdout.rdbuf(NULL);
	Stderr.rdbuf(NULL);
	Stdlog.rdbuf(NULL);

	return app.getResult();
}

int main(const int argc, const char* argv[]) {
	::_tsetlocale(LC_ALL, L"");

	return _tWinMain(::GetModuleHandle(NULL), NULL, NULL, SW_SHOW);
}
