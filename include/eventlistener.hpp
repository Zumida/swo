/*
 * eventlistener.hpp
 *
 * Last modified: <2014/01/30 16:39:54 +0900> By Zumida
 */
#ifndef EVENTLISTENER_HPP_INCLUDED
#define EVENTLISTENER_HPP_INCLUDED

#include "control.hpp"
#include "dragdrop.hpp"
#include "canvas.hpp"
#include <map>

namespace swo {
	inline namespace control {

		using WndMap = std::map<HWND, class EventListener*>;

		class EventListener : public Control {
		public:
			EventListener();
			EventListener(Control& parent);
			~EventListener();

			void setHandle(HWND handle);

			virtual bool wndproc(UINT msg, WPARAM wp, LPARAM lp);
			virtual bool onCreate() {return false;}
			virtual bool onDestroy() {return false;}
			virtual bool onActive() {return false;}
			virtual bool onInactive() {return false;}
			virtual bool onActiveApp() {return false;}
			virtual bool onInactiveApp() {return false;}
			virtual bool onKeyPress(int virtKey, int keyData) {return false;}
			virtual bool onCloseQuery() {return true;}
			virtual bool onClose() {return false;}
			virtual bool onCommand(int id) {return false;}
			virtual bool onDropFiles(const DragDrop& dd) {return false;}
			virtual bool onEnable() {return false;}
			virtual bool onDisable() {return false;}
			virtual bool onEnterSizeMove() {return false;}
			virtual bool onEraseBackGround(Canvas& canvas) {return false;}
			virtual bool onExitSizeMove() {return false;}
			virtual bool onHelp() {return false;}
			virtual bool onHotKey(int id, int mod) {return false;}
			virtual bool onHorizontalScroll(HWND hWnd, int sb, int pos) {return false;}
			virtual bool onInitDialog(HWND hWnd, int param) {return false;}
			virtual bool onKeyDown(int virtKey, int keyData) {return false;}
			virtual bool onKeyUp(int virtKey, int keyData) {return false;}
			virtual bool onFocusOut() {return false;}
			virtual bool onMenuCommand(HWND hWnd, int index) {return false;}
			virtual bool onMenuSelect(HMENU hMenu, int cmd, int mf) {return false;}
			virtual bool onMove(int x, int y) {return false;}
			virtual bool onMoving(int wmsz, Rect& rect) {return false;}
			virtual bool onPaint(Canvas& canvas) {return false;}
			virtual bool onQuit(int exitCode) {return false;}
			virtual bool onShow() {return false;}
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
			virtual bool onSyncPaint() {return false;}
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
			//virtual bool onXButtonDown(int fwButton, int fwKeys, int x, int y) {return false;}
			//virtual bool onXButtonUp(int fwButton, int fwKeys, int x, int y) {return false;}
			//virtual bool onXButtonDoubleClick(int fwButton, int fwKeys, int x, int y) {return false;}
			virtual bool onMouseHover(int fwKeys, int x, int y) {return false;}
			virtual bool onMouseLeave() {return false;}
		};
	};
};

#endif
