/*
 * eventlistener.cpp
 *
 * Last modified: <2014/01/07 19:11:39 +0900> By Zumida
 */
#include "swoconfig.hpp"
#include "eventlistener.hpp"
#include "application.hpp"
#include <windows.h>
#include <windowsx.h>
#include <limits.h>

#ifndef GET_KEYSTATE_WPARAM
#define GET_KEYSTATE_WPARAM(wp) (int)(short)LOWORD(wp)
#endif

#ifndef GET_HWND_WPARAM
#define GET_HWND_WPARAM(wp) ((HWND)wp)
#endif

#ifndef GET_HWND_LPARAM
#define GET_HWND_LPARAM(lp) ((HWND)lp)
#endif

#ifndef GET_WINDOWPOS_LPARAM
#define GET_WINDOWPOS_LPARAM(lp) *((WindowPos*)lp)
#endif

#ifndef GET_RECT_LPARAM
#define GET_RECT_LPARAM(lp) *((Rect*)lp)
#endif

#ifndef GET_W_LPARAM
#define GET_W_LPARAM(lp) (int)(short)LOWORD(lp)
#endif

#ifndef GET_H_LPARAM
#define GET_H_LPARAM(lp) (int)(short)HIWORD(lp)
#endif


using namespace swo;

EventListener::EventListener() : Control() {}

EventListener::EventListener(Control& parent) : Control(parent) {}

EventListener::~EventListener() {}

void EventListener::setHandle(HWND handle) {
	HWND current = Control::getHandle();
	if (current != nullptr) {
		Application::removeListener(current);
	}

	Control::setHandle(handle);
	if (handle != nullptr) {
		Application::addListener(handle, this);
	}
}

