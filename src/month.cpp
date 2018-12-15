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
    
    // Interactive monthly bills program
    int month::runMonth(string prompttext, string defaultSubDirectory)
    {
        while (true){
            cout << prompttext << month::promptsplit << monthName << month::promptend << " ";
            string temp;
            cin >> temp;
            
            if (temp == "exit")
            {
                cout << "Exiting..." << endl;
                return 0;
            }
            else if (temp == "ls")
            {
                listBills();
            }
            else if (temp == "add")
            {
                addBill();
            }
            else if (temp == "help")
            {
                cout << "Help is not yet implemented. Good luck!" << endl;
            }
            //else if (temp == "default")
            //{
            //    changeDefaultSaveFile();
            //}
            else if (temp == "save")
            {
                save();
            }
            else 
            {
                cout << "No valid command recognized. Use \"help\" for more info." << endl;
            }
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
    
    // saves current month
    // returns 0 on success, -1 on file open error
    int month::save() const
    {
        fstream file ("./" + subdirectory + monthName, std::fstream::trunc | std::fstream::out);
        
        if (!file.is_open())
        {
            cout << "ERROR opening file " << subdirectory << monthName << endl;
            return -1;
        }
        
        for (int i = 0; i < bills.size(); i++)
        {
            if (bills[i].writeToStream(file) != 0)
            {
                cout << "ERROR writing bill number " << i << endl;
            }
        }
        
        cout << bills.size() << " bills written to file ./" << subdirectory << monthName << endl;
    }
    
    void month::setName(string newName)
    {
        monthName = newName;
    }
    
    void month::setDirectory(string directory)
    {
        subdirectory = directory;
    }
}