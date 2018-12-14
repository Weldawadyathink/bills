#include <iostream>
#include "month.h"
#include <sqlite3.h>

using namespace std;
using namespace spenser;

int main()
{
    std::cout << "Hello World" << std::endl;
    
    month myMonth;
    myMonth.addBill();
}