#pragma once
#include <string>
#include <iostream>

enum class OrderBookType{ask, bid, unknown, asksale, bidsale};

class OrderBookEntry {
    private:
        double price;
        double amount;
        std::string timestamp;
        std::string product;
        OrderBookType orderType;
        std::string username;
    public:
        OrderBookEntry();
        OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType, std::string username = "dataset");
        static OrderBookType stringsToOrderBookType(std::string s);
        static bool compareByTimestamp(const OrderBookEntry& e1, const OrderBookEntry& e2);
        static bool compareByPriceAsc(OrderBookEntry& e1, OrderBookEntry& e2);
        static bool compareByPriceDesc(OrderBookEntry& e1, OrderBookEntry& e2);
        double getPrice();
        double getAmount();
        std::string getTimeStamp();
        std::string getProduct();
        OrderBookType getOrderType();
        std::string getUsername();
        void setPrice(double _price);
        void setAmount(double _amount);
        void setTimeStamp(std::string _timestamp);
        void setProduct(std::string _product);
        void setType(OrderBookType _orderType);
        void setUsername(std::string _username);
};