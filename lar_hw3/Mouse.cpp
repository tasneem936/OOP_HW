#include "Mouse.h"
//	c'tor
Mouse::Mouse(int price, const string& manufacturer,  const string& color, bool isWireless, int dpi) :
	PeripheralDevice(price, manufacturer, color, isWireless), _dpi(dpi) {};

Mouse::operator string() const
{
	string tmp = PeripheralDevice::operator std::string();//we call a string function of the PeripheralDevice  to get the PeripheralDevice details
	tmp = (tmp + ", Mouse with dpi : " + to_string(_dpi)); //add to a string a dpi
	return tmp;

}
void Mouse::connect(Computer computer)
{
	cout << "Connecting a mouse" << endl;
	if (getComputerId() != computer.getId())
	{
		cout << string(*this);              
		PeripheralDevice::connect(computer); //call the method that connect a computer to a mouse
	}
}
void Mouse::setDpi(const int dpi)
{
	_dpi = dpi;
}
int Mouse::getDpi() const
{
	return _dpi;
}
