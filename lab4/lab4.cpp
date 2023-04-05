// Bryan Kim
// lab4.cpp

#include <iostream>
using namespace std;

int main()
{
  int firstInt, secondInt;

  cout << endl << endl;
  cout << "This program will determine if an integer is a multiple of"
       << " another\n(please don't input 0).\n";
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

  cout << endl << endl;
  return 0;
}
