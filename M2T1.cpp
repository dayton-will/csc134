/*
M2T1 - Tire Shop
CSC 134
dayton-will, 9/3/25
Revision of "sales" program from M1, now with user input.
M2T1*/

//magic words to start -- feed the Magic Wish Machine! (This is the only way I will refer to a computer from now on)

#include <iostream>
#include <iomanip>

using namespace std;
int main() {
    // Declare variables
    string item = "tire";
    string items = "tires";
    double cost_per = 93.50;
    int amount = 100;
    //Variables for user input
    int amount_purchased;
    double total_cost;

    // Greet customer
    cout << "Hello! Welcome to our " << item << " shop.";

    // Ask for information
    std::cout << " Each " << item << " costs $" << std::fixed << std::setprecision(2) << cost_per << std::endl;

    cout << "We have " << amount << " " << items << " available." << endl;
    cout << "How many " << items << " do you need?" << endl;

    // cin: user input into variable
    cin >> amount_purchased;
    // Process information
    total_cost = amount_purchased * cost_per;

    // Output answer
    std::cout << "Your total cost is: $" << std::fixed << std::setprecision(2) << total_cost << std::endl;
    cout << "Our techs will have those installed within an hour. We accept cash or all major credit cards; no personal checks." << endl;
    cout << "Thank you for your business. Have a great day!" << endl;

    return 0;

}