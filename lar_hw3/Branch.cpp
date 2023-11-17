
#include "Branch.h"
#include <iostream>
#include <typeinfo>
#include "HWExceptions.h"
//	c'tor
Branch::Branch(string location, int capacity) :_location(location), _capacity(capacity)
{
	_count = 0;
	_Catalog_value = 0;
}
//defult c'tor
Branch::Branch() : _location("~"), _capacity(0)
{
	_count = 0;
	_Catalog_value = 0;
}
//copy c'tor
Branch::Branch(const Branch& _other) :_capacity(_other._capacity), _location(_other._location)
{
	_count = 0;
	_Catalog_value = 0;
}
//D'tor
Branch::~Branch()
{
	for (int i = 0; i < _count; i++)delete _itemCatalog[i];
}
vector<Item*> Branch::getCatalog() const
{
	return _itemCatalog;
}

void Branch::setLocation(const string newLocation)
{
	_location = newLocation;
}
string Branch::getLocation() const
{
	return _location;
}


//a method to add a new item to the catalog
void Branch::addItem(Item* newItem)
{
	if (_count == _capacity) throw FullCatalogError();//if the catalog is full, we should throw exception
	else
	{
		vector<Item*>::iterator p = find(_itemCatalog.begin(), _itemCatalog.end(), newItem);//create a iterator ,and check if exist a new item we want to add
		if (p != _itemCatalog.end())throw ExistingItemError(); //if exist the same item , we throw a exception
		else
		{
			_itemCatalog.push_back(newItem);  //add the item to a catalog
			_count++;
			_Catalog_value += newItem->getPrice(); //add the price of the new item to a cataloge price
		}
	};
}
//it's print the catlog
void Branch::printCatalog()
{
	cout << "Printing KSF branch in " << this->getLocation() << endl; //print a message with the store location
	cout << "There are " << this->getcount() << " item in the catalog" << endl;
	cout << "Catalog value is: " << _Catalog_value << endl;
	for (Item* p : _itemCatalog)           // p is a iterator to the items catalog
	{
		cout << string(*p) << endl;            //print item details
	}
}
Item* Branch::removeItem(const int id)
{
	vector<Item*>::iterator p = _itemCatalog.begin();  //it's iterator to the start of the catalog
	for (; p != _itemCatalog.end(); p++)
	{
		if (*p != NULL && (*p)->getId() == id) //if we find that there are a item with the id that we get we delete it 
		{
			Item* r = *p;  //we save a pointer to a item that we want to delete 
			_count--;
			_Catalog_value -= (*p)->getPrice();
			_itemCatalog.erase(p);   //we remove the item we find from the catalog
			return r;     //return a pointer to a item we delete
		}
	}
	throw NonExistingItemError();     //we throw a exception 
}
//this is a function to compare between the id for two items
bool myfuncid(Item* item1, Item* item2)
{
	return(item1->getId() < item2->getId());
}
//Print catalog By id
void Branch::print_catalog_by_id()
{
	std::sort(_itemCatalog.begin(), _itemCatalog.end(), myfuncid);  //sort the catalog by id
	printCatalog();//print the catalog after sorting
}
bool myfuncPrice(Item* item1, Item* item2)
{
	return item1->getPrice() < item2->getPrice();
}

//Print catalog By price
void Branch::print_catalog_by_price()
{
	std::stable_sort(_itemCatalog.begin(), _itemCatalog.end(), myfuncPrice);//sort the catalog by price 
	printCatalog(); //print the catalog after sorting

}
int Branch::getcount()
{
	return _count;
}
//return the capacity of the store catalog
int Branch::getCapacity()
{
	return _capacity;
}


