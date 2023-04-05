// Bryan Kim
// lab9.cpp
// 10/26/22

#include <iostream>
#include <string>

using namespace std;

void input(string& str1, string& str2);
// str1 and str2 will be overwritten

void swapStr(string& str1, string& str2);
// strings will be switched

void output(string str1, string str2);
// prints str1 and str2

int main()
{
  string str1;
  string str2;
  
  cout << endl << endl;
  input (str1, str2);
  output (str1, str2);
  swapStr (str1, str2);
  output (str1, str2);
  cout << endl << endl;
  return 0;
}

void input (string& str1, string& str2)
{
  cout << "Please enter a string: ";
  getline(cin, str1);
  cout << "\nPlease enter another string: ";
  getline(cin, str2);
}

void swapStr (string& str1, string& str2)
{
  string temp = str1;
  str1 = str2;
  str2 = temp;
}

void output (string str1, string str2)
{
  cout << endl << endl << "string 1 is " << str1
       << " and string 2 is " << str2 << endl << endl;
}
