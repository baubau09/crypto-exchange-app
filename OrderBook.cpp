#include "OrderBook.h"
#include "CSVReader.h"


OrderBook::OrderBook(string fileName) {
    orders = CSVReader::readCSV(fileName);

}

vector<string> OrderBook::getKnownProducts() {
    vector<string> products;
    return products;
}

vector<OrderBookEntry> OrderBook::getOrders(OrderBookType type, string product, string timestamp) {
    return orders;
}