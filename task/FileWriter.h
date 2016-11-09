#pragma once 
#include "Device.h"
#include<ostream>

class FileWriter
{
private:
	//std::ofstream &writer;
public:
	//FileWriter();
	//~FileWriter();
	void writeInFile(Device content, short number);
	char * getFileName(short number);
};
