// old-style module for search ingame stuff.
// original author unknown
// partially modified and modernized by Eugene Golubev

#pragma once

#include <Windows.h>

namespace offset {
	DWORD ClientTable();
	DWORD EngineTable();
	DWORD StudioTable();
	DWORD StudioAPITable();
	DWORD UserMsgBase();
	DWORD EventBase();
	DWORD Speed();
	DWORD ButtonsBase();
	DWORD PlayerMove();
	DWORD ClientState();
	DWORD ClientStatic();
}