// Bryan Kim
// lab16.cpp

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

int findMax(const Person list[], int numE);

int findMin(const Person list[], int numE);

void selSort(Person list[], int numE);

void swap(Person& p1, Person& p2);

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
  int indexLeast;
  int indexMost;
  
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
  
  indexMost = findMax(clients, count);
  cout << "The oldest person's record:" << endl;
  printRec(clients[indexMost]);
  cout << endl << endl;

  indexLeast = findMin(clients, count);
  cout << "The person with the least coffees consumed:" << endl;
  printRec(clients[indexLeast]);
  cout << endl << endl;

  selSort(clients, count);
  cout << "Printing Alphabetically (name, age, coffee cups per day)...\n";
  cout << endl;
  for (int i = 0; i < count; i++) {
    printRec (clients[i]);
    cout << endl;
  }
  
  cout << endl << endl;
  
  return 0;
}

void printRec (Person p)
{
  cout << left << setw(NAME_SPACING) << p.name;
  cout << right << setw(AGE_CUPS_SPACING) << p.age;
  cout << right << setw(AGE_CUPS_SPACING) << p.coffee;
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

int findMax (const Person list[], int numE)
{
  int maxIndex = 0;
  for (int i = 1; i < numE; i++) {
    if (list[i].age > list[maxIndex].age) {
      maxIndex = i;
    }
  }
  return maxIndex;
}

int findMin (const Person list[], int numE)
{
  int minIndex = 0;
  for (int i = 1; i < numE; i++) {
    if (list[i].coffee < list[minIndex].coffee) {
      minIndex = i;
    }
  }
  return minIndex;
}

void selSort (Person list[], int numE)
{
  int index;
  for (int i = 0; i < numE; i++) {
    index = i;
    for (int j = i + 1; j < numE; j++) {
      if (list[j].name < list[index].name) {
        index = j;
      }
    }
    if (index != i)
      swap(list[index], list[i]);
  }    
}

void swap (Person& p1, Person& p2)
{
  Person temp = p1;
  p1 = p2;
  p2 = temp;
}
