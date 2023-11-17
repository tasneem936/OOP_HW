#include "Computer.h"
#include "PeripheralDevice.h"
//	c'tor
Computer::Computer(int price, const string& manufacturer, const string& cpu, bool isLaptop, int ports) :
	Item(price, manufacturer), _cpu(cpu), _is_a_laptop(isLaptop), _Usb_ports(ports) {};



//return the cpu
string Computer::getCpu() const
{
	return _cpu;
}

//return 1 if the computer is laptop , else 0
bool Computer::isALaptop() const
{
	return _is_a_laptop;
}

//edit the cpu
void Computer::setCpu(const string cpu)
{
	_cpu = cpu;
}

//edit if the computer is a laptop or no
void Computer::setIsALaptop(bool b)
{
	_is_a_laptop = b;
}
// To string convertion function
Computer::operator string() const
{
	string tmp = Item::operator std::string() + ", "; //we call a string function of the item  to get the item details
	if (_is_a_laptop)tmp = tmp + "Laptop" + ", ";   //add to the item string a details if the computer is a laptop or no 
	else tmp = tmp + "Desktop" + ", ";
	return (tmp + _cpu);   //retun the computer details like a string
}
//return the number of the usb ports
int Computer::getPorts() const
{
	return _Usb_ports;
}
//return the number of the connecting devices
int Computer::getCountOfDevises() const
{
	return _countOfDevise;
}
// print the string of each peripheral device connect to the computer
void Computer::printConnected()
{
	cout << "There are " << _countOfDevise << " connection to " << string(*this) << endl;//print the computer details
	for (const PeripheralDevice* ptr : this->connectedDevices)
	{
		cout << string(*ptr) << endl;  //print the details for all the connecting devices
	}
}

//connect a new device to the computer
void Computer::connectToComputer(const PeripheralDevice *newDevice)
{
	this->connectedDevices.push_back(newDevice);//add a new device to the vector 
	_countOfDevise++;  //increace the count of devices
}

//disconnect a device  ,and remove it from connectDevices
void Computer::deleteDevice(int id)
{
	int index = 0;
	for (const PeripheralDevice* vecDevice : this->connectedDevices)
	{
		if (vecDevice->getId() == id)
		{
			connectedDevices.erase(connectedDevices.begin() + index);
			return;
		}
		index++;
	}
}
