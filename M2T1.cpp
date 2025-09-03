/*
M2T1 - hello, user
CSC 134
dayton-will, 9/3/25
Revision of "sales" program from M1, now with user input.
m2t1*/

//magic words to start -- feed the Magic Wish Machine! (This is the only way I will refer to a computer from now on)

#include <iostream>

using namespace std;
int main() {
    // Declare variables ("the truth")
    string item = "apple";
    double cost_per = 0.99;
    int amount = 20;
    //Variables for user input
    int amount_purchased;
    double total_cost;

    // Greet the user
    cout << "Hello! Welcome to our " << item << " store.";
    // Ask for information
    cout << " Each " << item << " costs $" << cost_per << endl;
    cout << "We have " << amount << " available." << endl;
    cout << "How many would you like?" << endl;
    // cin: user input into variable
    cin >> amount_purchased;
    // Process information
    total_cost = amount_purchased * cost_per;
    // Output the answer
    cout << "Your total cost is: $" << amount_purchased << endl;


    return 0;


}