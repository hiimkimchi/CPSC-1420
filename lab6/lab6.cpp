// Bryan Kim
// lab6.cpp

#include <iostream>
#include <cctype>
using namespace std;

const char YES = 'y';
const int INITIAL_VAL1 = 2;
const int INITIAL_VAL2 = 3;

int main()
{
  int firstInt, secondInt;
  char yOrN = YES;

  cout << endl << endl;
  cout << "This program will determine if an integer is a multiple of"
       << " another\n(please don't input 0).\n";

  while (tolower(yOrN) == YES) {
    firstInt = INITIAL_VAL1, secondInt = INITIAL_VAL2;
    cout << "Please input two integers leaving a space in between them: ";
    
    while (firstInt % secondInt != 0 && secondInt % firstInt != 0) {
      cin >> firstInt >> secondInt;
    
      if (firstInt > secondInt) {
        if (firstInt % secondInt == 0) {     
          cout << "\nYes, " << firstInt << " is a multiple of " << secondInt
               << ", and the other factor is " << firstInt / secondInt << ".";
        } else {
          cout << "\nNo, " << firstInt << " is not a multiple of " << secondInt
               << ". Please input another pair: ";
        }
      
      } else {
        if (secondInt % firstInt == 0) {
          cout << "\nYes, " << secondInt << " is a multiple of " << firstInt
               << ", and the other factor is " << secondInt / firstInt << ".";
        } else {
          cout << "\nNo, " << secondInt << " is not a multiple of " << firstInt
               << ". Please input another pair: ";
        }
      }
      
    }
    cout << endl << endl <<  "Would you like to input another pair? (y or n) ";
    cin >> yOrN;

    cout << endl << endl;
    
  }
  cout << "Goodbye!";
  cout << endl << endl;
  return 0;
}
