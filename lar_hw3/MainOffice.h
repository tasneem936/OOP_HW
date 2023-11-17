

#ifndef MAINOFFICE_H
#define MAINOFFICE_H

#include <map>
#include <vector>
#include <string>
#include <algorithm>

#include "Branch.h"

using std::map;
using std::vector;
using std::string;

class MainOffice
{
private:
    map<string, Branch> branches;
    vector<string> locations; // all current keys in branches map

    MainOffice() {};
    ~MainOffice();
    MainOffice(const MainOffice& other) = delete; // should not copy
    MainOffice& operator=(const MainOffice& other) = delete; // should not assign
public:

    void addBranch(const string& location, int capacity);
    void removeBranch(const string& location);

    void printBranchesByLocation(void (*foo)(const Branch&))  ;
    void printBranchesByValue(void (*foo)(const Branch&)) ;
    //void printByValue() const;
    static MainOffice& getInstance();
    map<string, Branch>& getBranches();
    vector<string>& getLocations();
    Branch& getBranch(const string& location);
    Branch* sortBranches(vector<Branch> arr);
    Branch* findMax(vector<Branch> arr);

};

class ExistingBranchError : public std::exception
{    const char* what() const throw () override
    {
        return "Trying to add a branch with an already existing location";
    }
};

class NonExistingBranchError : public std::exception
{
    const char* what() const throw () override
    {
        return "Trying to delete a branch with an non existing location";
    }
};


#endif