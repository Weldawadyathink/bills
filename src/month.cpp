#include "month.h"

using namespace spenser;
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;

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
            cout << i << ": " << bills[i].getName() << "-" << bills[i].getPrettyAmount() << " " << (bills[i].getPaid() ? "Paid" : "*Not Paid*") << endl;
        }
    }
    
    // interactively add a new bill
    int month::addBill()
    {
        string newName;
        int price;
        
        cout << "What is the name of the bill?" << endl;
        cin >> newName;
        
        cout << "How much is it for? (in cents)" << endl;
        cin >> price;
        
        bill temp (newName, price);
        temp.printAmount();
        cout << endl;
        
        addBill(temp);
    }
}