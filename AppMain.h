#pragma once
#include <string>
#include <iostream>
#include <ios>
#include <limits>
#include <cmath>
#include <algorithm>
#include <vector>
#include "OrderBookEntry.h"
#include "OrderBook.h"
#include "TypeChecker.h"
#include "Wallet.h"
using namespace std;

class AppMain {
    public:
        AppMain();
        void init();
    private:
        OrderBook orderBook{"20200317.csv"};
        Wallet wallet;
        string currentTime;
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
