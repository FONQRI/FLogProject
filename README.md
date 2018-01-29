# FLogProject
This is a lightweight cross-platform logger library for C++ based on Standard Template Library.

## Getting Started

These instructions will get you a copy of the project up and running basically this is a simple example of usage of library .

### Prerequisites

* nothing

### Installing

You only need to copy "FLog.cpp" and "FLog.h" in you project directory and include it .

## Examples 
```c++

#include "FLog.h"
#include <iostream>
  
int main()
{
	// set print level to top ( print all logs )
	FLog::printAll = true;
  
	// set log level to top ( log every thing )
	FLog::logLevel = FLog::Level::all;

	// using APIs
	FLogUser("first user", "Test message log");
	FLogGui("Test message log");
	FLogerror("Test message log");
	FLogdatabase("Test message log");
	FLoginfo("Test message log");
	FLogwarning("Test message log");

	return 0;
}

```

![Screenshot](https://github.com/FONQRI/FLogProject/blob/master/img/Usage.png "Screenshot of usage log")


## Using
You can set these static variables and use library like above :
>
```c++
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
```
## Deployment

I will add more options to this library but my first priority is keeping this library as simple as possible .

## Built With

* c++

## Commenting

I use [doxygen documentation style](http://doxygen.nl/manual.html) for documenting and I specify priority of TODOs with P[0-3] . e.g :

```c++
// TODO P[0] Fix Most important bug 
// TODO P[1] add important API
// TODO P[2] add an exciting feature 
```

## Versioning

I increase main number when I have a big change in API and sub number for inside changes . 

## Authors

* **Behnam Sabaghi** - *Initial work* - [FONQRI](https://github.com/FONQRI)


## License

This project is licensed under the MIT License - see the [Licence](LICENSE) file for details

## Acknowledgments

* [Modern Cpp](http://moderncpp.ir/) website 

