/*
 * application.hpp
 *
 * Last modified: <2013/08/27 01:04:50 +0900> By Zumida
 */
#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "define.hpp"
#include "stringlist.hpp"
#include "control.hpp"
#include "eventlistener.hpp"

namespace swo {

	class Application : public Object {
	private:
		static class Application instance;

		enum {
			BOOT,
			INITIALIZE,
			RUN,
			FINALIZE
		} status;

		StringList arguments;
		Objects objects;
		Controls controls;

		bool terminated;
		int result;

		WndMap wndMap;

		Application();
		~Application();

	public:
		/*
		 * NOTE : Application::initialize()
		 * ライブラリ側では準備をしていない。
		 * 必ず利用者が準備すること。
		 * It has not prepared in the library side. 
		 * A user needs to prepare at any cost.
		 */
		void initialize(void);

		void boot(void);
		void finalize(void);
		void terminate(int result=0);

		StringList& getArguments(void);
		int getResult(void) const;

		bool isRunning(void) const;
		bool isTerminated(void) const;

		void add(Object* object);
		void remove(Object* object);
		void run(void);

		template<typename T> T& createObject(void) {
			T *obj = new T();
			add(obj);
			return *obj;
		}

		template<typename T> T& createObject(Control& parent) {
			T *obj = new T(&parent);
			add(obj);
			return *obj;
		}

		static class Application& getInstance(void);
		static EventListener* findListener(const HWND hWnd);
		static void addListener(const HWND hWnd, const class EventListener* listener);
		static void removeListener(const HWND hWnd);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
	};
};

#endif
