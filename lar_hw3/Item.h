#include <iostream>
#ifndef ITEM_H
#define ITEM_H
#include <string>
using std::string;
using std::cout;
using std::endl;
class Item
{
	int _price;
	string _manufacturer;
	int _id;                 //the id of the item 
	static int _itemId;      // it's a variable to save the last id
public:
	///Item();
	Item(int price, const string& manufacturer);
	virtual ~Item();
	virtual operator string()  const = 0;
	int getPrice()const;
	string getManufacturer()const;
	int getId()const;
	void setPrice(int price);
	void setManufacturer(const string& manufacturer);
	static bool itemPtrCompare(Item* first, Item* sec);

};


#endif // !ITEM_H