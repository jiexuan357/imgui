// requires:
// defining IMGUI_INCLUDE_IMGUI_USER_H and IMGUI_INCLUDE_IMGUI_USER_INL
// at the project level

#pragma once
#ifndef IMGUI_USER_ADDONS_H_
#define IMGUI_USER_ADDONS_H_

#ifndef IMGUI_FORCE_INLINE
#	ifdef _MSC_VER
#		define IMGUI_FORCE_INLINE __forceinline
#	elif (defined(__clang__) || defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__))
#		define IMGUI_FORCE_INLINE inline __attribute__((__always_inline__))
#	else
#		define IMGUI_FORCE_INLINE inline
#	endif
#endif//IMGUI_FORCE_INLINE

#ifndef IMGUI_NO_INLINE
#	ifdef _MSC_VER
#		define IMGUI_NO_INLINE __declspec((noinline))
#	elif (defined(__clang__) || defined(__GNUC__) || defined(__MINGW32__) || defined(__MINGW64__))
#		define IMGUI_NO_INLINE __attribute__((__noinline__))
#	else
#		define IMGUI_NO_INLINE
#	endif
#endif//IMGUI_NO_INLINE

// Defining a custom placement new() with a dummy parameter allows us to bypass including <new> which on some platforms complains when user has disabled exceptions.
#ifndef IMIMPL_PLACEMENT_NEW
struct ImImplPlacementNewDummy {};
inline void* operator new(size_t, ImImplPlacementNewDummy, void* ptr) { return ptr; }
inline void operator delete(void*, ImImplPlacementNewDummy, void*) {}
#define IMIMPL_PLACEMENT_NEW(_PTR)  new(ImImplPlacementNewDummy() ,_PTR)
#endif //IMIMPL_PLACEMENT_NEW

#ifdef IMGUI_USE_MINIZIP	// requires linking to library -lZlib
#   ifndef IMGUI_USE_ZLIB
#   define IMGUI_USE_ZLIB	// requires linking to library -lZlib
#   endif //IMGUI_USE_ZLIB
#endif //IMGUI_USE_MINIZIP

#ifdef __EMSCRIPTEN__
#   ifndef NO_IMGUIEMSCRIPTEN
#       include "./imguiemscripten/imguiemscripten.h"
#   endif //NO_IMGUIEMSCRIPTEN
#else //__EMSCRIPTEN__
#   undef NO_IMGUIEMSCRIPTEN
#   define NO_IMGUIEMSCRIPTEN
#endif //__EMSCRIPTEN__

#ifndef NO_IMGUISTRING
#include "./imguistring/imguistring.h"
#endif //NO_IMGUISTRING
#ifndef NO_IMGUIHELPER
#include "./imguihelper/imguihelper.h"
#endif //NO_IMGUIHELPER
#ifndef NO_IMGUITABWINDOW
#include "./imguitabwindow/imguitabwindow.h"
#endif //NO_IMGUITABWINDOW

#undef IMGUI_USE_AUTO_BINDING
#if (defined(IMGUI_USE_GLUT_BINDING) || defined(IMGUI_USE_SDL2_BINDING) || defined(IMGUI_USE_GLFW_BINDING) || defined(IMGUI_USE_WINAPI_BINDING))
#	define IMGUI_USE_AUTO_BINDING
# 	include "./imguibindings/imguibindings.h"
#endif //IMGUI_USE_AUTO_BINDING

#ifndef NO_IMGUILISTVIEW
#include "./imguilistview/imguilistview.h"
#endif //NO_IMGUILISTVIEW
#ifndef NO_IMGUIFILESYSTEM
#include "./imguifilesystem/imguifilesystem.h"
#endif //NO_IMGUIFILESYSTEM
#ifndef NO_IMGUITOOLBAR
#include "./imguitoolbar/imguitoolbar.h"
#endif //NO_IMGUITOOLBAR
#ifndef NO_IMGUIPANELMANAGER
#include "./imguipanelmanager/imguipanelmanager.h"
#endif //NO_IMGUIPANELMANAGER
#ifndef NO_IMGUIVARIOUSCONTROLS
#include "./imguivariouscontrols/imguivariouscontrols.h"
#endif //NO_IMGUIVARIOUSCONTROLS
#ifndef NO_IMGUISTYLESERIALIZER
#include "./imguistyleserializer/imguistyleserializer.h"
#endif //NO_IMGUISTYLESERIALIZER
#ifndef NO_IMGUIDATECHOOSER
#include "./imguidatechooser/imguidatechooser.h"
#endif //NO_IMGUIDATECHOOSER
#ifndef NO_IMGUICODEEDITOR
#include "./imguicodeeditor/imguicodeeditor.h"
#endif //NO_IMGUICODEEDITOR
#ifdef IMGUISCINTILLA_ACTIVATED
#include "./imguiscintilla/imguiscintilla.h"
#endif //IMGUISCINTILLA_ACTIVATED
#ifndef NO_IMGUIGRAPHEDITOR
#include "./imguinodegrapheditor/imguinodegrapheditor.h"
#endif //NO_IMGUIGRAPHEDITOR

#ifdef YES_IMGUIADDONS_ALL
#	ifndef NO_IMGUIPDFVIEWER
#		undef YES_IMGUIPDFVIEWER
#		define YES_IMGUIPDFVIEWER
#	endif //NO_IMGUIPDFVIEWER
#endif //YES_IMGUIADDONS_ALL

#ifdef YES_IMGUIPDFVIEWER
#include "./imguiyesaddons/imguipdfviewer.h"
#endif //YES_IMGUIPDFVIEWER

#endif //IMGUI_USER_ADDONS_H_

