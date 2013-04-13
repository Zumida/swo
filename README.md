SWO - Simple Widget Objects library
===================================

MingwによるWindowsGUIアプリケーション作成を支援するためのC++ライブラリです。
Win32APIのシンプルなラッパーです。しかし、まだ未完成です。

It is a C++ library for supporting the WindowsGUI application creation by Mingw.
It is a simple wrapper of Win32API.
However, it is still incomplete.

Usage
-----
1. Appicationクラスのインスタンスよりウィジットを生成する。  
   Generate widget from the instance of an Appication class.  

2. ウィジットの初期設定を行う。  
   Perform initial setting of widget.  

3. Appicationクラスのインスタンスのrun()にてWindowsメッセージを処理する。  
   Process a Windows message in run() of the instance of an Appication class.  

main.cpp

	#include "application.hpp"
	#include "form.hpp"
	
	using namespace swo;
	
	int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPTSTR pCmdLine, int showCmd) {
		
		Application app;
		
		Form& form = app.createObject<Form>();
		form.show();
		
		return app.run();
	}

	#ifndef wWinMain
	int main(const int argc, const char** argv) {
		::_tsetlocale(LC_ALL, L"");
		
		return _tWinMain(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), SW_SHOW);
	}
	#endif

Compile
-------
ライブラリ指定にlibswo.aを追加する。  
Add a libswo.a to specify library.  

必要に応じてインクルードパスとライブラリパスを追加してください。  
Please add an include path and a library path if needed.  

	g++ -o guitest.exe -I/home/swo/include -DWIN32 -DUNICODE -D_UNICODE main.cpp -L/home/swo/lib -mwindows -static -lswo  

License
-------
Copyright &copy; 2013 Zumida  
Distributed under the [MIT License][mit].  

[MIT]: http://www.opensource.org/licenses/mit-license.php
