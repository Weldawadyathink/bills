#include "bills.h"

using namespace spenser;

namespace spenser
{
    bills::bills()
    {
        filename = "bills.txt";
    }
    
    bills::bills(std::string file)
    {
        filename = file;
    }
    
    // main entrypoint. runs interactive bills program
    int bills::runBills()
    {
        month myMonth;
        myMonth.runMonth("bills");
    }
}