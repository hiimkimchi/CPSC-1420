// Bryan Kim
// lab15.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string FILE_NAME = "/home/fac/sreeder/class/cs1420/lab15input.dat";
const int MAX = 75;
const char YES = 'y';
const char SPACE = ' ';
const string BIG_SPACE = "    ";
const int WIDTH = 15;
const int SMALLWIDTH = 2;

int linSearch (string list[], int numE, string target);

int main()
{
  string list[MAX];
  ifstream inFile;
  int count = 0;
  char ans = YES;
  string word;
  int targetIndex;
  
  cout << endl << endl;
  inFile.open(FILE_NAME);
  if(inFile.fail()) {
    cout << endl << endl;
    cout << "Problem with reading file. Please press enter to quit.";
    cin.ignore();
    return 0;
  }
  
  while (count < MAX && inFile >> list[count]) {
    count++;
  }
  
  inFile.close();

  cout << "Index" << SPACE << "Word" << endl;
  for (int i = 0; i < count; i++) {
    cout << right << setw(SMALLWIDTH) << i << BIG_SPACE;
    cout << left << setw(WIDTH) << list[i] << endl;
  }

  while (tolower(ans) == YES) {
    cout << endl << "Which word would you like to search? ";
    cin >> word;
    targetIndex = linSearch(list, count, word);
    if (targetIndex == -1) {
      cout << endl << "Word does not exist in the group."; 
    } else {
      cout << endl << "Word exists and its index is: " << targetIndex << ".";
    }
    cout << endl << endl << "Would you like to search for another word? ";
    cin >> ans;
  }
  cout << endl << endl << "Goodbye" << endl << endl;
}

int linSearch (string list[], int numE, string target)
{
  int index = 0;
  while (index < numE && list[index] != target) {
    index++;
  }

  if (index < numE) {
    return index;
  } else {
    return -1;
  }
}
