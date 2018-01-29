#include "FLog.h"
#include <iostream>
int main()
{
	FLog::printAll = true;
	FLog::logLevel = FLog::Level::all;
	FLogUser("first user", "Test message log");
	FLogGui("Test message log");
	FLogerror("Test message log");
	FLogdatabase("Test message log");
	FLoginfo("Test message log");
	FLogwarning("Test message log");
	return 0;
}
