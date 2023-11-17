#include "PeripheralDevice.h"
#include "HWExceptions.h"
#include"Keyboard.h"
#include "Computer.h"
#include"Mouse.h"

#include <typeinfo>
using namespace std;
//	c'tor
PeripheralDevice::PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWireless) :Item(price, manufacturer)
{
	_color = color;
	_isWireless = isWireless;
	_idOfComputer = 0;
	connected_computer = NULL;
}

void PeripheralDevice::connect(Computer computer)
{
	cout << " is Connecting to computer: " << string(computer) << endl; //a derived class should provide an implementation and then call this method to print the computer detalis
	if (this->getComputerId() == 0)        //if the device isn't connecting to any computer ,we connect the computer if there is a empty usb in the computer
	{
		if (computer.getPorts() > computer.getCountOfDevises())  //check that there are a empty usb in the computer
		{
			if (computer.checkSameType(*this)) //check if the computer is connecting to peripheral devices of the same type connected
			{
				throw ConnectError();    //throw a error if there are another devise with the same type is conneting 
			}
			else
			{
				computer.connectToComputer(this);   //connect the device with computer
				connected_computer = &computer;              // set the computer is connecting with the device
				_idOfComputer = computer.getId();
			}
		}
		else
			throw ConnectError();
	}
	else
	{
		if (this->getComputerId() != computer.getId()) throw ConnectError();//if we try to add a another computer that is not the same computer we is connecting with
	}
}

PeripheralDevice::operator string() const
{
	string tmp = Item::operator std::string(); //we call a string function of the item  to get the item details
	if (_isWireless)tmp = (tmp + ", Wireless"); //add to a string a details 
	else tmp = (tmp + ", Wired");
	tmp = (tmp + ", " + _color);               //add to a string a details    
	return tmp;                              //return a details of the peripheral device by string
}

PeripheralDevice::~PeripheralDevice()
{
	disconnect();
}

//it's to edit  if the peripheral device is wireless or no  
void PeripheralDevice::setIsWireless(bool isWireless)
{
	_isWireless = isWireless;
}
//the method to edit the color
void PeripheralDevice::setColor(const string color)
{
	_color = color;
}
//it's to get the color
string PeripheralDevice::getColor() const
{
	return _color;
}
//it's to return 1 if the peripheral device is wireless else return 0
bool PeripheralDevice::getIsWireless() const
{
	return _isWireless;
}
//return the id of the computer that connecting to this device
int PeripheralDevice::getComputerId() const
{
	return _idOfComputer;
}
//return the computer that connecting to this device
Computer* PeripheralDevice::getconnected_computer()
{
	return  connected_computer;
}

//set the id of the computer that connecting to this device
void PeripheralDevice::setIdOfComputer(int id)
{
	_idOfComputer = id;
}
//disconnect the computer 
void PeripheralDevice::disconnect()
{
	if (connected_computer != NULL) //if the device is connected with a computer we should delete it
	{
		connected_computer->deleteDevice(this->getId());//we disconnect the device from the computer ;
		_idOfComputer = 0;
		connected_computer = NULL;
	}
}

