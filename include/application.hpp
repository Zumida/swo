/*
 * application.hpp
 *
 * Last modified: <2014/01/18 10:46:47 +0900> By Zumida
 */
#ifndef APPLICATION_HPP_INCLUDED
#define APPLICATION_HPP_INCLUDED

#include "swoconfig.hpp"
#include "object.hpp"
#include "eventlistener.hpp"
#include "runner.hpp"

#define MakeApplication(RunnerClassType) \
	RunnerClassType runner; \
	Application myapp(&runner);

namespace swo {
	inline namespace core {

		class Application : public Object {
		public:
			enum class Status {
				BOOT,
				INITIALIZE,
				RUN,
				FINALIZE,
			};

		private:
			static class Application *instance;

			String processName;
			Runner* runner;
			Status status;
			StringList arguments;

			bool terminated;
			int result;

			WndMap wndMap;

		public:
			static class Application& getInstance(void);

			Application() = delete;
			Application(const Runner* runner);
			~Application();

			void initialize(void);
			void run(void);
			void finalize(void);

			static void terminate(int result=0);

			const String& getProcessName(void) const;
			StringList& getArguments(void);
			int getResult(void) const;
			const Status& getStatus(void) const;

			bool isRunning(void) const;
			bool isTerminated(void) const;

			static EventListener* findListener(const HWND hWnd);
			static void addListener(const HWND hWnd, const EventListener* listener);
			static void removeListener(const HWND hWnd);
			static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
		};
	};
};

#endif
