/*
M3T2 - Craps Part 1
CSC 134
dayton-will
9/22/25
Beginning of the craps game
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//Helper functions (todo)
//int roll();

//main
int main() {
    // int num = roll();
    // cout << num << endl;
    //MAIN CRAPS CYCLR
    // For now:
    /*
    - roll 26 (2-12)
    - branch based on win, lose, or point
    - rest comes later/*
    */
    int roll1;
    int roll2;
    int point; // roll if it doesn't immediately win/lose


    // Blatantly cheat
    cout << "enter two dice ( press ENTER between) ";
    cin >> roll1;
    cin >> roll2;
    
    // Set sum
    int sum = roll1+roll2;


    if ( (sum == 7) || (sum == 11) ) {
        cout << "Lucky Seven -- You win!" << endl;
        cout << "\n" << endl;
    }

    else if ( ( sum ==2) || (sum == 3) || (sum == 12) ) {
        cout << "1, 2, 12 -- Sorry, you lose." << endl;

    }

    else {
        // set the point
        point = sum;
        cout << "Did not roll a seven." << endl;
        cout << "Your point is: " << point << endl;


    }

    


return 0;

//DEFINE Helper Functions
int roll; {
    // rolls a six sided die
    //TODO
    return 7;
}



}
