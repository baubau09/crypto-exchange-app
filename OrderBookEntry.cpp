#include "OrderBookEntry.h"

OrderBookEntry::OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType) : price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType) {}

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