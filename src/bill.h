#pragma once
#include <string>

namespace spenser
{
    class bill
    {
        public:
            bill();
            bill(std::string name, int price = 0, bool paid = false);
            bool getPaid() const;
            bool setPaid(bool paid);
            std::string getName() const;
            std::string setName(std::string newName);
            int getAmount() const;
            std::string getPrettyAmount() const;
            int setAmount(int price);
            int writeToStream(std::ostream& stream) const;
            void printAmount(std::ostream& stream) const;
            void printAmount() const;
            int readFromStream(std::istream& stream);
            
        private:
            const static char moneySymbol = '$';
            const static char decimalIndicator = '.';
            const static char separator = ',';
            const static int istreamSize = 10;
            std::string organization;
            bool isPaid;
            int amount;
    };
}