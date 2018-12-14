#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "month.h"

namespace spenser
{
    class bills
    {
        public:
            bills();
            bills(std::string file);
            int runBills();
            
        private:
            std::string filename;
            std::vector<spenser::month> months;
            int readData();
            
    }
}