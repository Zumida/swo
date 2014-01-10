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

2. MakeApplication()の引数としてRunnerのサブクラスを用意する。  
   Prepare a subclass of Runner as an argument MakeApplication().   

3. サブクラスのrun()内に実行する処理を記述する。  
   Describe the process to be executed in run() of the subclass.  

main.cpp

	#include "swo.hpp"
	#include "form.hpp"
	
	using namespace swo;
	
	MakeApplication(
	class MyRunner : public Runner {
		void run(void) {
	
			Form& form = Form::create();
			form.show();
		}
	});

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
