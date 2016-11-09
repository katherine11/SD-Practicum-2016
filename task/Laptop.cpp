#include "Laptop.h"

const int MIN_HOURS_FOR_BATTERY_LIFE = 2;
const int MIN_SCREEN_LENGTH = 100;

Laptop::Laptop()
{
	Device();
	this->batteryLife = MIN_HOURS_FOR_BATTERY_LIFE;
	this->screenLength = MIN_SCREEN_LENGTH;
}

Laptop::Laptop(char type, int inventoryNumber, char *brand, char *model, double price, short nucleiNumber, float memory, short batteryLife, float screenLength)
       : PC(type, inventoryNumber, brand, model, price, nucleiNumber, memory)
{
	if (batteryLife > MIN_HOURS_FOR_BATTERY_LIFE && screenLength > MIN_SCREEN_LENGTH)
	{
		this->batteryLife = batteryLife;
		this->screenLength = screenLength;
	}
}

Laptop::Laptop(const Laptop &laptop) : PC(laptop)
{
	copy(laptop);
}

Laptop & Laptop::operator=(const Laptop &laptop)
{
	if (this != &laptop)
	{
		destroy();
	}

	Device::operator=(laptop);
	copy(laptop);

	return *this;
}

void Laptop::copy(Laptop laptop)
{
	this->screenLength = laptop.screenLength;
	this->batteryLife = laptop.batteryLife;
}

void Laptop::destroy()
{}