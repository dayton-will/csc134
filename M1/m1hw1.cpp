/*
CSC 134
M1 Lab
dayton-will
8/27/2025

Movie Talk: Create an output (using cout) about the film Meru, including the following variables:
1) Something to hold the name of the movie (string)
2) Something to hold the year it came out (int)
3) Something to hold the box office gross with a decimal (double)

References
IMDb.com. (2015, August 14). Meru. IMDb. https://www.imdb.com/title/tt2545428/ 

*/

#include <iostream>
using namespace std;
int main()  {
//start program
//movie name
string name = "Meru";
//year
int release = 2015;
//Box Office gross 
double boxOffice = 2.3;

cout << "The epic climbing documentary " << name;
cout << ", released in " << release;
cout << ", grossed $" << boxOffice << " million in the US and Canada. ";

}

