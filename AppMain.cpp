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
    cout << "Current time is: " << currentTime << endl;
    cout << "=========END MENU=========" << endl;
    cout << "Please input a number from 1-7" << endl;
}

void AppMain::printHelp() {
    cout << "Help - your aim is to make money. Analyse the market and make bids and offers. " << endl;
}

void AppMain::printMarketStats() {
    for (string p : orderBook.getKnownProducts()) {
        cout << "Product: " << p << endl;
        vector<OrderBookEntry> entries = orderBook.getOrders(OrderBookType::ask, p, currentTime);
        vector<OrderBookEntry> entriesBid = orderBook.getOrders(OrderBookType::bid, p, currentTime);

        cout << "Asks seen: " << entries.size() << endl;
        cout << "Min ask price: " << orderBook.getHighPrice(entries) << endl;
        cout << "Max ask price: " << orderBook.getLowPrice(entries) << endl;
        cout << "Bids seen: " << entriesBid.size() << endl;
        cout << "Min bid price: " << orderBook.getHighPrice(entriesBid) << endl;
        cout << "Max bid price: " << orderBook.getLowPrice(entriesBid) << endl;
        cout << "--" << endl;
    }
   
}

void AppMain::enterOffer() {
    cout << "Make an ask - enter the amount: product,price,amount. E.g: ETH/BTC,200,0.5" << endl;
    
    string input;
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, input);

    vector<string> tokens = CSVReader::tokenise(input, ',');

    if (tokens.size() != 3) {
        cout << "Bad input! " << input << endl;
    } else if ((!TypeChecker::is_number(tokens[1])) || (!TypeChecker::is_number(tokens[2])) || (!TypeChecker::is_product(tokens[0], orderBook))) {

        // check if price or amount is a valid double
        if (!TypeChecker::is_number(tokens[1])) {
            cout << "Invalid price " << tokens[1] << endl;
        }
        if (!TypeChecker::is_number(tokens[2])) {
            cout << "Invalid amount " << tokens[2] << endl;
        }

        // check if product is correct input
        if (!TypeChecker::is_product(tokens[0], orderBook)) {
            cout << "Invalid product " << tokens[0] << endl;
        }
    } else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::ask
            );
            orderBook.insertOrder(obe);
        } catch (exception& e) {
            cout << "Bad OrderBookEntry input" << endl;
        }
    }
    
    cout << "You typed: " << input << endl;

}

void AppMain::enterBid() {
    cout << "Make a bid - enter the amount: product,price,amount. E.g: ETH/BTC,200,0.5" << endl;

    string input;
    getline(cin, input);

    vector<string> tokens = CSVReader::tokenise(input, ',');

    if (tokens.size() != 3) {
        cout << "Bad input! " << input << endl;
    } else if ((!TypeChecker::is_number(tokens[1])) || (!TypeChecker::is_number(tokens[2])) || (!TypeChecker::is_product(tokens[0], orderBook))) {

        // check if price or amount is a valid double
        if (!TypeChecker::is_number(tokens[1])) {
            cout << "Invalid price " << tokens[1] << endl;
        }
        if (!TypeChecker::is_number(tokens[2])) {
            cout << "Invalid amount " << tokens[2] << endl;
        }

        // check if product is correct input
        if (!TypeChecker::is_product(tokens[0], orderBook)) {
            cout << "Invalid product " << tokens[0] << endl;
        }
    } else {
        try {
            OrderBookEntry obe = CSVReader::stringsToOBE(
                tokens[1],
                tokens[2],
                currentTime,
                tokens[0],
                OrderBookType::bid
            );
            orderBook.insertOrder(obe);
        } catch (exception& e) {
            cout << "Bad OrderBookEntry input" << endl;
        }
    }
    
    cout << "You typed: " << input << endl;
}

void AppMain::printWallet() {
    cout << "Your wallet is empty. " << endl;
}
        
void AppMain::goToNextTimeFrame() {
    currentTime = orderBook.getNextTime(currentTime);
    cout << "New time is: " << currentTime << endl;
}
 
int AppMain::getUserOption() {
    int userOption = 0;
    string line;
    cout << "Type in 1-7" << std::endl;
    getline(cin, line);
    try {
        userOption = std::stoi(line);
    } catch(const std::exception& e) {

    }
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
    currentTime = orderBook.getEarliestTime();
    do {
        printMenu();
        userOption = getUserOption();
        processUserOption(userOption);

    } while (userOption != 7);
}

