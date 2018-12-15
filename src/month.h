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
            int runMonth(std::string prompttext, std::string defaultSubDirectory);
            void setName(std::string newName);
            void setDirectory(std::string directory);
            
        private:
            std::string subdirectory;
            std::string monthName; // also save file
            static std::string monthFile; // save file for defaults
            void changeDefaultSaveFile();
            const static char promptsplit = '/';
            const static char promptend = '>';
            std::vector<spenser::bill> bills;
            int addBill(spenser::bill newBill);
            int save() const;
    };
}