#pragma once
#include <string>
#include <iostream>
#include <vector>
#include "OrderBookEntry.h"
using namespace std;

class MerkelMain {
    public:
        MerkelMain();
        void init();
    private:
        std::vector<OrderBookEntry> orders;
        void loadOrderBook();
        void printMenu();
        void printHelp();
        void printMarketStats();
        void enterOffer();
        void enterBid();
        void printWallet();
        void goToNextTimeFrame();
        int getUserOption();
        void processUserOption(int userOption);
};
