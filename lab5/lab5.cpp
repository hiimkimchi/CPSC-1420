// Bryan Kim
// lab5.cpp

#include <iostream>
using namespace std;

const char YES = 'y';

int main()
{
  int firstInt, secondInt;
  bool cont = true;
  char yOrN = 'y';

  cout << endl << endl;
  cout << "This program will determine if an integer is a multiple of"
       << " another\n(please don't input 0).\n";

  while (yOrN == YES) { 
    cout << "Please input two integers leaving a space in between them: ";
    cin >> firstInt >> secondInt;

    if (firstInt > secondInt) {
      if (firstInt % secondInt == 0) {     
        cout << "\nYes, " << firstInt << " is a multiple of " << secondInt
             << ", and the other factor is " << firstInt / secondInt << ".";
      } else {
        cout << "\nNo, " << firstInt << " is not a multiple of " << secondInt
             << ".";
      }
    } else {
      if (secondInt % firstInt == 0) {
        cout << "\nYes, " << secondInt << " is a multiple of " << firstInt
             << ", and the other factor is " << secondInt / firstInt << ".";
      } else {
        cout << "\nNo, " << secondInt << " is not a multiple of " << firstInt
             << ".";
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
