#include "Device.h"
#include <cstring>

Device::Device()
{

}

Device::Device(const Device & device)
{
	copy(device);
}

Device & Device::operator=(const Device & device)
{
	if (this != &device)
	{
		destroy();
	}

	copy(device);

	return *this;
}

Device::~Device()
{
	destroy();
}

void Device::copy(const Device & device)
{
	strcpy(this->brand,device.brand);
	strcpy(this->model, device.model);
	this->price = device.price;
	this->inventoryNumber = device.inventoryNumber;
	this->type = device.type;
}

void Device::destroy()
{
	delete[] this->brand;
	delete[] this->model;
}

void Device::printCharArray(std::ostream &os, char * charArray)
{
	for (size_t index = 0; index < strlen(charArray); index++)
	{
		os << charArray[index];
	}
}

std::ostream & operator << (std::ostream &os, const Device &device)
{
	os << "Device type: ";
	os << device.type;
	os << "/nInventory: ";
	os << device.inventoryNumber;
	os << "/nBrand: ";
	for (size_t index = 0; index < strlen(device.brand); index++)
	{
		os << device.brand[index];
	}

	//printCharArray(os, device.brand);

	os << "/nModel: ";
	for (size_t index = 0; index < strlen(device.model); index++)
	{
		os << device.model[index];
	}

	//printCharArray(os, device.model);
	os << "/nPrice: ";
	os << device.price;

	return os;
}

std::istream & operator >> (std::istream &is, Device &device)
{
	std::cout << "Device type: ";
	is >> device.type;
	std::cout << "/nInventory: ";
	is >> device.inventoryNumber;
	std::cout << "/nBrand: ";

	for (size_t index = 0; index < MAX_BRAND_SIZE; index++)
	{
		is >> device.brand[index];
	}

	std::cout << "/nModel: ";

	for (size_t index = 0; index < MAX_MODEL_SIZE; index++)
	{
		is >> device.model[index];
	}

	return is;
}

char Device::getType()const
{
	return this->type;
}

const char * Device::getBrand()const
{
	return this->brand;
}

const char * Device::getModel()const
{
	return this->model;
}

double Device::getPrice()const
{
	return this->price;
}
