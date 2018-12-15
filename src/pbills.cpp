#include "pbills.h"

using namespace spenser;
using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace spenser
{
    pbills::pbills()
    {
        
    }

    void pbills::runBills()
    {
        cout << "runBills working" << endl;
    }
    
    int pbills::open()
    {
        char temp = 'n';
        cout << "would you like to open " << folder << file << "? ";
        cin >> temp;
        if(temp == 'y')
        {
            fileSelect();
        }
        cout << "Opening " << folder << file << endl;
        
        filestream.open(folder + file, std::ios::in | std::ios::out);
        if (filestream.is_open())
        {
            string temp;
            filestream >> temp;
            if (filestream.eof())
            {
                cout << "File is empty. Creating data." << endl;
                filestream.seekg(0, std::ios_base::beg);
            }
        }
    }
    
    void pbills::fileSelect()
    {
        cout << "Select new folder (include final forward slash): ";
        cin >> folder;
        cout << "Select new file: ";
        cin >> file;
    }

}