bool EventListener::wndproc(UINT msg, WPARAM wp, LPARAM lp) {
	bool result = false;

	switch(msg) {
	//case WM_APP:
	case WM_ACTIVATE:
		result = (GET_WM_ACTIVATE_STATE(wp,lp) == WA_INACTIVE)? onInactive(): onActive();
		break;
	case WM_ACTIVATEAPP:
		result = ((BOOL)wp != TRUE)? onInactiveApp(): onActiveApp();
		break;
	/* FIXME/CHECK: Are WM_AFX{FIRST,LAST} valid for WINVER < 0x400? */
	//case WM_AFXFIRST:
	//case WM_AFXLAST:
	//case WM_ASKCBFORMATNAME:
	//case WM_CANCELJOURNAL:
	//case WM_CANCELMODE:
	//case WM_CAPTURECHANGED:
	//case WM_CHANGECBCHAIN:
	case WM_CHAR:
		result = onKeyPress(wp, lp);
		break;
	//case WM_CHARTOITEM:
	//case WM_CHILDACTIVATE:
	//case WM_CLEAR:
	case WM_CLOSE:
		if (!onCloseQuery()) return true;
		result = onClose();
		break;
	case WM_COMMAND:
		result = onCommand(GET_WM_COMMAND_ID(wp,lp));
		break;
	//case WM_COMPACTING:
	//case WM_COMPAREITEM:
	//case WM_CONTEXTMENU:
	//case WM_COPY:
	//case WM_COPYDATA:
	case WM_CREATE:
		result = onCreate();
		break;
	//case WM_CTLCOLORBTN:
	//case WM_CTLCOLORDLG:
	//case WM_CTLCOLOREDIT:
	//case WM_CTLCOLORLISTBOX:
	//case WM_CTLCOLORMSGBOX:
	//case WM_CTLCOLORSCROLLBAR:
	//case WM_CTLCOLORSTATIC:
	//case WM_CUT:
	//case WM_DEADCHAR:
	//case WM_DELETEITEM:
	case WM_DESTROY:
		result = onDestroy();
		break;
	//case WM_DESTROYCLIPBOARD:
	//case WM_DEVICECHANGE:
	//case WM_DEVMODECHANGE:
	//case WM_DISPLAYCHANGE:
	//case WM_DRAWCLIPBOARD:
	//case WM_DRAWITEM:
	case WM_DROPFILES:
		{
			DragDrop dd((HDROP)wp);
			result = onDropFiles(dd);
			break;
		}
	case WM_ENABLE:
		result = onEnable();
		break;
	//case WM_ENDSESSION:
	//case WM_ENTERIDLE:
	//case WM_ENTERMENULOOP:
	case WM_ENTERSIZEMOVE:
		result = onEnterSizeMove();
		break;
	case WM_ERASEBKGND:
		{
			Canvas cv(getHandle());
			result = onEraseBackGround(cv);
			break;
		}
	//case WM_EXITMENULOOP:
	case WM_EXITSIZEMOVE:
		result = onExitSizeMove();
		break;
	//case WM_FONTCHANGE:
	//case WM_GETDLGCODE:
	//case WM_GETFONT:
	//case WM_GETHOTKEY:
	//case WM_GETICON:
	//case WM_GETMINMAXINFO:
	//case WM_GETTEXT:
	//case WM_GETTEXTLENGTH:
	/* FIXME/CHECK: Are WM_HANDHEL{FIRST,LAST} valid for WINVER < 0x400? */
	//case WM_HANDHELDFIRST:
	//case WM_HANDHELDLAST:
	case WM_HELP:
		result = onHelp();
		break;
	case WM_HOTKEY:
		result = onHotKey(wp, lp);
		break;
	case WM_HSCROLL:
		result = onHorizontalScroll(GET_WM_HSCROLL_HWND(wp,lp),
									GET_WM_HSCROLL_CODE(wp,lp),
									GET_WM_HSCROLL_POS(wp,lp));
		break;
	//case WM_HSCROLLCLIPBOARD:
	//case WM_ICONERASEBKGND:
	case WM_INITDIALOG:
		result = onInitDialog(GET_HWND_WPARAM(wp), lp);
		break;
	//case WM_INITMENU:
	//case WM_INITMENUPOPUP:
#if (_WIN32_WINNT >= 0x0501)
	//case WM_INPUT:
#endif
	//case WM_INPUTLANGCHANGE:
	//case WM_INPUTLANGCHANGEREQUEST:
	case WM_KEYDOWN:
		result = onKeyDown(wp, lp);
		break;
	case WM_KEYUP:
		result = onKeyUp(wp, lp);
		break;
	case WM_KILLFOCUS:
		result = onFocusOut();
		break;
//	case WM_MDIACTIVATE:
//	case WM_MDICASCADE:
//	case WM_MDICREATE:
//	case WM_MDIDESTROY:
//	case WM_MDIGETACTIVE:
//	case WM_MDIICONARRANGE:
//	case WM_MDIMAXIMIZE:
//	case WM_MDINEXT:
//	case WM_MDIREFRESHMENU:
//	case WM_MDIRESTORE:
//	case WM_MDISETMENU:
//	case WM_MDITILE:
//	case WM_MEASUREITEM:
#if (WINVER >= 0x0500)
//	case WM_GETOBJECT:
//	case WM_CHANGEUISTATE:
//	case WM_UPDATEUISTATE:
//	case WM_QUERYUISTATE:
//	case WM_UNINITMENUPOPUP:
//	case WM_MENURBUTTONUP:
	case WM_MENUCOMMAND:
		result = onMenuCommand(GET_HWND_LPARAM(lp), wp);
		break;
//	case WM_MENUGETOBJECT:
//	case WM_MENUDRAG:
//	case WM_APPCOMMAND:
#endif
//	case WM_MENUCHAR:
	case WM_MENUSELECT:
		result = onMenuSelect(GET_WM_MENUSELECT_HMENU(wp,lp),
							  GET_WM_MENUSELECT_CMD(wp,lp),
							  GET_WM_MENUSELECT_FLAGS(wp,lp));
		break;
//	case WM_NEXTMENU:
	case WM_MOVE:
		result = onMove(GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_MOVING:
		result = onMoving(wp, GET_RECT_LPARAM(lp));
		break;
	//case WM_NCACTIVATE:
	//case WM_NCCALCSIZE:
	//case WM_NCCREATE:
	//case WM_NCDESTROY:
	//case WM_NCHITTEST:
	//case WM_NCLBUTTONDBLCLK:
	//case WM_NCLBUTTONDOWN:
	//case WM_NCLBUTTONUP:
	//case WM_NCMBUTTONDBLCLK:
	//case WM_NCMBUTTONDOWN:
	//case WM_NCMBUTTONUP:
#if (_WIN32_WINNT >= 0x0500)
	//case WM_NCXBUTTONDOWN:
	//case WM_NCXBUTTONUP:
	//case WM_NCXBUTTONDBLCLK:
	//case WM_NCMOUSEHOVER:
	//case WM_NCMOUSELEAVE:
#endif
	//case WM_NCMOUSEMOVE:
	//case WM_NCPAINT:
	//case WM_NCRBUTTONDBLCLK:
	//case WM_NCRBUTTONDOWN:
	//case WM_NCRBUTTONUP:
	//case WM_NEXTDLGCTL:
	//case WM_NEXTMENU:
	//case WM_NOTIFY:
	//case WM_NOTIFYFORMAT:
	//case WM_nullptr:
	case WM_PAINT:
		{
			Canvas cv(getHandle());
			result = onPaint(cv);
			break;
		}
	//case WM_PAINTCLIPBOARD:
	//case WM_PAINTICON:
	//case WM_PALETTECHANGED:
	//case WM_PALETTEISCHANGING:
	//case WM_PARENTNOTIFY:
	//case WM_PASTE:
	//case WM_PENWINFIRST:
	//case WM_PENWINLAST:
	//case WM_POWER:
	//case WM_POWERBROADCAST:
	//case WM_PRINT:
	//case WM_PRINTCLIENT:
	//case WM_QUERYDRAGICON:
	//case WM_QUERYENDSESSION:
	//case WM_QUERYNEWPALETTE:
	//case WM_QUERYOPEN:
	//case WM_QUEUESYNC:
	case WM_QUIT:
		result = onQuit(wp);
		break;
	//case WM_RENDERALLFORMATS:
	//case WM_RENDERFORMAT:
	//case WM_SETCURSOR:
	//case WM_SETFOCUS:
	//case WM_SETFONT:
	//case WM_SETHOTKEY:
	//case WM_SETICON:
	//case WM_SETREDRAW:
	//case WM_SETTEXT:
	//case WM_SETTINGCHANGE:
	case WM_SHOWWINDOW:
		result = ((BOOL)wp == TRUE)? onShow(): onHide(lp);
		break;
	case WM_SIZE:
		result = onSize(wp, GET_W_LPARAM(lp), GET_H_LPARAM(lp));
		break;
	//case WM_SIZECLIPBOARD:
	case WM_SIZING:
		result = onSizing(wp, GET_RECT_LPARAM(lp));
		break;
	//case WM_SPOOLERSTATUS:
	//case WM_STYLECHANGED:
	//case WM_STYLECHANGING:
	case WM_SYSCHAR:
		result = onSysKeyPress(wp, lp);
		break;
	//case WM_SYSCOLORCHANGE:
	case WM_SYSCOMMAND:
		result = onSysCommand(wp, GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	//case WM_SYSDEADCHAR:
	case WM_SYSKEYDOWN:
		result = onSysKeyDown(wp, lp);
		break;
	case WM_SYSKEYUP:
		result = onSysKeyUp(wp, lp);
		break;
	//case WM_TCARD:
	//case WM_THEMECHANGED:
	//case WM_TIMECHANGE:
	//case WM_TIMER:
	//case WM_UNDO:
	//case WM_USER:
	//case WM_USERCHANGED:
	//case WM_VKEYTOITEM:
	case WM_VSCROLL:
		result = onVerticalScroll(GET_WM_VSCROLL_HWND(wp,lp),
								  GET_WM_VSCROLL_CODE(wp,lp),
								  GET_WM_VSCROLL_POS(wp,lp));
		break;
	//case WM_VSCROLLCLIPBOARD:
	case WM_WINDOWPOSCHANGED:
		result = onWindowPosChanged(GET_WINDOWPOS_LPARAM(lp));
		break;
	case WM_WINDOWPOSCHANGING:
		result = onWindowPosChanging(GET_WINDOWPOS_LPARAM(lp));
		break;
	//case WM_WININICHANGE:
	//case WM_KEYFIRST:
#if _WIN32_WINNT >= 0x0501
	//case WM_KEYLAST:
	//case WM_UNICHAR:
#else
	//case WM_KEYLAST:
#endif
	case WM_SYNCPAINT:
		result = onSyncPaint();
		break;
	//case WM_MOUSEACTIVATE:
	case WM_MOUSEMOVE:
		result = onMouseMove(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_LBUTTONDOWN:
		result = onLeftButtonDown(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_LBUTTONUP:
		result = onLeftButtonUp(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_LBUTTONDBLCLK:
		result = onLeftButtonDoubleClick(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_RBUTTONDOWN:
		result = onRightButtonDown(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_RBUTTONUP:
		result = onRightButtonUp(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_RBUTTONDBLCLK:
		result = onRightButtonDoubleClick(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_MBUTTONDOWN:
		result = onMiddleButtonDown(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_MBUTTONUP:
		result = onMiddleButtonUp(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_MBUTTONDBLCLK:
		result = onMiddleButtonDoubleClick(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_MOUSEWHEEL:
		result = onMouseWheel(
			GET_WHEEL_DELTA_WPARAM(wp), GET_KEYSTATE_WPARAM(wp),
			GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	//case WM_MOUSEFIRST:
#if (_WIN32_WINNT >= 0x0500)
/*
	case WM_XBUTTONDOWN:
		result = onXButtonDown(
			GET_XBUTTON_WPARAM(wp), GET_KEYSTATE_WPARAM(wp),
			GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_XBUTTONUP:
		result = onXButtonUp(
			GET_XBUTTON_WPARAM(wp), GET_KEYSTATE_WPARAM(wp),
			GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_XBUTTONDBLCLK:
		result = onXButtonDoubleClick(
			GET_XBUTTON_WPARAM(wp), GET_KEYSTATE_WPARAM(wp),
			GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
*/
	//case WM_MOUSELAST:
#else
	//case WM_MOUSELAST:
#endif
	case WM_MOUSEHOVER:
		result = onMouseHover(
			GET_KEYSTATE_WPARAM(wp), GET_X_LPARAM(lp), GET_Y_LPARAM(lp));
		break;
	case WM_MOUSELEAVE:
		result = onMouseLeave();
		break;
#if (_WIN32_WINNT >= 0x0601)
	//case WM_TOUCHMOVE:
	//case WM_TOUCHDOWN:
	//case WM_TOUCHUP:
		;
#endif
	}

	return result;
}
