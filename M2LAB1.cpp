/*
CSC 134
M2 Lab 1 - Case Study with Crates
dayton-will
9/8/2025

volume =length x width x height
cost= volume x 0.23
charge= volume x 0.5
profit = charge-cost


*/

//magic words to start -- feed the Magic Wish Machine!
#include <iostream>
using namespace std;

int main()  {
//Set up the variables.
    double length, width, height; // size of crate
    double volume; //length * width * height
    double cost_to_make, charge_to_customer;
    double profit;

    const double cost_per_cubic_foot = 0.23; //relates to cost
    const double charge_per_cubic_foot = 0.5; // relates to charge

//Ask the user to input crate info.

cout << "ATD Shipping Crate Calculator. This application will provide our cost, price, and profit when building a shipping crate for one of our partners." << endl;
cout << "Crate length (feet):" << endl;
cin >> length;
cout << "Crate Width (feet): ";
cin >> width;
cout << "Crate Height (feet): ";
cin >> height;


//Calculate cost and prices.
volume = length * width * height;
cost_to_make = volume * cost_per_cubic_foot;
charge_to_customer = volume * charge_per_cubic_foot;
profit = charge_to_customer - cost_to_make;

//Display results.
cout << endl;
cout << "Your crate is " << volume << " cubic feet." << endl;
cout << "Customer Price: $" << charge_to_customer << endl;
cout << "Cost to Build : $" << cost_to_make << endl;
cout << "Profit        : $" << profit << endl;


return 0; // no errors

}