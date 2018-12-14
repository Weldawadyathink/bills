#include "bill.h"
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

using namespace spenser;

namespace spenser{
    
    bill::bill()
    {
        isPaid = false;
        organization = "";
        amount = 0;
    }
    
    // string name of company
    // price is cost of bill
    // paid is wether the bill has been paid
    bill::bill(string name, int price, bool paid)
    {
        isPaid = paid;
        amount = price;
        organization = name;
    }
    
    bool bill::getPaid() const
    {
        return isPaid;
    }
    
    bool bill::setPaid(bool paid)
    {
        isPaid = paid;
        return isPaid;
    }
    
    string bill::getName() const
    {
        return organization;
    }
    
    string bill::setName(string newName)
    {
        organization = newName;
        return organization;
    }
    
    int bill::getAmount() const
    {
        return amount;
    }
    
    // returns the amount in pretty form, with $ 
    string bill::getPrettyAmount() const
    {
        string temp;
        temp = bill::moneySymbol;
        temp += std::to_string(amount / 100);
        temp += bill::decimalIndicator;
        temp += std::to_string(amount % 100);
        return temp;
    }
    
    // sets the amount of the bill
    // returns 0 if input valid
    // returns -1 if input is negative
    int bill::setAmount(int price)
    {
        if (price < 0)
        {
            cout << "ERROR: " << organization << " bill cannot be negative";
            return -1;
        }
        
        amount = price;
        return 0;
    }
    
    // ostream overload. prints the entire class in csv format
    int bill::writeToStream(std::ostream& stream) const
    {
        stream << organization << bill::separator << amount << bill::separator << isPaid << bill::separator << endl;
        return 0;
        
    }
    
    // prints the amount in $ to stream
    void bill::printAmount(std::ostream& stream) const
    {
        stream << getPrettyAmount();
    }
    
    // prints the amount in $ to cout
    void bill::printAmount() const
    {
        printAmount(std::cout);
    }
    
    // inputs data into class. data style will read from a bill class ostream operation
    int bill::readFromStream(std::istream& stream)
    {
        // name
        std::getline(stream, organization, bill::separator);
        
        // amount
        string temp;
        std::getline(stream, temp, bill::separator);
        setAmount(std::stoi(temp));
        
        // paid
        std::getline(stream, temp, bill::separator);
        setPaid(temp[0]);
        
        return 0;
    }
}