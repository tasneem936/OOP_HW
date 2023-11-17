#include "MainOffice.h"


MainOffice::~MainOffice()
{
    this->branches.clear(); // destroys all branches
}

void MainOffice::addBranch(const string& location, int capacity)
{
    if (this->branches.find(location) != this->branches.end()) // branch with key already exists
    {
        throw ExistingBranchError();
    }
    // branch with key does not exist
    this->locations.push_back(location);
    this->branches.insert(make_pair(location, Branch(location,capacity)));
}
void MainOffice::removeBranch(const string& location)
{
    map<string, Branch>::iterator itr = this->branches.find(location);

    if (itr == this->branches.end()) // branch with key does not exist
    {
        throw NonExistingBranchError();
    }
    // branch with key does exist
    this->locations.erase(std::find(this->locations.begin(), this->locations.end(), location));
    this->branches.erase(itr);
}

void MainOffice::printBranchesByLocation(void (*foo)(const Branch&)) 
{
    std::cout << "There are " + std::to_string(this->branches.size()) + " KSP branches" << std::endl;

    vector<string> vec = this->locations;
    std::sort(vec.begin(), vec.end()); // sort locations

    for (string location : vec) // go over sorted locations
    {
        foo(this->branches.at(location));
    }
}

MainOffice& MainOffice::getInstance()
{
    static MainOffice mainOffice;
    return mainOffice;
}
map<string, Branch>& MainOffice::getBranches()
{
    return this->branches;
}

vector<string>& MainOffice::getLocations()
{
    return this->locations;
}

Branch& MainOffice::getBranch(const string& location)
{
    map<string, Branch>::iterator itr;
    for (itr = branches.begin(); itr != branches.end();itr++) {
        if (itr->first == location) {
            return itr->second;
        }
    }
        throw NonExistingBranchError();
}
/*
void MainOffice::printBranchesByValue(void (*foo)(Branch&))  {
    std::cout << "There are " + std::to_string(this->branches.size()) + " KSP branches" << std::endl;
    
    vector<Branch> vec;
    for (auto i : this->branches) {
        vec.push_back((i.second));
    }
    //std::sort(vec.begin(),vec.end(),Branch::compareByValue);

    for (auto v : vec) //go over the branches
    {
        foo(v);
    }
    
} 

Branch* MainOffice::findMax(vector<Branch> vec) {
    Branch* max_branch;
    int max = -1;
    for (auto v : vec) {
        if (v.calculateValue() > max) {
            max = v.calculateValue();
            max_branch = &v;
        }
    }
    return max_branch;
}
*/