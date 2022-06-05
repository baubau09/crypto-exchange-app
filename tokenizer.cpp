#include <iostream>
#include <vector>
#include <string>

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

    string s = "hello,I,have three tokens";
    vector<string> tokens = tokenise(s, ',');
    // note the use of const and & below
    // const says I won't edit t
    // & says I don't want to copy t from one of the tokens
    // I want to access the original version of the token
    for (const string& t : tokens) {
        std::cout << t << std::endl;
    }
}