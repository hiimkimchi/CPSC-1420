// Bryan Kim
// lab13.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const string FILE_NAME = "/home/fac/sreeder/class/cs1420/lab11input.dat";
const int ROW = 5;
const int COLUMN = 8;
const int SPACING = 5;
const string SPACE = "     ";
const string ADD_SPACE = "    ";

void printTable (int arr[][COLUMN]);

int findTotal (int arr[][COLUMN]);

int main()
{
  ifstream inFile;
  int arr[ROW][COLUMN] = {0};
  int num;

  cout << endl << endl;
  
  inFile.open(FILE_NAME);
  if (inFile.fail()) {
    cout << "File failed. Please press enter to exit the program.";
    cin.get();
    return 0;
  }
  
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COLUMN; c++) {
      inFile >> num;
      arr[r][c] = num;
    }
  }
  inFile.close();
  
  printTable(arr);
  findTotal(arr);
  cout << endl << "Total: " << SPACE << findTotal(arr);
  cout << endl << endl;
  return 0;
}

void printTable (int arr[][COLUMN])
{
  int rowTotal = 0;
  int colTotal = 0;
  cout << SPACE << ADD_SPACE;

  for (int c = 1; c <= COLUMN; c++) {
    cout << setw(SPACING) << c;
  }
  cout << endl;
  for (int r = 0; r < ROW; r++) {
    cout << r + 1 << SPACE << SPACE;
    rowTotal = 0;
    for (int c = 0; c < COLUMN; c++) {
      cout << setw(SPACING) << arr[r][c];
      rowTotal += arr[r][c];
    }
    cout << SPACE << ADD_SPACE << "Row Total: " << rowTotal << endl;
  }
  cout << "Col Tot:   ";
  for (int c = 0; c < COLUMN; c++) {
    colTotal = 0;
    for (int r = 0; r < ROW; r++) {
      colTotal += arr[r][c];
    }
    cout << setw(SPACING) << colTotal;
  }
}

int findTotal (int arr[][COLUMN])
{
  int total = 0;
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COLUMN; c++) {
      total += arr[r][c];
    }
  }
  return total;
}
