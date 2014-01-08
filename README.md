SWO - Simple Widget Objects library
===================================

MingwによるWindowsGUIアプリケーション作成を支援するためのC++ライブラリです。
Win32APIのシンプルなラッパーです。しかし、まだ未完成です。

It is a C++ library for supporting the WindowsGUI application creation by Mingw.
It is a simple wrapper of Win32API.
However, it is still incomplete.

Usage
-----
1. swo.hpp他、必要なヘッダファイルをインクルードする。  
   Include required header files.  

2. Application::initialize()を用意する。  
   Prepare Application::initialize().   

3. Application::initialize()内でウィジットを生成し初期設定を行う。  
   Generate widget, and perform initial setting.  

main.cpp

	#include "swo.hpp"
	#include "form.hpp"
	
	void Application::initialize(void) {
	
		Form& form = Form::create();
		form.show();
	}

Compile
-------
ライブラリ指定にlibswo.aを追加する。  
Add a libswo.a to specify library.  

必要に応じてインクルードパスとライブラリパスを追加してください。  
Please add an include path and a library path if needed.  

	g++ -o guitest.exe -std=c++11 -I/home/swo/include main.cpp -L/home/swo/lib -mwindows -static -lswo  

License
-------
Copyright &copy; 2014 Zumida  
Distributed under the [MIT License][mit].  

[MIT]: http://www.opensource.org/licenses/mit-license.php
