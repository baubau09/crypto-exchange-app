#include "AppMain.h"
#include "CSVReader.h"
#include <iostream>
#include <vector>

using namespace std;

AppMain::AppMain() {}

void AppMain::printMenu() {
    cout << "===========MENU===========" << endl;
    cout << "1. Print Help" << endl;
    cout << "2. Print Exchange Stats" << endl;
    cout << "3. Make an Offer" << endl;
    cout << "4. Make a bid" << endl;
    cout << "5. Print wallet" << endl;
    cout << "6. Continue" << endl;
    cout << "7. Exit" << endl;
    cout << "=========END MENU=========" << endl;
    cout << "Please input a number from 1-7" << endl;
}

void AppMain::printHelp() {
    cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << endl;
}

void AppMain::printMarketStats() {
    //cout << "Market contains: " << orders.size() << " entries." << endl;
    // unsigned int bids = 0;
    // unsigned int asks = 0;
    // for (OrderBookEntry& e : orders) {
    //     if (e.getOrderType() == OrderBookType::ask) {
    //         asks++;
    //     }
    //     if (e.getOrderType() == OrderBookType::bid) {
    //         bids++;
    //     }
    // }
    // cout << "OrderBook asks: " << asks << ", bids: " << bids << endl;

}

void AppMain::enterOffer() {
    cout << "Mark and offer - enter the amount " << endl;
}

void AppMain::enterBid() {
    cout << "Make a bid - enter the amount" << endl;
}

void AppMain::printWallet() {
    cout << "Your wallet is empty. " << endl;
}
        
void AppMain::goToNextTimeFrame() {
    cout << "Going to next time frame. " << endl;
}
 
int AppMain::getUserOption() {
    int userOption = 0;
    cin >> userOption;
    cout << "You chose: " << userOption << endl;
    return userOption;
}

void AppMain::processUserOption(int userOption) {
    switch (userOption)
    {
    case 1: // help
        printHelp();
        break;
    case 2: // exchange stats
        printMarketStats();
        break;
    case 3: // make an offer
        enterOffer();
        break;
    case 4: // make a bid
        enterBid();
        break;
    case 5: // print wallet
        printWallet();
        break;
    case 6: // Continue
        goToNextTimeFrame();
        break;
    case 7:
        cout << "Bye bye" << endl;
        break;
    default:
        cout << "Invalid choice! Please only choose from 1 - 7" << endl;
        break;
    }  
}

void AppMain::init() {
    int userOption = 0;
    do {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption);

    } while (userOption != 7);
}

