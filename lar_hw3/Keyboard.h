#pragma once
#include <string>
#include "PeripheralDevice.h"
using std::string;
using std::to_string;
using std::cout;
using std::endl;

class Keyboard :public  PeripheralDevice
{
	int _keys;
public:
	Keyboard(int price, const string& manufacturer, const string& color, bool isWerless, int keys);
	virtual operator string() const override;
	void connect(Computer computer) override;
	void setNumOfKeys(const int keys);
	int getNumOfKeys()const;
};
