#pragma once
#include <string>
#include <iostream>

enum class OrderBookType{ask, bid, unknown};

class OrderBookEntry {
    private:
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
    public:
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType);
        static OrderBookType stringsToOrderBookType(std::string s);
        double getPrice();
        double getAmount();
        std::string getTimeStamp();
        std::string getProduct();
        OrderBookType getOrderType();
        void setPrice(double _price);
        void setAmount(double _amount);
        void setTimeStamp(std::string _timestamp);
        void setProduct(std::string _product);
        void setType(OrderBookType _orderType);
};