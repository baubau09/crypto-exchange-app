#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> tokenise(string csvLine, char separator) {
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

int main() {
    string csvFileName{"20200317.csv"};
    ifstream csvFile{csvFileName};
    string line;

    if (!csvFile.is_open()) {
        cout << "Problem opening file " << csvFileName << endl;
    } else {
        cout << "Opened file " << csvFileName << endl;
        
        while (getline(csvFile, line)) {
            cout << "Read line " << line << endl;
            vector<string> tokens = tokenise(line, ',');
            if (tokens.size() != 5) {
                cout << "Bad line " << endl;
                continue;
            }
            // we have 5 tokens
            try {
                double price = stod(tokens[3]);
                double amount = stod(tokens[4]);
                cout << price << ": " << amount << endl;
            } catch (const exception& e) {
                cout << "Bad float (price): " << tokens[3] << endl;
                cout << "Bad float (amount): " << tokens[4] << endl;
                break;
            }
            
        }
    }
    csvFile.close();

}