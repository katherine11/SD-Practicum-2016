#include "InquiryProvider.h"
#include "PC.h"
#include "Laptop.h"
#include "Smartphone.h"
#include <cstdlib>
#include <iostream>
#include <cstring>

const size_t DEVICES_SIZE = 20;

InquiryProvider::InquiryProvider()
{
	this->devices = new Device[DEVICES_SIZE];
	for (size_t index = 0; index < DEVICES_SIZE; index++)
	{
		int randomNumber = rand() % 100;
		if (randomNumber <= 30)
		{
			this->devices[index] = PC();
		}
		else
		{
			if (randomNumber <= 60)
			{
				this->devices[index] = Laptop();
			}
			else
			{
				this->devices[index] = Smartphone();
			}
		}
	}
}

InquiryProvider::~InquiryProvider()
{
	delete[] this->devices;
}

Device* InquiryProvider::getDevicesBy(char type)
{
	if (correctChar(type)){

		Device *result = new Device[DEVICES_SIZE];
		int resultSize = 0;

		for (size_t index = 0; index < DEVICES_SIZE; index++)
		{
			if (this->devices[index].getType() == type)
			{
				result[resultSize++] = this->devices[index];
			}
		}

		if (resultSize != 0)
		{
			return result;
		}
		else
		{
			return NULL;
		}
	}
	else
	{
		std::cout << "Not a correct type given!";
	}

}

Device* InquiryProvider::getDevicesBy(char *brand)
{
	if (correctCharArray(brand))
	{
		Device *result = new Device[DEVICES_SIZE];
		int resultSize = 0;

		for (size_t index = 0; index < DEVICES_SIZE; index++)
		{
			if (strcmp(this->devices[index].getBrand(),brand) == 0)
			{
				result[resultSize++] = this->devices[index];
			}
		}

		if (resultSize != 0)
		{
			return result;
		}
		else
		{
			return NULL;
		}
	}
}

Device* InquiryProvider::getDevicesBy(char *brand, char *model)
{
	if (correctCharArray(brand) && correctCharArray(model))
	{
		Device *result = new Device[DEVICES_SIZE];
		int resultSize = 0;

		for (size_t index = 0; index < DEVICES_SIZE; index++)
		{
			bool condition = strcmp(this->devices[index].getBrand(), brand) == 0
				&& strcmp(this->devices[index].getModel(), model) == 0;
			
			if (condition)
			{
				result[resultSize++] = this->devices[index];
			}
		}

		if (resultSize != 0)
		{
			return result;
		}
		else
		{
			return NULL;
		}
	}
}

Device* InquiryProvider::getDevicesBy(char type, int maxPrice)
{
	if (correctChar(type) && maxPrice > 0)
	{
		Device *result = new Device[DEVICES_SIZE];
		int resultSize = 0;

		for (size_t index = 0; index < DEVICES_SIZE; index++)
		{
			bool equalType = this->devices[index].getType() == type;
			bool correctPrice = this->devices[index].getPrice() <= maxPrice;
			bool condition = equalType && correctPrice;

			if (condition)
			{
				result[resultSize++] = this->devices[index];
			}
		}

		if (resultSize != 0)
		{
			return result;
		}
		else
		{
			return NULL;
		}
	}

}

Device* InquiryProvider::getDevicesBy(char type, char *brand, int maxPrice)
{
	if (correctChar(type) && correctCharArray(brand) && maxPrice > 0)
	{
		Device *result = new Device[DEVICES_SIZE];
		int resultSize = 0;

		for (size_t index = 0; index < DEVICES_SIZE; index++)
		{
			bool equalType = this->devices[index].getType() == type;
			bool correctPrice = this->devices[index].getPrice() <= maxPrice;
			bool correctBrand = strcmp(this->devices[index].getBrand(), brand);
			bool condition = equalType && correctPrice && correctBrand;

			if (condition)
			{
				result[resultSize++] = this->devices[index];
			}
		}

		if (resultSize != 0)
		{
			return result;
		}
		else
		{
			return NULL;
		}
	}
}

bool InquiryProvider::correctChar(char type)
{
	return type == 'P' || type == 'L' || type == 'S';
}

bool InquiryProvider::correctCharArray(char *charArray)
{
	return charArray != NULL;
}


Device* InquiryProvider::returnDevices(Device *devices, bool condition)
{
	Device *result = new Device[DEVICES_SIZE];
	int resultSize = 0;

	for (size_t index = 0; index < DEVICES_SIZE; index++)
	{
		if (condition)
		{
			result[resultSize++] = this->devices[index];
		}
	}

	if (resultSize != 0)
	{
		return result;
	}
	else
	{
		return NULL;
	}
}