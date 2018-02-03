#ifndef FLog_H
#define FLog_H
#include <ctime>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
// macro API
#define FLogUser(user, message)                                                \
	FLog::mUserLog(std::chrono::system_clock::to_time_t(                       \
			   std::chrono::system_clock::now()),                      \
		   user, __LINE__, __FILE__, message)

#define FLogerror(message)                                                     \
	FLog::mError(std::chrono::system_clock::to_time_t(                         \
			 std::chrono::system_clock::now()),                        \
		 __LINE__, __FILE__, message)

#define FLoginfo(message)                                                      \
	FLog::mInfo(std::chrono::system_clock::to_time_t(                          \
			std::chrono::system_clock::now()),                         \
		__LINE__, __FILE__, message)

#define FLogdatabase(message)                                                  \
	FLog::mDatabase(std::chrono::system_clock::to_time_t(                      \
			std::chrono::system_clock::now()),                     \
			__LINE__, __FILE__, message)

#define FLogGui(message)                                                       \
	FLog::mUi(std::chrono::system_clock::to_time_t(                            \
		  std::chrono::system_clock::now()),                           \
		  __LINE__, __FILE__, message)

#define FLogwarning(message)                                                   \
	FLog::mWarning(std::chrono::system_clock::to_time_t(                       \
			   std::chrono::system_clock::now()),                      \
		   __LINE__, __FILE__, message)

// struct normal log info
namespace FONQRI {
struct Log {
  public:
	Log(std::string dateTime, std::string line, std::string file,
	std::string text, std::string type)
	: dateTime(dateTime), line(line), file(file), text(text), type(type)
	{
	}

	std::string dateTime;
	std::string line;
	std::string file;
	std::string text;
	std::string type;
};

// struct user log info
struct UserLog {
  public:
	UserLog(std::string dateTime, std::string line, std::string file,
		std::string text, std::string type, std::string user)
	: dateTime(dateTime), line(line), file(file), text(text), type(type),
	  user(user)
	{
	}

	std::string dateTime;
	std::string line;
	std::string file;
	std::string text;
	std::string type;
	std::string user;
};
}
class FLog {

  public:
	// enum for logging level
	enum Level { all, normal, important, none };

	// print info log if its true
	static bool printInfo;

	// print Error log if its true
	static bool printError;

	// print Critical log if its true
	static bool printCritical;

	// print Warning log if its true
	static bool printWarning;

	// print user log if its true
	static bool printUser;

	// print database log if its true
	static bool printDatabase;

	// print ui log if its true
	static bool printUi;

	// print all logs if its true
	static bool printAll;

	// couts to write user Log in database
	static size_t userLogCounts;

	// couts to write Log in database
	static size_t logCounts;

	// log level
	static Level logLevel;

	// container of normal log to write in database
	static std::vector<FONQRI::Log> normalLogList;

	// container of user log to write in database
	static std::vector<FONQRI::UserLog> userLogList;

	/**
	function for saving user log in vector and database and print them
(control by macro)

	@param dateTime date and time of log
	@param userName user name
	@param line line of log
	@param file file of log
	@param text log message
	*/
	static void mUserLog(std::time_t dateTime, std::string userName, int line,
			 std::string file, std::string text);

	/**
	function for saving error log in vector and database and print them
(control by macro)

	@param dateTime date and time of log
	@param line line of log
	@param file file of log
	@param text log message
	*/
	static void mError(const time_t dateTime, int line, std::string file,
			   std::string text);

	/**
	function for saving warning log in vector and database and print them
(control by macro)

	@param dateTime date and time of log
	@param line line of log
	@param file file of log
	@param text log message
	*/
	static void mWarning(const time_t dateTime, int line, std::string file,
			 std::string text);

	/**
	function for saving info log in vector and database and print them
(control by macro)

	@param dateTime date and time of log
	@param line line of log
	@param file file of log
	@param text log message
	*/
	static void mInfo(const time_t dateTime, int line, std::string file,
			  std::string text);

	/**
	function for saving log in vector and database and print them (control
by macro)

	@param dateTime date and time of log
	@param line line of log
	@param file file of log
	@param text log message
	*/
	static void mDatabase(const time_t dateTime, int line, std::string file,
			  std::string text);

	/**
	function for saving database log in vector and database and print them
(control by macro)

	@param dateTime date and time of log
	@param line line of log
	@param file file of log
	@param text log message
	*/
	static void mUi(const time_t dateTime, int line, std::string file,
			std::string text);

	/**
	 * @brief for saving all logs database for end of program

	 */
	static void saveAll();

  private:
	FLog();
};

#endif // FLog_H
