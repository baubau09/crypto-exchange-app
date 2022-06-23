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
    vector<string> currencies = CSVReader::tokenise(order.getProduct(), '/');

    // ask
    if (order.getOrderType() == OrderBookType::ask) {
        double amount = order.getAmount();
        string currency = currencies[0];
        cout << "Wallet::canFulfillOrder " << currency << " : " << amount << endl; 
        return containsCurrency(currency, amount);
    }

    // bid 
    if (order.getOrderType() == OrderBookType::bid) {
        double amount = order.getAmount() * order.getPrice();
        string currency = currencies[1];
        cout << "Wallet::canFulfillOrder " << currency << " : " << amount << endl; 
        return containsCurrency(currency, amount);
    }

    return false;
}

void Wallet::processSale(OrderBookEntry& sale) {
    vector<string> currs = CSVReader::tokenise(sale.getProduct(), '/');
    // ask
    if (sale.getOrderType() == OrderBookType::asksale)
    {
        double outgoingAmount = sale.getAmount();
        string outgoingCurrency = currs[0];
        double incomingAmount = sale.getAmount() * sale.getPrice();
        string incomingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;

    }
    // bid
    if (sale.getOrderType() == OrderBookType::bidsale)
    {
        double incomingAmount = sale.getAmount();
        string incomingCurrency = currs[0];
        double outgoingAmount = sale.getAmount() * sale.getPrice();
        string outgoingCurrency = currs[1];

        currencies[incomingCurrency] += incomingAmount;
        currencies[outgoingCurrency] -= outgoingAmount;
    }
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

std::ostream& operator<<(std::ostream& os,  Wallet& wallet) {
    os << wallet.toString();
    return os;
}



