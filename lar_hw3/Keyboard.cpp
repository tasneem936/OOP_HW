#include "Keyboard.h"
#include"HWExceptions.h"


Keyboard::Keyboard(int price,const string& manufacturer, const string& color, bool isWireless, int keys) :
	PeripheralDevice(price, manufacturer, color, isWireless), _keys(keys) {};
Keyboard::operator string() const
{
	string tmp = PeripheralDevice::operator std::string();
	tmp = (tmp + ", Keyboard with " + to_string(_keys) + " keys");
	return tmp;
}
void Keyboard::connect(Computer computer)
{
	cout << "Connecting a keyboard" << endl;//print a message
	if (getComputerId() != computer.getId())//check if the new connecting computer is already connect we do nothing
	{
		cout << string(*this); 
		PeripheralDevice::connect(computer);
	}
}
void Keyboard::setNumOfKeys(const int keys)
{
	_keys = keys;
}
int Keyboard::getNumOfKeys() const
{
	return _keys;
}