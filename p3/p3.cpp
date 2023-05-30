// Bryan Kim
// p3.cpp
// This code replicates the hit board game Chutes and Ladders.
// This version will put two players against each other and they will spin
// a spinner (1-6) to move spaces. Some spaces will have chutes and ladders
// (chutes = move down, ladders = move up).

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

using namespace std;

void welcome(string& name1, string& name2);
// prints a welcome message and stores names.

char goodbye();
// prints a goodbye message and asks if players want to replay.

int spin();
// spins a spinner (1-6).

int checkLoc(int currentLoc);
// checks current location for a chute or ladder.

void takeTurn(int& location, string player, bool& p1Turn);
// takes a turn for the desired player. 

int main()
{
  const char YES = 'y';
  int p1Location;
  int p2Location;
  string p1Name;
  string p2Name;
  char cont = YES;
  bool p1Turn = true;
  
  
  srand(time(0));
  
  welcome(p1Name, p2Name);
  while (tolower(cont) == YES) {
    p1Location = 0;
    p2Location = 0;

    while (p1Location != 100 && p2Location != 100) {
      if (p1Turn) {
        takeTurn (p1Location, p1Name, p1Turn);
      } else {
        takeTurn (p2Location, p2Name, p1Turn);
      }
    }
    cont = goodbye();
  }  
  return 0;
}
  
void welcome(string& name1, string& name2)
{
  cout << endl << endl;
  cout << "Welcome to Chutes and Ladders! Your goal is to reach exactly square"
       << " 100.\nThere will also be ladders that boost you and chutes that"
       << " move you back down.\nTwo players will play this game.\n";
  cout << endl << "Please enter player 1's name: ";
  getline (cin, name1);
  cout << endl << "Please enter player 2's name: ";
  getline (cin, name2);
}

char goodbye()
{
  char cont;
  cout << endl << endl << "Thanks for playing Chutes and Ladders!"
       << endl << "Would you like to play again? (y/n): ";
  cin >> cont;
  if (!cont) {
    cout << endl <<"Goodbye! Play again sometime!";
    cout << endl << endl;
  }
  return cont;
}
 
int spin ()
{
  const int MAX_SPIN = 5;
  int currentSpin = (rand() % MAX_SPIN) + 1;
  return currentSpin;
}

int checkLoc (int currentLoc)
{
  const int ONE_SPACE = 1;
  const int FOUR_SPACE = 4;
  const int THREE_SPACE = 3;
  const int EIGHT_SPACE = 8;
  const int NINE_SPACE = 9;
  const int TEN_SPACE = 10;
  const int TWELVE_SPACE = 12;
  const int FIFTEEN_SPACE = 15;
  const int SIXTEEN_SPACE = 16;
  const int NINTEEN_SPACE = 19;
  const int TWENTY_SPACE = 20;
  const int TW_ONE_SPACE = 21;
  const int TW_TWO_SPACE = 22;
  const int TW_THREE_SPACE = 23;
  const int TW_EIGHT_SPACE = 28;
  const int TH_SIX_SPACE = 36;
  const int TH_SEVEN_SPACE = 37;
  const int TH_EIGHT_SPACE = 38;
  const int FO_THREE_SPACE = 43;
  const int FO_EIGHT_SPACE = 48;
  const int FO_NINE_SPACE = 49;
  const int FI_ONE_SPACE = 51;
  const int FI_SIX_SPACE = 56;
  const int SI_TWO_SPACE = 62;
  const int SI_THREE_SPACE = 63;
  const int SI_FOUR_SPACE = 64;
  const int SE_ONE_SPACE = 71;
  const int EIGHTY_SPACE = 80;
  const int EI_SEVEN_SPACE = 87;
  const int NI_THREE_SPACE = 93;
  const int NI_FIVE_SPACE = 95;
  const int NI_EIGHT_SPACE = 98;
  
  int spacesMoved;
  if (currentLoc == ONE_SPACE) {
    spacesMoved = TH_SEVEN_SPACE;
  } else if (currentLoc == FOUR_SPACE) {
    spacesMoved = TEN_SPACE;
  } else if (currentLoc == NINE_SPACE) {
    spacesMoved = TWELVE_SPACE;
  } else if (currentLoc == SIXTEEN_SPACE) {
    spacesMoved = -TEN_SPACE;
  } else if (currentLoc == TW_THREE_SPACE) {
    spacesMoved = TW_ONE_SPACE;
  } else if (currentLoc == TW_EIGHT_SPACE) {
    spacesMoved = FI_SIX_SPACE;
  } else if (currentLoc == TH_SIX_SPACE) {
    spacesMoved = EIGHT_SPACE;
  } else if (currentLoc == FO_EIGHT_SPACE) {
    spacesMoved = -TW_TWO_SPACE;
  } else if (currentLoc == FO_NINE_SPACE) {
    spacesMoved = -TH_EIGHT_SPACE;
  } else if (currentLoc == FI_ONE_SPACE) {
    spacesMoved = FIFTEEN_SPACE;
  } else if (currentLoc == FI_SIX_SPACE) {
    spacesMoved = -THREE_SPACE;
  } else if (currentLoc == SI_TWO_SPACE) {
    spacesMoved = -FO_THREE_SPACE;
  } else if (currentLoc == SI_FOUR_SPACE) {
    spacesMoved = -FOUR_SPACE;
  } else if (currentLoc == SE_ONE_SPACE) {
    spacesMoved = NINTEEN_SPACE;
  } else if (currentLoc == EIGHTY_SPACE) {
    spacesMoved = TWENTY_SPACE;
  } else if (currentLoc == EI_SEVEN_SPACE) {
    spacesMoved = -SI_THREE_SPACE;
  } else if (currentLoc == NI_THREE_SPACE ||
             currentLoc == NI_FIVE_SPACE || currentLoc == NI_EIGHT_SPACE) {
    spacesMoved = -TWENTY_SPACE;
  } else {
    spacesMoved = 0;
  }
  return spacesMoved;
}

void takeTurn (int& currentLoc, string player, bool& p1Turn)
{
  int spinner = spin();
  int spacesMoved = checkLoc(currentLoc + spinner);
  if (currentLoc + spinner <= 100) {
    currentLoc += spinner;
  }
  int realCurrentLoc = currentLoc + spacesMoved;
  
  cout << endl << endl << "Press enter to spin: ";
  cin.ignore();
  cout << player << ", you spun " << spinner << ". \n" <<  endl;

  if (spacesMoved > 0) {
    cout << "Lucky! There was a ladder on this space." << endl;
  } else if (spacesMoved < 0) {
    cout << "Booo. There was a chute on this space." << endl;
  } else {
    cout << "There was no chute or ladder on this space." << endl;
  }
  cout << player << ", you are now at space " << realCurrentLoc << "." << endl;

  if (p1Turn) {
    p1Turn = false;
  } else {
    p1Turn = true;
  }
  currentLoc = realCurrentLoc;
}
