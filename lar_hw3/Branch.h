#include <iostream>
#include "Item.h"
#include "Computer.h"
#include "Keyboard.h"
#include"HWExceptions.h"
#include <vector>
#ifndef BRANCH_H
#define BRANCH_H
#include <algorithm>
using std::string;
using std::vector;

class Branch
{
	vector<Item*> _itemCatalog; //a array of pointer to item in the store
	string _location;           //the location of the store
	int _count;                //the number of the item on the store
	int _Catalog_value;        // catalog values is the sum of the price of all the items on the store
	const int _capacity;       //Branch catalog capacity
public:
	//	c'tor
	Branch(string location, int capacity);
	// copy c'tor
	Branch(const Branch& other);
	//defult c'tor
	Branch();
	//D'tor
	virtual ~Branch();
	string getLocation()const;
	void setLocation(const string newLocation);
	int getCapacity();
	int getcount();
	vector<Item*> getCatalog() const;
	void addItem(Item* newItem);
	void printCatalog();
	Item* removeItem(const int id);
	//Print catalog By id
	void print_catalog_by_id();
	//Print catalog By price
	void print_catalog_by_price();
	//return a pointer of the same type to the Item from the same class with the highest price
	template<class T>
	T* giveMeFinest(T* other)
	{
		vector<Item*>::iterator p;   //this is a iterator for a item catalpg
		vector<Item*>::iterator maxPtr = _itemCatalog.end(); //this a iterator to the item with the same type of other ,and the max price item of the same type
		for (p = _itemCatalog.begin(); p != _itemCatalog.end(); p++)
		{
			if (typeid(**p) == typeid(*other))   //if we find a item in the catalog with he same type
			{
				if (maxPtr == _itemCatalog.end())maxPtr = p;  //if the maxptr is pointer to the last of a catalog we initiate it
				else
				{
					if ((*maxPtr)->getPrice() < (*p)->getPrice())maxPtr = p; //if the p is a item with the highest price, we make maxptr to point to p
				}
			}
		}
		if (maxPtr == _itemCatalog.end())throw NoneExistingItemTypeError();  //if the maxptr is pointer to the last of a catalog , that's mean that we don't find a item with the same type
		else return dynamic_cast<T*>(*maxPtr);  //if we find we should return a pointer to the item 

	}
};

#endif // !BRANCH_H