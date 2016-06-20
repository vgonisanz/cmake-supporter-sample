//============================================================================
// Name        : main.cpp
// Author      : vgonisanz
// Version     :
// Copyright   : MIT
// Description : Sample usage
//============================================================================

#include "CMSSample_config.h"						// Version Header
#define LOG_TAG	"Sample-Common"		// Crossplatform Logs
#include "logger.h"

#include "foo.h"
#include "var.h"

using namespace threemonkeybits;

// Declaration
void printWelcome();
void useFooModule();
void useVarModule();

// Main
int main()
{
	printWelcome();
	useFooModule();
	useVarModule();
	return 0;
}

// Functions
void printWelcome()
{
	LOGI("Welcome to the common sample");
	LOGI("------------------------------------------------------------------");
}

void useFooModule()
{
	LOGI("Foo module");
	LOGI("------------------------------------------------------------------");
	Foo myFoo;
	myFoo.foo(1);
}

void useVarModule()
{
	LOGI("Var module");
	LOGI("------------------------------------------------------------------");
	Var* myVar = new Var();
	myVar->foo(2);
	delete myVar;
}
