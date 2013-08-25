/*
 * application.hpp
 *
 * Last modified: <2013/08/25 08:37:21 +0900> By Zumida
 */
#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "define.hpp"
#include "stringlist.hpp"
#include "control.hpp"

namespace swo {

	class Application : public Object {
	private:
		static class Application instance;

		StringList arguments;
		Objects objects;
		Controls controls;

		bool running;
		bool terminated;
		int result;

		Application();
		~Application();

	public:
		/*
		 * NOTE : Application::main()
		 * ライブラリ側では準備をしていない。
		 * 必ず利用者が準備すること。
		 * It has not prepared in the library side. 
		 * A user needs to prepare at any cost.
		 */
		void main(void);

		void initialize(void);
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
	};

};

#endif
