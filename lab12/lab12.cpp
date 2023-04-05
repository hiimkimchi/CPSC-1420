// Bryan Kim
// lab12.cpp

#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

const string FILE_NAME = "/home/fac/sreeder/class/cs1420/lab12input.dat";
const int MAX_LENGTH = 50;

void printList (const double arr[], int numE);

double total (const double arr[], int numE);

int readFile (double arr[]);

int main()
{
  double list[MAX_LENGTH] = {0};
  int count;
  
  cout << endl << endl;
  count = readFile(list);
  if (count == 0) {
    cout << "Wrong File, press enter to exit the program.";
    cin.get();
    return 0;
  }
  printList (list, count);
  cout << endl << endl;
  cout << "Total: " << total (list, count);
  cout << endl << endl;
  
  return 0;
}

int readFile (double arr[])
{
  ifstream inFile;
  int count = 0;
  double num;
  inFile.open(FILE_NAME);
  
  while (inFile >> num) {
    arr[count] = num;
    count++;
  }
  inFile.close();
  return count;
}

void printList (const double arr[], int numE)
{
  const int SPACING = 8;
  const int DIGITS = 3;
 
  cout << setw(SPACING) << "Index";
  cout << setw(SPACING) << "Value" << endl;

  for (int i = 0; i < numE; i++) {
    cout << setw(SPACING) << i << fixed << showpoint
         << setprecision(DIGITS) << setw(SPACING) << arr[i] << endl;
  }
}

double total (const double arr[], int numE)
{
  double tot = 0;
  for (int i = 0; i < numE; i++) {
    tot += arr[i];
  }
  return tot;
}
