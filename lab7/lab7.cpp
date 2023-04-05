//Bryan Kim
//lab7.cpp

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  const int MAX = 9;
  const int MIN = 3;
  const int WIDTH = 5;
  const char SPACE = ' ';
  int value;
  
  cout << endl << endl;
  while (value < MIN || value > MAX) {
    cout << "Please supply a value (between 3 and 9):";
    cin >> value;
    cin.ignore();
  }

  cout << endl << "Pattern 1!" << endl << endl;
  for (int i = 0; i < value; i++) {
    cout << value;
  }
  cout << endl << endl << "Press enter for the next pattern";
  cin.ignore();

  cout << endl << "Pattern 2!" << endl << endl;
  for (int i = 0; i < value; i++) {
    cout << "1" << endl;
  }
  cout << endl << endl << "Press enter for the next pattern";
  cin.ignore();

  cout << endl << "Pattern 3!" << endl << endl;
  cout << SPACE << SPACE;
  for (int i = 1; i <= value; i++) {
    cout << setw(WIDTH) << i;
  }
  cout << endl;

  for (int row = 1; row <= value; row++) {
    cout << row << SPACE;
    for (int col = 1; col <= value; col++) {
      cout << setw(WIDTH) << row * col;
    }
    cout << endl;
  }
  cout << endl << endl << "Press enter for the next pattern";
  cin.ignore();

  cout << endl << "Pattern 4!" << endl << endl;
  for (int i = 1; i <= value; i++) {
    for (int j = 1; j <= i; j++) {
      cout << i << SPACE;
    }
    cout << endl;
  }
  cout << endl << endl << "Press enter for the next pattern";
  cin.ignore();
    
  cout << endl << "Pattern 5!" << endl << endl;
  for (int i = 1; i <= value; i++) {
    for (int j = 0; j < i - 1 ; j++) {
      cout << SPACE;
    }
    cout << i << endl;
  }
  for (int i = value - 1; i > 0; i--) {
    for (int j = 0; j < i - 1; j++) {
      cout << SPACE;
    }
    cout << i << endl;
  }
  cout << endl << endl << "Press enter for the next pattern";
  cin.ignore();

  cout << endl << "Final Pattern!" << endl << endl;
  for (int i = 1; i < value; i++) {
    cout << SPACE;
  }
  cout << '1' << endl;

  for (int i = 2; i <= value ; i++) {
    for (int j = value; j > i; j--) {
      cout << SPACE;
    }
    cout << i;
    for (int j = 0; j < ((i - 1) * 2) - 1; j++) {
      cout << SPACE;
    }
    cout << i << endl;
  }
  for (int i = value - 1; i > 1; i--) {
    for (int j = i; j < value; j++) {
      cout << SPACE;
    }
    cout << i;
    for (int j = 0; j < ((i - 1) * 2) - 1;j++) {
      cout << SPACE;
    }
    cout << i << endl;
  }

  for (int i = 1; i < value; i++) {
    cout << SPACE;
  }
  cout << '1' << endl;
  cout << endl << endl;
  
  return 0;
}
