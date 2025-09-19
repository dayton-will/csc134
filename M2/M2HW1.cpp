/*
M2HW1
CSC 134
dayton-will
9/15/2025
Complete 2, 3, or 4 questions.

*/

// magic words to start -- feed the Magic Wish Machine!

#include <iostream>
#include <iomanip> 
using namespace std;

//put other functions above main()

void question1() {
    cout << "Question 1" << endl;
}

void question2() {
    cout << "Question 2" << endl;
}

void question3() {
    cout << "Question 3" << endl;
}

void question4() {
    cout << "Question 4" << endl;
}

int main() {
    //call each question as its own function
    //start with a menu - this will make it easier to choose which program to run. (Flash gave me the idea for the menu, but the code is all mine.)
    
    string choice; // Text input for the menu. Selecting 1-4 will run the associated program, while 0 will exit the menu.
    string name; // Get user's name
    double account_balance; // Current account balance
    double deposit_amount; // Amount customer is depositing
    double withdrawal_amount; // amount customer is withdrawing

    do {
        cout << "===== MENU =====" << endl;
        cout << "1 - Run Question 1" << endl;
        cout << "2 - Run Question 2" << endl;
        cout << "3 - Run Question 3" << endl;
        cout << "4 - Run Question 4" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == "1") {
            question1();
            break; //end the "do...while" loop
        }

    } while (choice != "0");



    //question1();

    cout << "Welcome to Gringott's Wizarding Bank, est. 1474. May I please get the name on the account?" << endl;
    cin >> name;
    cout << "Thank you, " << name << ". What is your current account balance?" << endl;
    cin >> account_balance;
    cout << "Thank you. How much would you like to deposit?" << endl;
    cin >> deposit_amount;
    cout << "Thank you. And how much would you like to withdraw?" << endl;
    cin >> withdrawal_amount;

    cout << setprecision(2) << fixed;  // magic words for 2 decimal places; requires "#include <iomanip>"

/*    
    question2();
    question3();
    question4();
    
*/
return 0; // no errors

}
