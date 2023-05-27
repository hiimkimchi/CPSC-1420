//Bryan Kim
//p1.cpp
//This program takes user inputed strings and integers and
//implements them into a paragraph, creating a
//"MadLibs" type word game.

#include <iostream>
#include <string>
using namespace std;

int main()
{
  int age;
  string name, place, college, career, animal, petName;

  cout << endl << endl;

  cout << "\nWelcome to the Word Game! You will get a series\n"
       << "of prompts and a paragraph story will be printed" << endl
       << "afterwards.\n" << endl;
  
  cout << "Please enter a name: ";
  getline (cin, name);
  
  cout << "Enter an age (as an integer): ";
  cin >> age;
  cin.ignore();
  
  cout << "Enter a place: ";
  getline (cin, place);
  
  cout << "Enter a college: ";
  getline (cin, college);
  
  cout << "Enter a career: ";
  getline (cin, career);
  
  cout << "Enter an animal: ";
  getline (cin, animal);
  
  cout << "Enter another name: ";
  getline (cin, petName);
  
  cout << "\nThere once was a person named " << name
       << " who lived in " << place << ". " << endl
       << "At the age of " << age << ", " << name
       << " went to college at " << college << ". " << endl
       << name << " graduated and went to work as a " << career << "."
       << "\nThen, " << name << " adopted a(n) " << animal
       << " named " << petName << ".\n"
       << "They both lived happily ever after!\n";
  
  cout << "\nThank you for playing the Word Game! Have a nice day.\n";

  cout << endl << endl;
  return 0;
}
