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
	public:
		void run(void) {
	
			Form& form = Form::create();
			form.show();
		}
	});


ログ出力を活用する場合は、クラス定義をMakeApplication()の外で行います。
When utilizing a log output, a class definition is performed outside MakeApplication(). 

main.cpp

	#include "swo.hpp"
	#include "logger.hpp"
	#include <exception>
	
	using namespace swo;
	
	class MyRunner : public Runner {
	
	public:
		void run(void) {
			/*
			 * 標準出力/標準エラー出力/標準ログ出力は、
			 * DebugViewまたはgdbにて確認すること！
			 */
			LOG_I(L"通常ログ出力");
	
			LOG_W(L"警告ログ出力");
	
			LOG_E(L"エラーログ出力");
	
			LOG_D(L"デバッグログ出力");
	
			try {
				throw std::exception();
	
			} catch (std::exception &e) {
				LOG_EX(e);
			}
		}
	};
	
	MakeApplication(MyRunner);

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
