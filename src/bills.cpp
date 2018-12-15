#include "bills.h"

using namespace spenser;

namespace spenser
{
    bills::bills()
    {
        filename = "bills.txt";
        subdirectory = "data/";
    }
    
    bills::bills(std::string file)
    {
        filename = file;
    }
    
    // main entrypoint. runs interactive bills program
    int bills::runBills()
    {
        month myMonth;
        myMonth.setName("testing");
        myMonth.setDirectory(subdirectory);
        myMonth.runMonth("bills", subdirectory);
    }
    
    // checks if the defaults are OK
    void bills::checkDefaults()
    {
        
    }
}