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
    private:
        static vector<string> tokenise(string csvLine, char separator);
        static OrderBookEntry stringsToOBE(vector<string> strings);
        static OrderBookEntry stringsToOBE(string priceString, string amountString, string timestamp, string product, OrderBookType orderType);
        
};