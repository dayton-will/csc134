/*
M2HW1
CSC 134
dayton-will
9/15/2025
Complete 2, 3, or 4 questions.

*/
#include <iostream>
#include <iomanip> // for...?
using namespace std;

//put other functions above main()

void question1() {
    cout << "Question 1" << endl;
}

void question2() {
    cout << "Question 1" << endl;
}

void question3() {
    cout << "Question 1" << endl;
}

void question4() {
    cout << "Question 1" << endl;
}

int main() {
    //call each question as its own function

    question1();

    cout << "Example of printing out correct money values" << endl;
    double cost = 8.0;
    // magic words for 2 decimal places
    cout << setprecision(2) << fixed; // requires "#include <iomanip>"
    cout << "The cost is: $" << cost << endl;""
    question2();
    question3();
    question4();
    return 0;

}
