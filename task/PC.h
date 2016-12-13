#pragma once
#include "Device.h"
#include <iostream>

class PC : public Device
{
private:
	short nucleiNumber;
	float memory; //RAM
public:
	PC();
	PC(char type, int inventoryNumber, char *brand, char *model, double price, short nucleiNumber, float memory);
	PC(const PC &pc);
	PC &operator=(const PC &pc);
	~PC();

	friend std::ostream & operator << (std::ostream &os, const PC &pc);
	friend std::istream & operator >> (std::istream &is, PC &pc);

	void copy(PC pc);
	void destroy();


};
