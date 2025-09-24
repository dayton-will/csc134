/*
M3LAB1 - Choose Your Own Adventure
CSC 134
dayton-will
9/24/2025
*/

#include <iostream>
using namespace std;

//================FUNCTION PROTOTYPES================//
//Declare all y locations here
void home(); // Starting location
void gym(); // Garage gym!
void kitchen(); // Where the food lives.
void homeOffice(); // Where I answer the phone



//Declare all my customers here
void Hannah(); // Single mom, messy car. Ford Taurus.
void Warren(); // Local entrepreneur. Runs a small gym. F250 pickup truck. Has kids and dogs.
void Lauren(); // Nurse with a "side hustle" as a certified masseuse. Doesn't have kids of her own, but spends a lot of time with nieces/nephews.
void Jonny(); // Description
void Lucille(); // Description

void gameOver(); // An ending
void victory(); // Another ending

//==========MAIN FUNCTION==========//
int main()
{
    cout << "=========================================" << endl;
    cout << "WELCOME TO YOUR ENTREPRENEURIAL ADVENTURE" << endl;
    cout << "=========================================" << endl;
    cout << endl;

 home();   //Start the adventure!

 cout << "\nYou wake up, rubbing the sleep from your eyes, an obnoxious dog whining in your face."<< endl;
 cout << "You know how you should start your day. Do you slam your preworkout and get a workout in, or head to the kitchen for coffee?"<< endl;
 cout << "(1 = Preworkout, 2 = Coffeee):";

 int choice;
 cin >> choice;
 if (choice == 1)
{
    cout << "\nExcellent choice! You feel your ears burning from the preworkout, you hit a deadlift PR, and your shins are bleeding" <<endl;
    cout << "from the barbell scraping them. Great workout, and you're ready to crush the day." << endl;
}

 return 0;
}