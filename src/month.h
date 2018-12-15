#pragma once
#include <vector>
#include "bill.h"
#include <fstream>
#include <iostream>
#include <string>

namespace spenser
{
    class month
    {
        public:
            month();
            int listBills();
            int addBill();
            int runMonth(std::string prompttext, std::string defaultSubDirectory);
            
        private:
            std::string subdirectory;
            std::string monthName;
            static std::string monthFile;
            void changeDefaultSaveFile();
            const static char promptsplit = '/';
            const static char promptend = '>';
            std::vector<spenser::bill> bills;
            int addBill(spenser::bill newBill);
    };
}