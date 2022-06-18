#include "CSVReader.h"
#include <iostream>
#include <fstream>

CSVReader::CSVReader() {

}

vector<string> CSVReader::tokenise(string csvLine, char separator) {
    vector<string> tokens; //  stores the tokens
    int start, end; // used to delineate the position of the tokens
    string token;

    start = csvLine.find_first_not_of(separator);

    do {
        end = csvLine.find_first_of(separator, start);

        if (start == csvLine.length() || start == end) break; // nothing more to find
        if (end >= 0) {
            token = csvLine.substr(start, end - start); // start, substring length
        } else {
            token = csvLine.substr(start, csvLine.length() - start); // end is invalid
        }

        tokens.push_back(token); // add token to the end of the tokens vector

        start = end + 1; // move past this token

    } while (end > 0); // continue loop condition

    return tokens;
}

OrderBookEntry CSVReader::stringsToOBE(vector<string> tokens) {
    double price, amount;
    if (tokens.size() != 5) {
        cout << "Bad line " << endl;
        throw exception{};
    }
    // we have 5 tokens
    try {
        price = stod(tokens[3]);
        amount = stod(tokens[4]);
        //cout << price << ": " << amount << endl;
    } catch (const exception &e)
    {
        cout << "Bad float (price): " << tokens[3] << endl;
        cout << "Bad float (amount): " << tokens[4] << endl;
        throw;
    }
    OrderBookEntry obe{price, amount, tokens[0], tokens[1],OrderBookEntry::stringsToOrderBookType(tokens[2])};

    return obe;
}

OrderBookEntry CSVReader::stringsToOBE(string priceString, string amountString, string timestamp, string product, OrderBookType orderType) {
    double price, amount;
    try {
         price = stod(priceString);
         amount = stod(amountString);
    }catch(const exception& e){
        cout << "CSVReader::stringsToOBE Bad float! " << priceString<< std::endl;
        cout << "CSVReader::stringsToOBE Bad float! " << amountString << endl; 
        throw;        
    }
    OrderBookEntry obe{price, 
                    amount, 
                    timestamp,
                    product, 
                    orderType};
                
    return obe;
}

vector<OrderBookEntry> CSVReader::readCSV(string csvFileName) {
    vector<OrderBookEntry> entries;
    ifstream csvFile{csvFileName};
    string line;

    if (csvFile.is_open())
    {
        while(getline(csvFile, line))
        {
            try {
                OrderBookEntry obe = stringsToOBE(tokenise(line, ','));
                entries.push_back(obe);
            }catch(const exception& e)
            {
                std::cout << "CSVReader::readCSV bad data"  << std::endl;
            }
        }// end of while
    }    

    cout << "CSVReader::readCSV read " << entries.size() << " entries"  << endl;

    return entries;
}