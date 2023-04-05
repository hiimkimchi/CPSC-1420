//Bryan Kim
//lab2.cpp

#include <iostream>
#include <string>
using namespace std;

int main()
{
  string word;
  int integer1, integer2, quotient, modResult;
  double float1, float2, doubleQuotient;

  cout << endl << "\nPlease input a single word: ";
  cin >> word;
  cout << "\nYou have inputed: " << word << ".\n";
  
  cout << "\nPlease input two integers seperated by a space: ";
  cin >> integer1 >> integer2;
  quotient = integer1 / integer2;
  modResult = integer1 % integer2;
  
  cout << endl << integer1 << " divided by " << integer2 << " is "
       << quotient << ".\n";
       
  cout << integer1 << " mod " << integer2 << " is " << modResult << ".\n";

  cout << "\nPlease input two float numbers separated by a space: ";
  cin >> float1 >> float2;
  doubleQuotient = float1 / float2;
  
  cout << endl << float1 << " divided by " << float2 << " is "
       << doubleQuotient << ".\n" << endl;
}
