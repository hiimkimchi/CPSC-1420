// Bryan Kim
// lab3.cpp

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

  if (secondInt % firstInt == 0) {
    cout << "\nYes, " << firstInt << " is a multiple of " << secondInt
         << ", and the other factor is " << secondInt / firstInt << ".";
  } else {
    cout << "\nNo, " << firstInt << " is not a multiple of " << secondInt
         << ".";
  }

  cout << endl << endl;
  return 0;
}
