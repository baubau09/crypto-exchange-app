#include "Wallet.h"

using namespace std;

Wallet::Wallet() {}

void Wallet::insertCurrency(string type, double amount) {

}

bool Wallet::removeCurrency(string type, double amount) {

    return false;
}

bool Wallet::containsCurrency(std::string type, double amount) {

    return false;
}

bool Wallet::canFulfillOrder(OrderBookEntry order) {

    return false;
}

void Wallet::processSale(OrderBookEntry& sale) {

}

string Wallet::toString() {
    return "Wallet: ";
}


