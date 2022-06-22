#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include "OrderBook.h"

class TypeChecker {
    public:
        TypeChecker();
        static bool is_number(const std::string& s);
        static bool is_product(const std::string& s, OrderBook& orderBook);
};