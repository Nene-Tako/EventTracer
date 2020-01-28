#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winevt.h>
#include <Windows.h>
#include <conio.h>

#pragma comment(lib, "wevtapi.lib")
class EventTracer
{
private:
	LPWSTR pwsPath;
	LPWSTR pwsQuery;
	EVT_HANDLE hEvent;
public:
	EventTracer();
	EventTracer(LPWSTR path);
	~EventTracer();

	BOOL setPath(LPWSTR path);
	BOOL setQuery(LPWSTR query);

	BOOL eventMonitoring(DWORD flags);
	BOOL eventToFile(DWORD flags, const char* filename);
};