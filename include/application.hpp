/*
 * application.hpp
 *
 * Last modified: <2013/10/20 11:18:09 +0900> By Zumida
 */
#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "define.hpp"
#include "stringlist.hpp"
#include "control.hpp"
#include "eventlistener.hpp"

namespace swo {

	typedef std::list<class Control*> Controls;

	class Application : public Object {
	public:
		enum Status {
			BOOT,
			INITIALIZE,
			RUN,
			FINALIZE
		};

	private:
		static class Application instance;

		Status status;
		StringList arguments;
		Objects objects;
		Controls controls;

		bool terminated;
		int result;

		WndMap wndMap;

		Application();
		~Application();

	public:
		static class Application& getInstance(void);

		/*
		 * NOTE : Application::initialize()
		 * ライブラリ側では準備をしていない。
		 * 必ず利用者が準備すること。
		 * It has not prepared in the library side. 
		 * A user needs to prepare at any cost.
		 */
		void boot(void);
		void initialize(void);
		void run(void);
		void finalize(void);

		static void terminate(int result=0);

		StringList& getArguments(void);
		int getResult(void) const;
		Status getStatus(void) const;

		bool isRunning(void) const;
		bool isTerminated(void) const;

		void add(Object* object);
		void remove(Object* object);

		static EventListener* findListener(const HWND hWnd);
		static void addListener(const HWND hWnd, const EventListener* listener);
		static void removeListener(const HWND hWnd);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
	};
};

#endif
