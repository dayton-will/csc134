/*
M4HW1
CSC 134
dayton-will
10/22/2025
Print Multiplication Table ("Times Table")
*/

// magic words to start -- feed the Magic Wish Machine!

#include <iostream>
#include <iomanip> 
using namespace std;

//Function Declarations (Definitions are at the bottom)
void say_hello(); // says hi

int get_the_answer(); // Provides answers

double double_a_number(); // num times two

int main() {
//This program does nothing userful!
double my_num;
int another_num;

cout << "Welcome to the best program ever!" << endl;
cout << "Please enter a number (with or without decimal place)." << endl;
cin >> my_num;
my_num = my_num * 2;
cout << "Double the number is: " << my_num << endl;

}