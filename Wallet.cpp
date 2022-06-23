#include "Wallet.h"

using namespace std;

Wallet::Wallet() {}

void Wallet::insertCurrency(string type, double amount) {
    double balance;

    if (amount < 0) {
        throw exception{};
    }
    if (currencies.count(type) == 0) {
        balance = 0;
    } else {
        balance = currencies[type];
    }

    balance += amount;
    currencies[type] = balance;
}

bool Wallet::removeCurrency(string type, double amount) {

    if (amount < 0) {
        return false;
    }
    if (currencies.count(type) == 0) {
        cout << "No currency for " << type << endl;
        return false;
    } else {
        if (containsCurrency(type, amount)) { // we have enough to remove
            cout << "Removing " << amount << " " << type << endl; 
            currencies[type] -= amount;
            return true;
        } else {
            return false;
        }
    }

    return false;
}

bool Wallet::containsCurrency(std::string type, double amount) {
    if (currencies.count(type) == 0) {
        return false;
    }
    return currencies[type] >= amount;
}

bool Wallet::canFulfillOrder(OrderBookEntry order) {

    return false;
}

void Wallet::processSale(OrderBookEntry& sale) {

}

string Wallet::toString() {
    string s;
    for (pair<string, double> pair : currencies) {
        string currency = pair.first;
        double amount = pair.second;
        s += currency + " : " + to_string(amount) + "\n";
    }
    return s;
}


