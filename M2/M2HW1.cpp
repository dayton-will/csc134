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
#include <functional> /* Allows hash so the same account number is always tied to a given name.
(I didn't control for variation such as inconsistent capitalization).
*/

using namespace std;

//put other functions above main()

void question1() {
    string name; // Get user's name
    double account_balance; // Current account balance
    double deposit_amount; // Amount customer is depositing
    double withdrawal_amount; // amount customer is withdrawing
    double final_balance;
    
    cout << "Question 1" << endl;
    cout << setprecision(2) << fixed;  // magic words for 2 decimal places; requires "#include <iomanip>"

    // Greet the customer, obtain name
    cout << "Welcome to Gringott's Wizarding Bank, est. 1474. May I please get the name on the account?" << endl;
    cin.ignore();
    getline(cin, name);   // Allow full name w/ spaces
    // Obtain account balance
    cout << "Thank you, " << name << ". What is your current account balance?" << endl;
    cin >> account_balance;
    // Obtain deposit amount
    cout << "Thank you. How much would you like to deposit?" << endl;
    cin >> deposit_amount;
    // Obtain withdrawal amount
    cout << "Thank you. And how much would you like to withdraw?" << endl;
    cin >> withdrawal_amount;
    
    //Obtain account number with hash
    std::hash<std::string> hasher;
    size_t raw_hash = hasher(name);
    int account_number = raw_hash % 1000000;  // clamp to 6 digits

    // Display pertinent information at end of transaction: similar to a receipt.
    cout << "\n -- Transaction Summary --" << endl;
    cout << "Name:          " << name << endl;
    cout << "Account #:     " << account_number << endl;
    final_balance = account_balance + deposit_amount - withdrawal_amount;
    cout << "Final Balance: $" << final_balance << endl;
    cout << "\n" << endl;
}

void question2() {
    cout << "Question 2" << endl;
    cout << setprecision(2) << fixed;  // magic words for 2 decimal places; requires "#include <iomanip>"

    //Set up the variables.
    double length, width, height; // size of crate
    double volume; //length * width * height
    double cost_to_make, charge_to_customer;
    double profit;

    const double COST_PER_CUBIC_FOOT = 0.3; //relates to cost
    const double CHARGE_PER_CUBIC_FOOT = 0.52; // relates to charge

//Ask the user to input crate info.

    cout << "General Crates Building Calculator. This application will provide our cost, price, and profit when building a shipping crate for one of our partners." << endl;
    cout << "Crate Length (feet):";
    cin >> length;
    cout << "Crate Width (feet) :";
    cin >> width;
    cout << "Crate Height (feet):";
    cin >> height;


//Calculate cost and prices.
    volume = length * width * height;
    cost_to_make = volume * COST_PER_CUBIC_FOOT;
    charge_to_customer = volume * CHARGE_PER_CUBIC_FOOT;
    profit = charge_to_customer - cost_to_make;

//Display results.
    cout << endl;
    cout << "Your crate is " << volume << " cubic feet." << endl;
    cout << "Customer Price: $" << charge_to_customer << endl;
    cout << "Cost to Build : $" << cost_to_make << endl;
    cout << "Profit        : $" << profit << endl;
    cout << "\n" << endl;

}

void question3() {
    // 
    int pizzas_ordered;
    int party_people;
    int slices_per_pizza;
    int leftover_slices;



    cout << "Question 3" << endl;
    cout << "Welcome to the Epic Pizza Party Planner!" << endl;
    cout << "How many pizzas are you ordering? (numerical value only) ";
    cin >> pizzas_ordered;
    cout << "How many slices per pizza? "; 
    cin >> slices_per_pizza;
    cout << "How many people are you inviting? ";
    cin >> party_people;

    // Define leftover slices, assuming 3 slices per party attendee
    leftover_slices = (pizzas_ordered * slices_per_pizza) - (party_people * 3);

    cout << "With " << pizzas_ordered << " pizzas for " << party_people << " people, you should have " << leftover_slices << " slices remaining at the end of the party." << endl;
    cout << "\n" << endl;

}

void question4() {
    cout << "Question 4" << endl;
}

int main() {
    //call each question as its own function
    //start with a menu - this will make it easier to choose which program to run. (Flash gave me the idea for the menu, but the code is all mine.)
    
    string choice; // Text input for the menu. Selecting 1-4 will run the associated program, while 0 will exit the menu.



    do {
        cout << "===== MENU =====" << endl;
        cout << "1 - Run Question 1" << endl;
        cout << "2 - Run Question 2" << endl;
        cout << "3 - Run Question 3" << endl;
        cout << "4 - Run Question 4" << endl;
        cout << "0 - Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;
        cout << "\n" << endl;


        if (choice == "1") {
            question1();
        }

        if (choice == "2") {
            question2();
        }

        if (choice == "3") {
            question3();
        }

        if (choice == "4") {
            question4();
        }



    } while (choice != "0");

return 0; // no errors

}
