#include "PC.h"

const int MIN_MEMORY_SIZE = 100;
const int MIN_NUCLEI_SIZE = 1;

PC::PC()
{
	Device();
	this->nucleiNumber = MIN_NUCLEI_SIZE;
	this->memory = MIN_MEMORY_SIZE;
}

PC::PC(char type, int inventoryNumber, char *brand, char *model, double price, short nucleiNumber, float memory) 
			: Device(type, inventoryNumber, brand, model, price)
{
	if (nucleiNumber > MIN_NUCLEI_SIZE && memory > MIN_MEMORY_SIZE){
		this->nucleiNumber = nucleiNumber;
		this->memory = memory;
	}
}

PC::PC(const PC &pc) : Device(pc)
{
	copy(pc);
}

PC & PC::operator=(const PC &pc)
{
	if (this != &pc)
	{
		destroy();
	}

	Device::operator=(pc);
	copy(pc);

	return *this;
}

std::ostream & operator << (std::ostream &os, const PC &pc)
{
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


void PC::copy(PC pc)
{
	this->nucleiNumber = pc.nucleiNumber;
	this->memory = pc.memory;
}

void PC::destroy()
{
	Device::destroy();
}