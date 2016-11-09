#pragma once
#include "PC.h"
#include "Device.h"

class Laptop : public PC
{
private:
	float screenLength; // in inches;
	short batteryLife;// in hours;

public:
	Laptop();
	Laptop(char type, int inventoryNumber, char *brand, char *model, double price, short nucleiNumber, float memory, short batteryLife, float screenLength);
	Laptop(const Laptop & laptop);
	Laptop &operator=(const Laptop &laptop);
	~Laptop();

	void copy(Laptop laptop);
	void destroy();

};


