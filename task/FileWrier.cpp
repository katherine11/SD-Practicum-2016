#include "FileWriter.h"

/*
FileWriter::FileWriter()
{

}

FileWriter::~FileWriter()
{

}
*/

void FileWriter::writeInFile(Device content, short number)
{
	char *name = getFileName(number);

	//std::ofstream myfile;
	//this->writer >> content;
}

char * FileWriter::getFileName(short number)
{
	char *result;
	switch (number)
	{

	case 1: return result = "file1.txt";
			break;
	case 2: return result = "file2.txt";
			break;
	case 3: return result = "file3.txt";
			break;
	case 4: return result = "file4.txt";
			break;
	case 5: return result = "file5.txt";
			break;
		default: return NULL;
			break;
	}

}
