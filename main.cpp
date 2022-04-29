#include <iostream>
#include "MerkelMain.h"
#include "OrderBookEntry.h"
using namespace std;


// void printMenu() {
//     cout << "===========MENU===========" << endl;
//     cout << "1. Print Help" << endl;
//     cout << "2. Print Exchange Stats" << endl;
//     cout << "3. Make an Offer" << endl;
//     cout << "4. Make a bid" << endl;
//     cout << "5. Print wallet" << endl;
//     cout << "6. Continue" << endl;
//     cout << "7. Exit" << endl;
//     cout << "=========END MENU=========" << endl;
//     cout << "Please input a number from 1-7" << endl;
// }

// int getUserOption() {
//     int userOption = 0;
//     cin >> userOption;
//     cout << "You chose: " << userOption << endl;
//     return userOption;
// }

// void printHelp() {
//     cout << "Help - your aim is to make money" << endl;
// }

// void printMarketStats() {
//     cout << "Market looks good" << endl;
// }

// void makeOffer() {
//     cout << "Please choose which currency do you want to sell" << endl;
// }

// void makeBid() {
//     cout << "Please choose the currency you want to buy" << endl;
// }

// void printWallet() {
//     cout << "You look rich" << endl;
// }

// void goToNextTimeFrame() {
//     cout << "continueeee" << endl;
// }

// void processOption(int userOption) {
//     switch (userOption)
//     {
//     case 1: // help
//         printHelp();
//         break;
//     case 2: // exchange stats
//         printMarketStats();
//         break;
//     case 3: // make an offer
//         makeOffer();
//         break;
//     case 4: // make a bid
//         makeBid();
//         break;
//     case 5: // print wallet
//         printWallet();
//         break;
//     case 6: // Continue
//         goToNextTimeFrame();
//         break;
//     case 7:
//         cout << "Bye bye" << endl;
//         break;
//     default:
//         cout << "Invalid choice! Please only choose from 1 - 7" << endl;
//         break;
//     }
// }

int main() {
    MerkelMain app{};

    int userOption = 0;
    do {
        app.printMenu();
        userOption = app.getUserOption();
        app.processUserOption(userOption);

    } while (userOption != 7);
}
