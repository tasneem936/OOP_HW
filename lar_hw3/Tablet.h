#pragma once

#include "PeripheralDevice.h"
#include "Computer.h"

class Tablet :  public virtual PeripheralDevice,  virtual public Computer {
	int screenSize;
public:

	Tablet(int price, const string& manufacturer, const string& color, const string& cpu, int numOfPorts, int screenSize) :
		PeripheralDevice(price, manufacturer, color, true), Computer(price, manufacturer, cpu, false, numOfPorts), screenSize(screenSize) {}
	~Tablet(){}
	void connect(Computer c) override;
	const int getScreenSize() const;
	void setScreenSize(int screenSize);
	operator string() const;
	int getType() const { return 2; }

};


