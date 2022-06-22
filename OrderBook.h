#pragma once
#include <iostream>
#include "OrderBookEntry.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class OrderBook {
    public:
        OrderBook(string fileName); // construct, reading a csv data file
        vector<string> getKnownProducts(); // return vector of all known products in the dataset
        vector<OrderBookEntry> getOrders(OrderBookType type, string product, string timestamp); // return vector of Orders according to the sent filters
        static double getHighPrice(vector<OrderBookEntry>& orders);
        static double getLowPrice(vector<OrderBookEntry>& orders);
    private:
        vector<OrderBookEntry> orders;
};