// Bryan Kim
// lab3.cpp
// This lab determines if the first user inputed int is a multiple of the second.
// (Did not error check for dividing by zero)

#include <iostream>

using namespace std;

int main()
{
  int firstInt, secondInt;

  cout << endl << endl;
  cout << "This program will determine if the first integer is a multiple of"
       << " the second\n(please don't input 0).\n";
  cout << "Please input two integers leaving a space in between them: ";
  cin >> firstInt >> secondInt;

  if (firstInt % secondInt == 0) {
    cout << "\nYes, " << firstInt << " is a multiple of " << secondInt
         << ", and the other factor is " << firstInt / secondInt << ".";
  } else {
    cout << "\nNo, " << firstInt << " is not a multiple of " << secondInt
         << ".";
  }

  cout << endl << endl;
  return 0;
}
