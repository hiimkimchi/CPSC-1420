// Bryan Kim
// lab10.cpp

#include <iostream>
#include <fstream>

using namespace std;

const string FILE_NAME = "/home/fac/sreeder/class/cs1420/lab10input.dat";
const int TWO = 2;
const int SIZE = 30;

int main()
{
  ifstream inFile;
  int oddNum [SIZE];
  int evenNum [SIZE];
  int negNum [SIZE];
  int num;
  int oddCount = 0;
  int evenCount = 0;
  int negCount = 0;

  cout << endl << endl;
  
  inFile.open(FILE_NAME);
  if (inFile.fail()) {
    cout << "File failed. Please press enter to exit the program.";
    cin.get();
    return 0;
  }

  while (inFile >> num) {
    if (num % TWO == 0 && num > 0) {
      evenNum[evenCount] = num;
      evenCount++;
    }
    if (num % TWO != 0 && num > 0) {
      oddNum[oddCount] = num;
      oddCount++;
    }
    if (num < 0) {
      negNum[negCount] = num;
      negCount++;
    }
  }

  cout << endl << "Printed, this is the evenNum array." << endl << endl;
  for (int i = 0; i < evenCount; i++) {
    cout << "Index: " << i << " is " << evenNum[i] << endl;
  }

  cout << endl << "Printed, this is the oddNum array." << endl << endl;
  for (int i = 0; i < oddCount; i++) {
    cout << "Index: " << i << " is " << oddNum[i] << endl;
  }

  cout << endl << "Printed, this is the negNum array." << endl << endl;
  for (int i = 0; i < negCount; i++) {
    cout << "Index: " << i << " is " << negNum[i] << endl;
  }

  inFile.close();
  
  return 0;
}
