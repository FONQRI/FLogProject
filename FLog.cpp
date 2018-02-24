#include "FLog.h"
FLog::FLog() {}

//	function for saving user log in vector and database and print them
//(control by macro)
void FLog::mUserLog(std::time_t dateTime, std::string userName, int line,
			std::string function, std::string file, std::string text)
{

	// get thread id and convert it to string
	std::ostringstream sstream;
	sstream << std::this_thread::get_id();
	std::string threadIdStr = sstream.str();

	if (logLevel != FLog::none) {
		if (FLog::printUser | FLog::printAll) {
			std::string timeTemp = std::string(std::ctime(&dateTime));
			timeTemp.replace(timeTemp.size() - 1, 1, "");
			std::string temp =
			" [DateTime: " + timeTemp + " ] " +
			" [Type: User    ] " + " [Line: " +
			std::to_string(line) + " ] " + " [Function: " +
			function + " ] " + " [Thread Id: " + threadIdStr +
			" ] " + " [File: " + file + " ] " + " [User: " +
			userName + " ] " + " [MSG: " + text + " ] ";
			std::mutex locker;
			locker.lock();
			std::clog << temp << std::endl;
			locker.unlock();
		}
		FLog::userLogList.push_back(FONQRI::UserLog(
		std::string(std::ctime(&dateTime)), std::to_string(line), file,
		text, "user", userName));
		if (FLog::userLogList.size() >= FLog::userLogCounts) {
			// NOTE you can save save userLogList  to database
		}
	}
}

//	function for saving error log in vector and database and print them
//(control by macro)
void FLog::mError(const time_t dateTime, int line, std::string function,
		  std::string file, std::string text)
{

	// get thread id and convert it to string
	std::ostringstream sstream;
	sstream << std::this_thread::get_id();
	std::string threadIdStr = sstream.str();

	if (logLevel != FLog::none) {
		if (FLog::printError | FLog::printAll) {

			std::string timeTemp = std::string(std::ctime(&dateTime));
			timeTemp.replace(timeTemp.size() - 1, 1, "");
			std::string temp = " [DateTime: " + timeTemp + " ] " +
					   " [Type: Error   ] " + " [Line: " +
					   std::to_string(line) + " ] " +
					   " [Function: " + function + " ] " +
					   " [Thread Id: " + threadIdStr + " ] " +
					   " [File: " + file + " ] " + " [MSG: " +
					   text + " ] ";
			std::mutex locker;
			locker.lock();
			std::clog << temp << std::endl;
			locker.unlock();
		}
		FLog::normalLogList.push_back(
		FONQRI::Log(std::string(std::ctime(&dateTime)),
				std::to_string(line), file, text, "error"));

		if (FLog::normalLogList.size() >= FLog::logCounts) {
			// NOTE you can save save normalLogList  to database
		}
	}
}

//	function for saving warning log in vector and database and print them
//(control by macro)
void FLog::mWarning(const time_t dateTime, int line, std::string function,
			std::string file, std::string text)
{

	// get thread id and convert it to string
	std::ostringstream sstream;
	sstream << std::this_thread::get_id();
	std::string threadIdStr = sstream.str();

	if (logLevel < FLog::important) {
		if (FLog::printWarning | FLog::printAll) {
			std::string timeTemp = std::string(std::ctime(&dateTime));
			timeTemp.replace(timeTemp.size() - 1, 1, "");
			std::string temp = " [DateTime: " + timeTemp + " ] " +
					   " [Type: Warning ] " + " [Line: " +
					   std::to_string(line) + " ] " +
					   " [Function: " + function + " ] " +
					   " [Thread Id: " + threadIdStr + " ] " +
					   " [File: " + file + " ] " + " [MSG: " +
					   text + " ] ";
			std::mutex locker;
			locker.lock();
			std::clog << temp << std::endl;
			locker.unlock();
		}
		FLog::normalLogList.push_back(
		FONQRI::Log(std::string(std::ctime(&dateTime)),
				std::to_string(line), file, text, "warning"));

		if (FLog::normalLogList.size() >= FLog::logCounts) {
			// NOTE you can save save normalLogList  to database
		}
	}
}

//	function for saving info log in vector and database and print them
//(control by macro)
void FLog::mInfo(const time_t dateTime, int line, std::string function,
		 std::string file, std::string text)
{
	// get thread id and convert it to string
	std::ostringstream sstream;
	sstream << std::this_thread::get_id();
	std::string threadIdStr = sstream.str();

	if (logLevel == FLog::all) {
		if (FLog::printInfo | FLog::printAll) {
			std::string timeTemp = std::string(std::ctime(&dateTime));
			timeTemp.replace(timeTemp.size() - 1, 1, "");
			std::string temp = " [DateTime: " + timeTemp + " ] " +
					   " [Type: Info    ] " + " [Line: " +
					   std::to_string(line) + " ] " +
					   " [Function: " + function + " ] " +
					   " [Thread Id: " + threadIdStr + " ] " +
					   " [File: " + file + " ] " + " [MSG: " +
					   text + " ] ";
			std::mutex locker;
			locker.lock();
			std::clog << temp << std::endl;
			locker.unlock();
		}
		FLog::normalLogList.push_back(
		FONQRI::Log(std::string(std::ctime(&dateTime)),
				std::to_string(line), file, text, "info"));

		if (FLog::normalLogList.size() >= FLog::logCounts) {
			// NOTE you can save save normalLogList  to database
		}
	}
}

