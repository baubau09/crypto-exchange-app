#include "TypeChecker.h"

using namespace std;

TypeChecker::TypeChecker() {}

bool TypeChecker::is_number(const string& s) {
    char* end = nullptr;
    double val = strtod(s.c_str(), &end);
    return end != s.c_str() && *end == '\0' && val != HUGE_VAL;
}


bool TypeChecker::is_product(const string& s, OrderBook& orderBook) {
    vector<string> products = CSVReader::tokenise(s,'/');

    if (products.size() != 2) {
        return false;
    }

    if ((products[0].length() < 3 || products[0].length() > 5) || (products[1].length() < 3 || products[1].length() > 5)) {
        return false;
    }
    
    return true;
}

bool TypeChecker::is_ask_bid(const string& s) {
    if (s == "ask" || s == "bid") {
        return true;
    }
    return false;
}

bool TypeChecker::is_min_max(const string& s) {
    if (s == "min" || s == "max") {
        return true;
    }
    return false;
}