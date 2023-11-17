#include "Tablet.h"


void Tablet::connect(Computer c)
{
	string t = typeid(this).name();
	std::cout << "Connecting a " << t << " " << std::endl;
	std::cout << Tablet::operator std::string();
	PeripheralDevice::connect(c);
}

const int  Tablet::getScreenSize() const
{
	return this->screenSize;
}

void Tablet::setScreenSize(const int screenSize)
{
	this->screenSize = screenSize;
}

Tablet::operator string() const
{
	return this->Item::operator std::string() + ", " + this->getColor() + ", " + this->getCpu() + ", Tablet with screen size: "
		+ std::to_string(this->screenSize);
}
