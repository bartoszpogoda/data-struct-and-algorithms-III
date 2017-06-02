#pragma once

#include <iostream>
#include "KSFileReader.h"
#include "TSFileReader.h"

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define ENTER 13

class CLInterface {
private:
	static KSFileReader* ksFileReader;
	static TSFileReader* tsFileReader;

	CLInterface() {};
public:
	static void enter();
	static int handleUserInput();

	static bool viewInputFilenameKS();
	static bool viewInputFilenameTS();
	static void viewMainMenu();

	static void viewExecuteKS();
	static void viewExecuteTS();
};