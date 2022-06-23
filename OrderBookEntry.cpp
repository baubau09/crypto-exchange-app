#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry() {}

OrderBookEntry::OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType, std::string _username) : price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType), username(_username) {}

OrderBookType OrderBookEntry::stringsToOrderBookType(std::string s) {
    if (s == "ask") {
        return OrderBookType::ask;
    }
    if (s == "bid") {
        return OrderBookType::bid;
    }
    if (s == "asksale") {
        return OrderBookType::asksale;
    }
    if (s == "bidsale") {
        return OrderBookType::bidsale;
    }
    return OrderBookType::unknown;
}

double OrderBookEntry::getPrice() {
    return price;
}

double OrderBookEntry::getAmount() {
    return amount;
}

std::string OrderBookEntry::getTimeStamp() {
    return timestamp;
}

std::string OrderBookEntry::getProduct() {
    return product;
}

OrderBookType OrderBookEntry::getOrderType() {
    return orderType;
}

std::string OrderBookEntry::getUsername() {
    return username;
}

void OrderBookEntry::setPrice(double _price) {
    this->price = _price;
}

void OrderBookEntry::setAmount(double _amount) {
    this->amount = _amount;
}

void OrderBookEntry::setTimeStamp(std::string _timestamp) {
    this->timestamp = _timestamp;
}

void OrderBookEntry::setProduct(std::string _product) {
    this->product = _product;
}

void OrderBookEntry::setType(OrderBookType _type) {
    this->orderType = _type;
}

void OrderBookEntry::setUsername(std::string _username) {
    this->username = _username;
}

bool OrderBookEntry::compareByTimestamp(const OrderBookEntry& e1, const OrderBookEntry& e2) {
    return e1.timestamp < e2.timestamp;
}

bool OrderBookEntry::compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2) {
    return e1.price < e2.price;
}

bool OrderBookEntry::compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2) {
    return e1.price > e2.price;
}