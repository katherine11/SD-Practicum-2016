#pragma once
#include <iostream>

const int MAX_BRAND_SIZE = 30;
const int MAX_MODEL_SIZE = 30;

class Device
{
private:
	char type; // P,L,C
	int inventoryNumber;
	char brand[MAX_BRAND_SIZE];
	char model[MAX_MODEL_SIZE];
	double price;

public:
	Device();
	Device(char type, int inventoryNumber, char *brand, char *model, double price);
	Device(const Device & device);
	Device &operator=(const Device & device);
	~Device();

	void copy(const Device & device);
	void destroy();
	void printCharArray(std::ostream &os, const char * charArray);

	friend std::ostream & operator << (std::ostream &os, const Device &device);
	friend std::istream & operator >> (std::istream &is, Device &device);

	char getType()const;
	const char *getBrand()const;
	const char *getModel()const;
	double getPrice()const;
};
