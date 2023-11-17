#pragma once
#include <exception>
using std::exception;

class ExistingItemError : public exception
{
	virtual const char* what() const throw()
	{
		return "Trying to add an item with an id already in the catalog";
	};
};
struct FullCatalogError : public exception
{
	virtual const char* what() const throw()
	{
		return "Trying to add an item to a full catalog";
	};

};

struct NonExistingItemError : public exception
{
	virtual const char* what() const throw()
	{
		return "Trying to remove an item with a non existing id";
	};
};
class NoneExistingItemTypeError :public exception
{
	virtual const char* what() const throw()
	{
		return"Trying to get an item with a non existing type";
	};
};
class ConnectError :public exception
{
	virtual const char* what() const throw()
	{
		return "Failed connection attempt";
	};
};
