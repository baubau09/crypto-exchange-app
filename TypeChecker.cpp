#include "TypeChecker.h"

using namespace std;

TypeChecker::TypeChecker() {}

bool TypeChecker::is_number(const string& s) {
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}


bool TypeChecker::is_product(const string& s, OrderBook& orderBook) {
    vector<string> products = orderBook.getKnownProducts();
    for (int i = 0; i < products.size(); i++)
    {
        if (s == products[i]) {
            return true;
        }
    }
    return false;
}