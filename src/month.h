#pragma once
#include <vector>
#include "bill.h"
#include <fstream>
#include <iostream>

namespace spenser
{
    class month
    {
        public:
            month();
            int listBills();
            int addBill();
            int runMonth(std::string prompttext);
            
        private:
            std::string monthName;
            const static char promptsplit = '/';
            const static char promptend = '>';
            std::vector<spenser::bill> bills;
            int addBill(spenser::bill newBill);
    };
}