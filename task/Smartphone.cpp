#include "Smartphone.h"

const int MIN_FRONT_CAM_RES = 2;
const int MIN_BACK_CAM_RES = 0.5;
const int MIN_NUMBER_OF_SIMS = 1;

Smartphone::Smartphone()
{
	Device();
	this->frontCameraResolution = MIN_FRONT_CAM_RES;
	this->backCameraResolution = MIN_BACK_CAM_RES;
	this->numberOfSims = MIN_NUMBER_OF_SIMS;
}

Smartphone::Smartphone(char type, int inventoryNumber, char *brand, char *model, double price, float frontCameraRes, float backCameraRes, short numberOfSims)
: Device(type, inventoryNumber, brand, model, price)
{
	if (frontCameraRes > MIN_BACK_CAM_RES && backCameraRes > MIN_BACK_CAM_RES && numberOfSims > MIN_NUMBER_OF_SIMS)
	{
		this->frontCameraResolution = frontCameraRes;
		this->backCameraResolution = backCameraRes;
		this->numberOfSims = numberOfSims;
	}
}

Smartphone::Smartphone(const Smartphone &smartphone) : Device(smartphone)
{
	//copy(smartphone);
}

Smartphone & Smartphone::operator=(const Smartphone &smartphone)
{
	if (this != &smartphone)
	{
		destroy();
	}

	Device::operator=(smartphone);
	//copy(smartphone);

	return *this;
}

void Smartphone::copy(Smartphone &smartphone)
{
	Device::copy(smartphone);
	this->frontCameraResolution = smartphone.frontCameraResolution;
	this->backCameraResolution = smartphone.backCameraResolution;
	this->numberOfSims = smartphone.numberOfSims;
}

void Smartphone::destroy()
{
	Device::destroy();
}

Smartphone::~Smartphone()
{
	destroy();
}