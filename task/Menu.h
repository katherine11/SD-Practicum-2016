#pragma once
#include "InquiryProvider.h"
#include "FileWriter.h"
#include "FileReader.h"

class Menu
{
private:
	InquiryProvider provider;
	FileWriter writer;
	FileReader reader;
public:
	Menu();
	~Menu();
	void startMenu();
	void printMenuContent();
};
