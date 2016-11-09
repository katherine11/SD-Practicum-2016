#include "Menu.h"
#include <iostream>
#include <cstring>

Menu::Menu()
{
	this->provider = InquiryProvider();
	this->writer = FileWriter();
}

Menu::~Menu(){}

void Menu::startMenu()
{
	short input;

	do{
		
		printMenuContent();
		std::cin >> input;

		switch (input)
		{
			case 0: std::cout << "Exitting";
				break;
			case 1:
				{
				  std::cout << "Enter a type for PC(P), Laptop(L) or Smartphone(S): ";
				  char type;
				  std::cin >> type;
				  
				  this->provider.getDevicesBy(type);
				}
					break;
			case 2:
				{
					  std::cout << "Enter a brand: ";
					  char brand[30];
					  std::cin.getline(brand, 30);
					  
					  this->provider.getDevicesBy(brand);
				}
					break;
			case 3:
				{
					  std::cout << "Enter brand and model: ";
					  char brand[30];
					  std::cin.getline(brand, 30);
					  
					  char model[30];
					  std::cin.getline(model, 30);
					  
					  this->provider.getDevicesBy(brand, model);
				}
					break;
			case 4:
				{
					  std::cout << "Enter type: ";
					  char type;
					  std::cin >> type;
					  
					  std::cout << "Enter price: ";
					  int price;
					  std::cin >> price;
					  
					  this->provider.getDevicesBy(type, price);
				}
					break;
			case 5:
				{
					  std::cout << "Enter type: ";
					  char type;
					  std::cin >> type;

					  std::cout << "Enter a brand: ";
					  char brand[30];
					  std::cin.getline(brand, 30);

					  std::cout << "Enter price: ";
					  int price;
					  std::cin >> price;

					  this->provider.getDevicesBy(type, brand, price);
				}
					break;
			default: std::cout << "No such command! ";
				break;
		}

	} while (input == 0);

}

void Menu::printMenuContent()
{
	std::cout << "Choose from 0 to 5 what to happen: " << std::endl;
	std::cout << "0 - For exit/n";
	std::cout << "1 - File with all devices of a given type/n";
	std::cout << "2 - File with all devices of a given brand/n";
	std::cout << "3 - File with all devices of a given brand and model/n";
	std::cout << "4 - File with all devices of a given type and max price/n";
	std::cout << "3 - File with all devices of a given type, brand and maxPrice/n";
}