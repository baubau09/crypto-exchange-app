#include "OrderBook.h"


OrderBook::OrderBook(string fileName) {
    orders = CSVReader::readCSV(fileName);

}

vector<string> OrderBook::getKnownProducts() {
    vector<string> products;
    map<string, bool> prodMap;

    for (OrderBookEntry& e : orders) {
        prodMap[e.getProduct()] = true;
    }

    for (auto& productStringBoolPair : prodMap) {
        products.push_back(productStringBoolPair.first);
    }

    return products;
}

vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, string product, string timestamp) {
    vector<OrderBookEntry> orders_sub;

    for (OrderBookEntry& e : orders) {
        if (e.getOrderType() == type &&
            e.getProduct() == product &&
            e.getTimeStamp() == timestamp) {
                orders_sub.push_back(e);
        }
    }

    return orders_sub;
}

double OrderBook::getHighPrice(vector<OrderBookEntry>& orders) {
    double max = 0.0;

    for (OrderBookEntry& e : orders) {
        if (e.getPrice() > max) {
            max = e.getPrice();
        }
    }
    return max;
}

double OrderBook::getLowPrice(vector<OrderBookEntry>& orders) {
    double min = orders[0].getPrice();

    for (OrderBookEntry& e : orders) {
        if (e.getPrice() < min) {
            min = e.getPrice();
        }
    }
    return min;
}

string OrderBook::getEarliestTime() {
    string earliest = orders[0].getTimeStamp();
    for (OrderBookEntry& e : orders) {
        if (e.getTimeStamp() < earliest) {
            earliest = e.getTimeStamp();
        }
    }
    return earliest;
}

string OrderBook::getNextTime(string timestamp) {
    string next_timestamp = "";
    for (OrderBookEntry& e : orders) {
        if (e.getTimeStamp() > timestamp) {
           next_timestamp = e.getTimeStamp();
           break;
        }
    }

    if (next_timestamp == "") {
        next_timestamp = getEarliestTime();
    }

    return next_timestamp;
}

void OrderBook::insertOrder(OrderBookEntry& order) {
    orders.push_back(order);
    sort(orders.begin(), orders.end(), OrderBookEntry::compareByTimestamp);
}