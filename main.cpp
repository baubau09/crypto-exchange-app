#include <iostream>

using namespace std;


void printMenu() {
    cout << "===========MENU===========" << endl;
    cout << "1. Print Help" << endl;
    cout << "2. Print Exchange Stats" << endl;
    cout << "3. Make an Offer" << endl;
    cout << "4. Make a bid" << endl;
    cout << "5. Print wallet" << endl;
    cout << "6. Continue" << endl;
    cout << "7. Exit" << endl;
    cout << "=========END MENU=========" << endl;
    cout << "Please input a number from 1-7" << endl;
}

int getUserOption() {
    int userOption = 0;
    cin >> userOption;
    cout << "You chose: " << userOption << endl;
    return userOption;
}

void processOption(int userOption) {
    switch (userOption)
    {
    case 1: // help
        cout << "Help - your aim is to make money" << endl;
        break;
    case 2: // exchange stats
        cout << "Market looks good" << endl;
        break;
    case 3: // make an offer
        cout << "Please choose which currency do you want to sell" << endl;
        break;
    case 4: // make a bid
        cout << "Please choose the currency you want to buy" << endl;
        break;
    case 5: // print wallet
        cout << "You look rich" << endl;
        break;
    case 6: // Continue
        cout << "continueeee" << endl;
        break;
    case 7:
        cout << "Bye bye" << endl;
        break;
    default:
        cout << "Invalid choice! Please only choose from 1 - 7" << endl;
        break;
    }
}

int main() {
    int userOption = 0;
    do {
        printMenu();
        userOption = getUserOption();
        processOption(userOption);

    } while (userOption != 7);
}
