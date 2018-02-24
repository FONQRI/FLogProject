#include "FLog.h"
#include <iostream>
#include <thread>
int main()
{
	// set print level to top ( print all logs )
	FLog::printAll = true;

	// set log level to top ( log every thing )
	FLog::logLevel = FLog::Level::all;
	std::thread([]() {
	FLogUser("first user", "Test message log");

	}).join();

	// using APIs
	FLogUser("first user", "Test message log");
	FLogGui("Test message log");
	FLogerror("Test message log");
	FLogdatabase("Test message log");
	FLoginfo("Test message log");
	FLogwarning("Test message log");
	FLogFree();

	return 0;
}
