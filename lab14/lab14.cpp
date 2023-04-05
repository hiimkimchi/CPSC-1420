// Bryan Kim
// lab14.cpp

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Person
{
  string name;
  int age;
  int coffee;
};

void printRec(Person p);

double averageAge(const Person list[], int numE);

int totalCoffee(const Person list[], int numE);

const int MAX = 150;
const int NAME_SPACING = 12;
const int AGE_CUPS_SPACING = 4;
const string FILE_NAME = "/home/fac/sreeder/class/cs1420/lab14input.dat";
const int DIGITS = 5;

int main()
{
  Person clients[MAX];
  int count = 0;
  ifstream inFile;
  
  cout << endl << endl;
  
  inFile.open(FILE_NAME);
  if (inFile.fail()) {
    cout << "File error. Press enter to exit program.";
    cin.get();
    return 0;
  }
  
  while (inFile >> clients[count].name) {
    inFile >> clients[count].age >> clients[count].coffee;
    count++;
  }

  inFile.close();
  
  cout << "Printing (name, age, coffee cups per day)...\n";
  
  for (int i = 0; i < count; i++) {
    printRec (clients[i]);
    cout << endl;
  }

  cout << endl << endl;
  cout << "Average Age: " << setprecision(DIGITS)
       << averageAge(clients, count);
  cout << endl << "Total Cups of Coffee: " << totalCoffee(clients, count);

  cout << endl << endl;
  
  return 0;
}

void printRec (Person p)
{
  cout << left << setw(NAME_SPACING) << p.name;
  cout << setw(AGE_CUPS_SPACING) << p.age;
  cout << setw(AGE_CUPS_SPACING) << p.coffee;
}

double averageAge (const Person list[], int numE)
{
  double total = 0.0;
  for (int i = 0; i < numE; i++) {
    total += list[i].age;
  }
  
  return total/numE;
}

int totalCoffee (const Person list[], int numE)
{
  int total;
  for (int i = 0; i < numE; i++) {
    total += list[i].coffee;
  }
  
  return total;
}
