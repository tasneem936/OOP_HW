#include <iostream>
#include "Computer.h"
#include "Mouse.h"
#include "Keyboard.h"
#include "Branch.h"
#include "Tablet.h"
#include <vector>
#include <algorithm>
#include "MainOffice.h"
#include <string>
#include "HWExceptions.h"
// not all includes are a "must"

#define TEST_MAIN_SIZE 6
void print_branch_catalog(const Branch& branch)
{
	std::vector<Item*> catalog = branch.getCatalog();
	std::cout << "Printing KSF Branch in " << branch.getLocation() << std::endl;
	//sort by id, you need to implement comparator
	std::sort(catalog.begin(), catalog.end(), Item::itemPtrCompare);
	std::cout << "There are " << catalog.size() << " items in the catalog: " << std::endl;
	for (int i = 0; i < catalog.size(); i++)
	{
		std::cout << static_cast<std::string>(*(catalog[i])) << std::endl;
	}
}

int main()
{
	//freopen("main_output.txt", "w", stdout);


	MainOffice& mo = MainOffice::getInstance();
	try
	{
		//this is try-catch block #1
		mo.addBranch("Haifa", TEST_MAIN_SIZE);
		mo.addBranch("Tel-Aviv", TEST_MAIN_SIZE);
		mo.addBranch("Jerusalem", TEST_MAIN_SIZE);
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #1" << std::endl;
		std::cout << e.what() << std::endl;
		return 1;
	}
	Branch* haifaBranch = NULL;
	Branch* telAvivBranch = NULL;
	Branch* jerusalemBranch = NULL;

	try
	{
		haifaBranch = &mo.getBranch("Haifa");
		telAvivBranch = &mo.getBranch("Tel-Aviv");
		jerusalemBranch = &mo.getBranch("Jerusalem");
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #2" << std::endl;
		std::cout << e.what() << std::endl;
		return 1;
	}

	if (!haifaBranch || !telAvivBranch || !jerusalemBranch)
	{
		// This if should not run, only for safety check
		std::cout << "Error with branch retrieval, shutting down." << std::endl;
		return 1;
	}

	Computer* computers[TEST_MAIN_SIZE];
	Mouse* mouses[TEST_MAIN_SIZE];
	Keyboard* keyboards[TEST_MAIN_SIZE];

	for (int i = 0; i < TEST_MAIN_SIZE; i++)
	{
		computers[i] = new Computer(100 * (i)+10, "Manufacturer" + std::to_string(i), ((i % 2) ? "Red" : "Blue"), i % 2, i + 3);
		mouses[i] = new Mouse(10 * i + 1, "Manufacturer" + std::to_string(i + 1), ((i % 2) ? "Green" : "Silver"), (i + 1) % 2, 50 * (i + 1));
		keyboards[i] = new Keyboard(20 * i + 5, "Manufacturer" + std::to_string(i + 1), ((i % 2) ? "Orange" : "Gold"), i % 2, 20 + i);
	}
	for (int i = 0; i < TEST_MAIN_SIZE - 1; i++)
	{
		Branch* branchPtr = NULL;
		switch (i % 3)
		{
		case 0:
		{
			branchPtr = haifaBranch;
			break;
		}
		case 1:
		{
			branchPtr = telAvivBranch;
			break;

		}
		case 2:
		{
			branchPtr = jerusalemBranch;
			break;
		}

		}
		try
		{
			branchPtr->addItem(computers[i]);
			branchPtr->addItem(mouses[i]);
			branchPtr->addItem(keyboards[i]);
		}
		catch (std::exception& e)
		{
			std::cout << "try-catch block #3" << std::endl;
			std::cout << e.what() << std::endl;
		}
	}
	print_branch_catalog(*haifaBranch);
	std::cout << std::endl;
	try
	{
		haifaBranch->addItem(computers[TEST_MAIN_SIZE - 1]);
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #4" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		haifaBranch->removeItem(computers[TEST_MAIN_SIZE - 1]->getId());
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #5" << std::endl;
		std::cout << e.what() << std::endl;
	}
	//////////////////////////////////////////////////////////////////////
	try
	{
		Item* removedItem = jerusalemBranch->removeItem(7);
		delete removedItem;
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #6" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		Computer* bestComputer = jerusalemBranch->giveMeFinest(computers[0]);
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #7" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Computer* computer = haifaBranch->giveMeFinest(computers[0]);
		std::cout << "Best computer in haifa: " << std::endl;
		std::cout << static_cast<std::string>(*computer) << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #8" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		keyboards[0]->connect(*(computers[0]));
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #9" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		mouses[0]->connect(*(computers[0]));
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #10" << std::endl;
		std::cout << e.what() << std::endl;
	}
	try
	{
		keyboards[1]->connect(*(computers[0]));
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #11" << std::endl;
		std::cout << e.what() << std::endl;
	}
	keyboards[0]->disconnect();
	try
	{
		keyboards[1]->connect(*(computers[0]));
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #12" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	computers[0]->printConnected();
	Keyboard* bestKeyboard = NULL;
	Computer* bestComputer = NULL;
	try
	{
		bestKeyboard = telAvivBranch->giveMeFinest(keyboards[1]);
		bestComputer = telAvivBranch->giveMeFinest(computers[1]);
		if (bestKeyboard && bestComputer)
			bestKeyboard->connect(*bestComputer);
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #13" << std::endl;
		std::cout << e.what() << std::endl;
	}
	if (bestComputer) bestComputer->printConnected();
	try
	{
		if (bestKeyboard)
		{
			telAvivBranch->removeItem(bestKeyboard->getId());
			delete bestKeyboard;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #14" << std::endl;
		std::cout << e.what() << std::endl;
	}
	if (bestComputer) bestComputer->printConnected();
	std::cout << std::endl;
	Tablet* tablet = new Tablet(150, "Manufacturer007", "Cream", "CPU", 1, 14);
	try
	{
		//jerusalemBranch->addItem(tablet);
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #15" << std::endl;
		std::cout << e.what() << std::endl;
	}
	
	std::cout << "New tablet: \n" << static_cast<std::string>(*tablet) << std::endl << std::endl;
	mo.printBranchesByLocation(&print_branch_catalog);
	std::cout << std::endl;
	//mo.printBranchesByValue(&print_branch_catalog);
	std::cout << std::endl;
	try
	{
		mo.removeBranch("Jerusalem");
	}
	catch (std::exception& e)
	{
		std::cout << "try-catch block #16" << std::endl;
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	//mo.printBranchesByValue(&print_branch_catalog);
	std::cout << std::endl;
	delete computers[TEST_MAIN_SIZE - 1];
	delete keyboards[TEST_MAIN_SIZE - 1];
	delete mouses[TEST_MAIN_SIZE - 1];
	std::cout << "\n#####End of main#####\n" << std::endl; 
	return 0;
}