#pragma once 
#include <iostream>
#include "Item.h"
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;


class Computer :public Item
{
	string _cpu; //the cpu of the computer 
	bool _is_a_laptop; //if the computer is laptop or no 
	const int _Usb_ports;
	int _countOfDevise;
	vector <const PeripheralDevice*> connectedDevices;
public:
	//	c'tor
	Computer(int price, const string& manufacturer, const string& cpu, bool is_a_laptop, int usb);
	string getCpu()const;
	bool isALaptop()const;
	void setCpu(const string cpu);
	void setIsALaptop(bool b);
	virtual operator string() const;
	void printConnected();
	int getPorts()const;
	int getCountOfDevises()const;
	void connectToComputer(const PeripheralDevice* newDevice);
	void deleteDevice(int id);
	template<class T>
	bool checkSameType(T& other)
	{
		vector<PeripheralDevice*>::iterator it;
		for (it = connectDevices.begin(); it != connectDevices.end(); it++)
		{
			if (typeid(**it) == typeid(other)) //if there are a another item with the same type of other we should return 1 else return 0 
			{
				return 1;
			}
		}
		return 0;

	}
};

