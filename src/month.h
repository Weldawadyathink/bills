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
            
        private:
            std::vector<spenser::bill> bills;
            int addBill(spenser::bill newBill);
    };
}