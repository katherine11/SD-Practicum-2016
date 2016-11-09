#pragma once
#include "Device.h"
#include <fstream>
#include <iostream>

class FileReader
{
private:
	//std::ifstream &baseFile;
public:
	FileReader();
	~FileReader();

	Device * read();
};


