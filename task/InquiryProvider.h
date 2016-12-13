#pragma once
#include "Device.h"

class InquiryProvider
{
private:
	Device *devices;

	bool correctChar(char type);
	bool correctCharArray(char *brand);
	Device* returnDevices(Device *devices, bool condition);
public:
	InquiryProvider ();
	~InquiryProvider();
	Device* getDevicesBy(char type);
	Device* getDevicesBy(char *brand);
	Device* getDevicesBy(char *brand, char *model);
	Device* getDevicesBy(char type, int maxPrice);
	Device* getDevicesBy(char type, char *brand, int maxPrice);

};

