/*
M3LAB2 - Letter Grades/Game Mechanics Test
CSC 134
dayton-will
9/24/2025
*/

// words to start -- feed the Magic Wish Machine!

#include <iostream>
using namespace std;

// Write the code in a function
void letter_grader();
void combat();

int main() {
   
    letter_grader();
    // combat();
     return 0;


}

//define other functions here

void letter_grader() {
    // Input a number grade.
    // Respond with a letter grade.
    double num_grade;
    string letter_grade;
    // Constants for grade breakpoints.
    const double A_GRADE = 90; // (or higher)
    const double B_GRADE = 80;
    const double C_GRADE = 70;
    const double D_GRADE = 60;

    cout << "Enter a number grade 0-100: ";
    cin >> num_grade;

    // Create the "if" statements.
    if (num_grade >= A_GRADE ) {
        letter_grade = "A";
    }

    else if (num_grade >= B_GRADE ) {
        letter_grade = "B";
    }

    else if (num_grade >= C_GRADE ) {
        letter_grade = "C";
    }

    else if (num_grade >= D_GRADE ) {
        letter_grade = "D";
    }

    else {
        letter_grade = "F";
    }



    // Output the answer
    cout << "A number grade of " << num_grade << " is: " << letter_grade;
    cout << endl << endl;

}

/* 
90 - 100 A
80 - 89 B
70 - 79 C
60 - 69 D
< 60 F
*/