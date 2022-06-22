#pragma once

#include "OrderBookEntry.h"
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class CSVReader {
    public:
        CSVReader();
        static vector<OrderBookEntry> readCSV(string csvFile);
        static vector<string> tokenise(string csvLine, char separator);
        static OrderBookEntry stringsToOBE(string priceString, string amountString, string timestamp, string product, OrderBookType orderType);
        
    private:
        static OrderBookEntry stringsToOBE(vector<string> strings);
        
};