//	function for saving database log in vector and database and print them
//(control by macro)
void FLog::mDatabase(const time_t dateTime, int line, std::string function,
			 std::string file, std::string text)
{
	// get thread id and convert it to string
	std::ostringstream sstream;
	sstream << std::this_thread::get_id();
	std::string threadIdStr = sstream.str();

	if (logLevel < FLog::normal) {
		if (FLog::printDatabase | FLog::printAll) {
			std::string timeTemp = std::string(std::ctime(&dateTime));
			timeTemp.replace(timeTemp.size() - 1, 1, "");
			std::string temp = " [DateTime: " + timeTemp + " ] " +
					   " [Type: Databas ] " + " [Line: " +
					   std::to_string(line) + " ] " +
					   " [Function: " + function + " ] " +
					   " [Thread Id: " + threadIdStr + " ] " +
					   " [File: " + file + " ] " + " [MSG: " +
					   text + " ] ";
			std::mutex locker;
			locker.lock();
			std::clog << temp << std::endl;
			locker.unlock();
		}
		FLog::normalLogList.push_back(
		FONQRI::Log(std::string(std::ctime(&dateTime)),
				std::to_string(line), file, text, "database"));

		if (FLog::normalLogList.size() >= FLog::logCounts) {
			// NOTE you can save save normalLogList  to database
		}
	}
}

//	function for saving ui log in vector and database and print them
//(control by macro)
void FLog::mUi(const std::time_t dateTime, int line, std::string function,
		   std::string file, std::string text)
{
	// get thread id and convert it to string
	std::ostringstream sstream;
	sstream << std::this_thread::get_id();
	std::string threadIdStr = sstream.str();

	if (logLevel == FLog::all) {
		if (FLog::printUi | FLog::printAll) {
			std::string timeTemp = std::string(std::ctime(&dateTime));
			timeTemp.replace(timeTemp.size() - 1, 1, "");
			std::string temp = " [DateTime: " + timeTemp + " ] " +
					   " [Type: Ui      ] " + " [Line: " +
					   std::to_string(line) + " ] " +
					   " [Function: " + function + " ] " +
					   " [Thread Id: " + threadIdStr + " ] " +
					   " [File: " + file + " ] " + " [MSG: " +
					   text + " ] ";
			std::mutex locker;
			locker.lock();
			std::clog << temp << std::endl;
			locker.unlock();
		}
		FLog::normalLogList.push_back(
		FONQRI::Log(std::string(std::ctime(&dateTime)),
				std::to_string(line), file, text, "ui"));
		if (FLog::normalLogList.size() >= FLog::logCounts) {
			// NOTE you can save save normalLogList  to database
		}
	}
}

void FLog::mfree(const time_t dateTime, int line, std::string function,
		 std::string file)
{

	// get thread id and convert it to string
	std::ostringstream sstream;
	sstream << std::this_thread::get_id();
	std::string threadIdStr = sstream.str();

	if (logLevel < FLog::important) {
		if (FLog::printWarning | FLog::printAll) {
			std::string timeTemp = std::string(std::ctime(&dateTime));
			timeTemp.replace(timeTemp.size() - 1, 1, "");
			std::string temp = " [DateTime: " + timeTemp + " ] " +
					   " [Type: Warning ] " + " [Line: " +
					   std::to_string(line) + " ] " +
					   " [Function: " + function + " ] " +
					   " [Thread Id: " + threadIdStr + " ] " +
					   " [File: " + file + " ] ";
			std::mutex locker;
			locker.lock();
			std::clog << temp << std::endl;
			locker.unlock();
		}
		FLog::normalLogList.push_back(
		FONQRI::Log(std::string(std::ctime(&dateTime)),
				std::to_string(line), file, "Free ", "warning"));

		if (FLog::normalLogList.size() >= FLog::logCounts) {
			// NOTE you can save save normalLogList  to database
		}
	}
}

//	function for saving all logs database for end of program
void FLog::saveAll()
{
	// NOTE you can save save normalLogList  to database
	// NOTE you can save save userLogList  to database
}

// initializing static members
bool FLog::printInfo = false;
bool FLog::printError = false;
bool FLog::printCritical = false;
bool FLog::printUser = false;
bool FLog::printDatabase = false;
bool FLog::printUi = false;
bool FLog::printWarning = false;
bool FLog::printAll = false;
size_t FLog::userLogCounts = 1;
size_t FLog::logCounts = 1;
FLog::Level FLog::logLevel = FLog::normal;
std::vector<FONQRI::Log> FLog::normalLogList;
std::vector<FONQRI::UserLog> FLog::userLogList;
