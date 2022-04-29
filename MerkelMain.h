#include <string>
#include <iostream>
using namespace std;

class MerkelMain {
    public:
        MerkelMain();
        void init();
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
