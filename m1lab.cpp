/*
CSC 134
M1 Lab
dayton-will
8/27/2025

"Our goal is to use repl.it to write a program which displays the business name (ATD Mobile Detail), 
number of months for maintenance service, price per month, and the price to prepay all of them."
*/

//magic words to start -- feed the Magic Wish Machine!

#include <iostream>
using namespace std;
int main()  {
    //Start program.
//This program will serve as a prototype for pricing prepay for my mobile automotive detailing business.
//The owner's name
string name = "ATD";
//Number of months for maintenance package
int months = 6;

//Price per month
double pricePerMonth = 100.75;


//Greet customer

cout << "Thank you for calling " << name;
cout << " Mobile Detailing." << endl;
cout << "We're currently offering a promotion on our monthly maintenance package; " << endl;
cout << "$100.75 per month if you prepay six months in advance." << endl;

//calculate total price of prepay
double totalPrice = months * pricePerMonth;

cout << "Booking six months in advance will cost " << totalPrice << endl;





}