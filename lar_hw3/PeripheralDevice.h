#pragma once
#include <iostream>
#include "Item.h"
#include "Computer.h"
#include <string>
using std::string;
using std::cout;
using std::endl;
class PeripheralDevice :public Item
{
	string _color;     //it's the color of the peripheral device
	bool _isWireless;  //if  the peripheral device is werless or no 
	int _idOfComputer; //we save the id of the computer that we connecting wuth
	Computer* connected_computer;  //save a pointer to a computer we connecting with
public:
	//	c'tor
	PeripheralDevice(int price, const string& manufacturer, const string& color, bool isWerless);
	virtual operator string() const override;
	~PeripheralDevice();
	virtual void connect(Computer computer) = 0;
	void setIsWireless(bool isWireless);
	void setColor(const string color);
	string getColor()const;
	bool getIsWireless()const;
	int getComputerId()const;
	Computer* getconnected_computer();
	void setIdOfComputer(int id);
	virtual void disconnect();

};

