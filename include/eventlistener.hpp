/*
 * eventlistener.hpp
 *
 * Last modified: <2013/04/11 06:36:38 +0900> By Zumida
 */
#ifndef EVENTLISTENER_HPP_INCLUDED
#define EVENTLISTENER_HPP_INCLUDED

#include <map>
#include <windows.h>
#include "object.hpp"
#include "dragdrop.hpp"
#include "canvas.hpp"

namespace swo {

	typedef std::map<HWND, class EventListener*> WndMap;

	class EventListener : public Object {
	private:
		HWND handle;

	protected:
		void setHandle(HWND handle);

		virtual bool wndproc(UINT msg, WPARAM wp, LPARAM lp);

		virtual bool onCreate(void) {return false;}
		virtual bool onDestroy(void) {return false;}
		virtual bool onActive(void) {return false;}
		virtual bool onInactive(void) {return false;}
		virtual bool onActiveApp(void) {return false;}
		virtual bool onInactiveApp(void) {return false;}
		virtual bool onKeyPress(int virtKey, int keyData) {return false;}
		virtual bool onCloseQuery(void) {return true;}
		virtual bool onClose(void) {return false;}
		virtual bool onCommand(int id) {return false;}
		virtual bool onDropFiles(const DragDrop& dd) {return false;}
		virtual bool onEnable(void) {return false;}
		virtual bool onDisable(void) {return false;}
		virtual bool onEnterSizeMove(void) {return false;}
		virtual bool onEraseBackGround(Canvas& canvas) {return false;}
		virtual bool onExitSizeMove(void) {return false;}
		virtual bool onHelp(void) {return false;}
		virtual bool onHotKey(int id, int mod) {return false;}
		virtual bool onHorizontalScroll(HWND hWnd, int sb, int pos) {return false;}
		virtual bool onInitDialog(HWND hWnd, int param) {return false;}
		virtual bool onKeyDown(int virtKey, int keyData) {return false;}
		virtual bool onKeyUp(int virtKey, int keyData) {return false;}
		virtual bool onFocusOut(void) {return false;}
		virtual bool onMenuCommand(HWND hWnd, int index) {return false;}
		virtual bool onMenuSelect(HMENU hMenu, int cmd, int mf) {return false;}
		virtual bool onMove(int x, int y) {return false;}
		virtual bool onMoving(int wmsz, Rect& rect) {return false;}
		virtual bool onPaint(Canvas& canvas) {return false;}
		virtual bool onQuit(int exitCode) {return false;}
		virtual bool onShow(void) {return false;}
		virtual bool onHide(int sw) {return false;}
		virtual bool onSize(int sizeType, int width, int height) {return false;}
		virtual bool onSizing(int wmsz, Rect& rect) {return false;}
		virtual bool onSysKeyPress(int charCode, int keyData) {return false;}
		virtual bool onSysCommand(int sysCmd, int x, int y) {return false;}
		virtual bool onSysKeyDown(int virtKey, int keyData) {return false;}
		virtual bool onSysKeyUp(int virtKey, int keyData) {return false;}
		virtual bool onVerticalScroll(HWND hWnd, int sb, int pos) {return false;}
		virtual bool onWindowPosChanged(WindowPos& pos) {return false;}
		virtual bool onWindowPosChanging(WindowPos& pos) {return false;}
		virtual bool onSyncPaint(void) {return false;}
		virtual bool onMouseMove(int virtKey, int x, int y) {return false;}
		virtual bool onLeftButtonDown(int fwKeys, int x, int y) {return false;}
		virtual bool onLeftButtonUp(int fwKeys, int x, int y) {return false;}
		virtual bool onLeftButtonDoubleClick(int fwKeys, int x, int y) {return false;}
		virtual bool onRightButtonDown(int fwKeys, int x, int y) {return false;}
		virtual bool onRightButtonUp(int fwKeys, int x, int y) {return false;}
		virtual bool onRightButtonDoubleClick(int fwKeys, int x, int y) {return false;}
		virtual bool onMiddleButtonDown(int fwKeys, int x, int y) {return false;}
		virtual bool onMiddleButtonUp(int fwKeys, int x, int y) {return false;}
		virtual bool onMiddleButtonDoubleClick(int fwKeys, int x, int y) {return false;}
		virtual bool onMouseWheel(int zDelta, int fwKeys, int x, int y) {return false;}
		virtual bool onXButtonDown(int fwButton, int fwKeys, int x, int y) {return false;}
		virtual bool onXButtonUp(int fwButton, int fwKeys, int x, int y) {return false;}
		virtual bool onXButtonDoubleClick(int fwButton, int fwKeys, int x, int y) {return false;}
		virtual bool onMouseHover(int fwKeys, int x, int y) {return false;}
		virtual bool onMouseLeave(void) {return false;}

	public:
		EventListener();
		virtual ~EventListener();

		HWND getHandle(void) const;

		static EventListener* findListener(HWND hWnd);
		static void addListener(HWND hWnd, class EventListener* listener);
		static void removeListener(HWND hWnd);
		static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp);
	};

};

#endif
