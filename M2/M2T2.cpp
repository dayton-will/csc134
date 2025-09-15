/*
M2T2 - Restaurant Receipt
CSC 134
dayton-will
9/15/2025
*/

//Taco Bell receipt for template. Stop at Taco Bell on the way home to enable effective completion.


//magic words to start -- feed the Magic Wish Machine!

# include <iostream>
#include <iomanip>
using namespace std;

int main()  {

    // Declare variables
    string item = "🌮Soft Taco";
    double menu_price = 2.19;
    double tax_percent = 0.07;  // 7% (4.75% NC sales tax, 2.25% Cumberland County sales tax)
    double tax_amount;          // Tax amount in $
    double total_price;

    // Calculate the values
    cout << "Order up" << endl;
    cout << item << " (x1)" << endl;
    cout << /*"\t"*/ << menu_price << endl;

    tax_amount = menu_price * tax_percent; // add sales tax
    total_price = menu_price + tax_amount;


    //Print the results
    cout << "Tax: $" << tax_amount << endl;
    cout << "Total: $" << total_price = menu_price + tax_amount << endl;


}