/*
M3LAB1 - Choose Your Own Adventure
CSC 134
dayton-will
9/24/2025
*/

#include <iostream>
using namespace std;

//================FUNCTION PROTOTYPES================//
// Declare all your locations here
void home();       // Starting location
void gym();        // Garage gym!
void kitchen();    // Where the food lives
void homeOffice(); // Where I answer the phone

// Declare business activities here

// Declare all my customers here
void Hannah();   // Single mom, messy car. Ford Taurus.
void Warren();   // Local entrepreneur. Runs a small gym. F250 pickup truck. Has kids and dogs.
void Lauren();   // Nurse with a "side hustle" as a certified masseuse. Doesn't have kids of her own, but spends a lot of time with nieces/nephews.
void Jonny();   // Description
void Lucille(); // Description

void gameOver(); // An ending
void victory();  // Another ending

//==========MAIN FUNCTION==========//
int main()
{
    cout << "=========================================" << endl;
    cout << "WELCOME TO YOUR ENTREPRENEURIAL ADVENTURE" << endl;
    cout << "=========================================" << endl;
    cout << endl;

    home();   // Start the adventure!

    return 0;
}

//==========FUNCTION DEFINITIONS==========//

void home()
{
    cout << "\nYou wake up, rubbing the sleep from your eyes, an obnoxious dog whining in your face." << endl;
    cout << "You know how you should start your day. Do you slam your preworkout and get a workout in, or head to the kitchen for coffee?" << endl;
    cout << "(1 = Preworkout, 2 = Coffee): ";

    int choice;
    cin >> choice;

    if (choice == 1)
    {
        cout << "\nExcellent choice! You feel your ears burning from the preworkout, you hit a deadlift PR, and your shins are bleeding" << endl;
        cout << "from the barbell scraping them. Great workout, and you're ready to crush the day." << endl;
        cout << endl;
    }
    else
    {
        cout << "\nReally, you thought you should skip your workout today? Nice try. You slam your pre and head to the gym." << endl;
        cout << "You feel your ears burning from the preworkout, you hit a deadlift PR, and your shins are bleeding" << endl;
        cout << "from the barbell scraping them. Great workout, and you're ready to crush the day." << endl;
        cout << endl;
    }

    cout << endl;

    homeOffice(); // Go to Home Office Function
}

void homeOffice()
{
    // TODO Build Home Office Function
    cout << "\nYour workout complete, you grab a cup of coffee and head to your desk." << endl;
    cout << "What do you do next?" << endl;
    cout << "1 = Plan your day, 2 = Call leads, 3 = Check Email, 4 = Check Instagram." << endl;
    int choice;
    cin >> choice;
    
    if (choice == 1)
    {
        cout << "\nExcellent choice. Research indicates that planning your day helps you work with your brain's natural patterns" << endl;
        cout << "and get organized." << endl;
        cout << endl;
    }

    else if (choice == 2)
    {
        //Build 2 = Call leads
    }

        else if (choice == 3)
    {
        //Build 3 = Call leads
    }

        else if (choice == 4)
    {
        //Build 4 = Check social media (YOU FAIL AND DIEEEEEE!)
    }


}
