#include <iostream>
#include "Item.h"
using std::string;
using std::cout;
using std::endl;
using std::to_string;

//initiate the counter of the last id 
int Item::_itemId = 0;


Item::Item(int price, const string& manufacturer) :_price(price), _manufacturer(manufacturer)
{
	_id = ++_itemId;
}
Item::~Item()
{
	cout << "Throwing away an item" << endl;
}
// To string convertion function
//we return a string with the item id, manufacturer and price with a comma between them
Item::operator string () const
{
	return ("id " + to_string(_id) + ": " + _manufacturer + " " + to_string(_price) + "$");

}
//return the price
int Item::getPrice() const
{
	return _price;
}
//return the Manufacturer
string Item::getManufacturer() const
{
	return _manufacturer;
}
//return the id 
int Item::getId() const
{
	return _id;
}
void Item::setPrice(int price)
{
	_price = price;
}
void Item::setManufacturer(const string& manufacturer)
{
	_manufacturer = manufacturer;
}
bool Item::itemPtrCompare(Item* first, Item* sec) {
	return first->getId() < sec->getId() ? true : false;
}

