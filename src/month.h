#pragma once
#include <vector>
#include "bill.h"
#include <fstream>
#include <iostream>
#include <string>
#include <fstream>

namespace spenser
{
    class month
    {
        public:
            month();
            int listBills();
            int addBill();
            std::string getName() const;
            void setName(std::string newName);
            int addBill(spenser::bill newBill);
            
        private:
            std::string monthName;
            std::vector<spenser::bill> bills;
    };
}