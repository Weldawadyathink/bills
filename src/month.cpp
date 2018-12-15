#include "month.h"

using namespace spenser;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;
using std::fstream;

namespace spenser
{
    month::month()
    {
    }
    
    // adds bill to end of vector. returns the index of the new bill
    int month::addBill(bill newBill)
    {
        bills.push_back(newBill);
        return bills.size() - 1;
    }
    
    // prints out all bills
    int month::listBills()
    {
        for(int i = 0; i < bills.size(); i++)
        {
            cout << i << ": " << bills[i].getName() << " " << bills[i].getPrettyAmount() << " " << (bills[i].getPaid() ? "Paid" : "*Not Paid*") << endl;
        }
    }
        

    
    // changes the default save file
    /*void month::changeDefaultSaveFile()
    {
        cout << "Enter a new default save file" << endl;
        string temp;
        cout << monthFile << ">";
        cin >> temp;
        
        if (temp != "")
        {
            monthFile = temp;
        }
        cout << monthFile << endl;
    }*/
    

    
    void month::setName(string newName)
    {
        monthName = newName;
    }
    
    string month::getName() const
    {
        return monthName;
    }
}