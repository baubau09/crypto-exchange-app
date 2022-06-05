#include "AppMain.h"
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

void AppMain::loadOrderBook() {

    orders.push_back(OrderBookEntry{1000,0.02,"2020/03/17 17:01:24.884492","BTC/USDT",OrderBookType::bid});
    orders.push_back(OrderBookEntry{2000,0.02,"2020/03/17 17:01:24.884492","BTC/USDT",OrderBookType::bid});
}

void AppMain::printHelp() {
    std::cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << std::endl;
}

void AppMain::printMarketStats() {
    std::cout << "Market contains: " << orders.size() << " entries." << std::endl;
}

void AppMain::enterOffer() {
    std::cout << "Mark and offer - enter the amount " << std::endl;
}

void AppMain::enterBid() {
    std::cout << "Make a bid - enter the amount" << std::endl;
}

void AppMain::printWallet() {
    std::cout << "Your wallet is empty. " << std::endl;
}
        
void AppMain::goToNextTimeFrame() {
    std::cout << "Going to next time frame. " << std::endl;
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
    loadOrderBook();
    int userOption = 0;
    do {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption);

    } while (userOption != 7);
}

