#pragma once
#include "Device.h"

class Smartphone : public Device
{
private:
	float frontCameraResolution;//in MP - 0.0 if there is not a front camera
	float backCameraResolution;// in MP;
	short numberOfSims;

	void copy(Smartphone &smartphone);
	void destroy();
public:
	Smartphone();
	Smartphone(char type, int inventoryNumber, char *brand, char *model, double price, float frontCameraRes, float backCameraRes, short numberOfSims);
	Smartphone(const Smartphone &smartphone);
	Smartphone & operator=(const Smartphone &smartphone);
	~Smartphone();
};
