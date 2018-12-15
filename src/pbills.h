#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace spenser
{
    class pbills
    {
        public:
            pbills();
            void runBills();
            
        private:
            std::string pbillsFileHeader = "bills_program_data_file";
            std::string folder = "data/";
            std::string file = "pbills";
            std::fstream filestream;

            int open();
            void close();
            void fileSelect();
    };
    // Main Program
    
}