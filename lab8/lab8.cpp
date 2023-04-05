// Bryan Kim
// lab8.cpp

#include <iostream>
using namespace std;

//DONT DO GLOBAL VARIABLES HERE, LOST POINTS FOR IT.
void welcome();
void goodbye();
int input();
int summation(int val);
const char YES = 'y';
int val;
char cont = YES;

int main()
{
  welcome();
  while (tolower(cont) == YES) {
    input();
    cout << endl << "The sum of all numbers between 1 and " << val;
    cout << " is " << summation(val);
    cout << ".\n";
    cout << "Would you like to input another value? (y or n): ";
    cin >> cont;
  }
  goodbye();
  return 0;
}

void welcome()
{
  cout << endl << endl << "Welcome to Lab 8!" << endl << endl;
}

void goodbye()
{
  cout << endl << endl << "Goodbye!" << endl << endl;
}

int input()
{
  const int MAX = 25;
  const int MIN = 5;
  val = 0;
  while (val < MIN || val > MAX) {
    cout << endl << "Please input a value (5 to 25): ";
    cin >> val;
  }
  return val;
}

int summation (int val)
{
  int sum = 0;
  for (int i = 1; i <= val; i++) {
    sum += i;
  }
  return sum;
}
  
