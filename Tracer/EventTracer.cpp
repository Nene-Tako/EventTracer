#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <winevt.h>

#include "EventTracer.h";
#pragma comment(lib, "wevtapi.lib")
EventTracer::EventTracer() : pwsPath(NULL), pwsQuery(NULL), hEvent(NULL) { };
EventTracer::EventTracer(LPWSTR path) : pwsPath(path), pwsQuery(NULL), hEvent(NULL) { };

BOOL EventTracer::setPath(LPWSTR path) {
	this->pwsPath = path;
}

BOOL EventTracer::setQuery(LPWSTR query) {
	this->pwsQuery = query;
}

BOOL EventTracer::eventMonitoring(DWORD flags) {
	// Subscribe function
}

BOOL EventTracer::eventToFile(DWORD flags, const char* filename) {
	DWORD status = ERROR_SUCCESS;

	// Subscribe but write to file
	hEvent = EvtSubscribe(NULL, NULL, this->pwsPath, this->pwsQuery,
		NULL, NULL, SubscriptionCallback, EvtSubscribeStartAtOldestRecord);
	if (hEvent == NULL) {
		status = GetLastError();
		this->error_reporting(status);
		return FALSE;
	}
	else {
		// Need 
	}
}