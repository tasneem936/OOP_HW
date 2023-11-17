#pragma once
#include <string>
#include "PeripheralDevice.h"
using std::string;
using std::to_string;
using std::cout;
using std::endl;

class Mouse :public PeripheralDevice
{
	int _dpi; //the dpi of the mouse
public:

	Mouse(int price, const string& manufacturer, const string& color, bool isWerless, int dpi);
	virtual operator string() const override;
	void connect(Computer computer) override;
	void setDpi(const int dpi);
	int getDpi()const;



};



