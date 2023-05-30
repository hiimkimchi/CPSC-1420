// Bryan Kim
// p2.cpp
// This program will allow two players to play a text based game similar to the
// hit board game "Hi Ho! Cherry-O." The objective is to collect a total of
// 10 cherries before your opponent.

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
  const int MAX_SPIN = 6;
  const int MAX_CHERRY = 10;
  const int MIN_CHERRY = 0;
  const int ONE_CHERRY = 1;
  const int TWO_CHERRY = 2;
  const int THREE_CHERRY = 3;
  const int FOUR_CHERRY = 4;
  const int FIVE_CHERRY = 5;
  const int SIX_CHERRY = 6;
  
  int p1Bucket = MIN_CHERRY, p1Tree = MAX_CHERRY,
      p2Bucket = MIN_CHERRY, p2Tree = MAX_CHERRY, spin;
  bool p1Turn = true;
  string p1Name, p2Name, winner;

  srand(time(0));
  
  cout << endl << endl;

  cout << "Welcome to Hi Ho Cherry-O!\n"
       << "\nThere are 10 cherries on your tree."
       << "\nYour objective is to get all 10 of them in your bucket."
       << "\nTwo players will be able to " 
       << "play this game.\n\nPlease input player 1's name: ";
  getline (cin, p1Name);

  cout << "\nPlease input player 2's name: ";
  getline (cin, p2Name);

  while (p1Bucket < MAX_CHERRY && p2Bucket < MAX_CHERRY) {
    if (p1Turn) {
      cout << endl << endl
           << p1Name << ", it's your turn! Press enter to spin.\n";
      cin.ignore();
    } else {
      cout << endl << endl
           << p2Name << ", it's your turn! Press enter to spin.\n";
      cin.ignore();
    }

    spin = (rand() % MAX_SPIN) + 1;
    cout << "The spinner says " << spin << ".\n";

    if (spin == ONE_CHERRY) {
      if (p1Turn) {
        p1Tree--;
        p1Bucket++;
      } else {
        p2Tree--;
        p2Bucket++;
      }
      cout << "One cherry has been added to your bucket!\n";
      
    } else if (spin == TWO_CHERRY) {
      if (p1Turn) {
        p1Tree -= TWO_CHERRY;
        p1Bucket += TWO_CHERRY;
      } else {
        p2Tree -= TWO_CHERRY;
        p2Bucket += TWO_CHERRY;
      }
      cout << "Ooh, two cherries have been added to your bucket!\n";

    } else if (spin == THREE_CHERRY) {
      if (p1Turn) {
        p1Tree = MAX_CHERRY;
        p1Bucket = 0;
      } else {
        p2Tree = MAX_CHERRY;
        p2Bucket = 0;
      }
      cout << "Oh no! All of your cherries are back on the tree.\n";
      
    } else if (spin == FOUR_CHERRY) {
      if (p1Turn) {
        p1Tree -= FOUR_CHERRY;
        p1Bucket += FOUR_CHERRY;
      } else {
        p2Tree -= FOUR_CHERRY;
        p2Bucket += FOUR_CHERRY;
      }
      cout << "Lucky! Four cherries have been added to your bucket!\n";
      
    } else if (spin == FIVE_CHERRY) {
      cout << "That darn dog! The dog came";
      if (p1Turn) {
        if (p1Bucket == ONE_CHERRY) {
          p1Bucket--;
          p1Tree++;
          cout << " and took a cherry from your bucket.\n";
        } else if (p1Bucket > ONE_CHERRY) {
          p1Bucket -= TWO_CHERRY;
          p1Tree += TWO_CHERRY;
          cout << " and took two cherries from your bucket.\n";
        } else {
          cout << ", but no cherries have been taken.\n";
        }
        
      } else {
        if (p2Bucket == ONE_CHERRY) {
          p2Bucket--;
          p2Tree++;
          cout << " and took a cherry from your bucket.\n";
        } else if (p2Bucket > ONE_CHERRY) {
          p2Bucket -= TWO_CHERRY;
          p2Tree += TWO_CHERRY;
          cout << " and took two cherries from your bucket.\n";
        } else {
          cout << ", but no cherries have been taken.\n";
        }
      }
      
    } else if (spin == SIX_CHERRY) {
      if (p1Turn) {
        p1Bucket += THREE_CHERRY;
        p1Tree -= THREE_CHERRY;
      } else {
        p2Bucket += THREE_CHERRY;
        p2Tree -= THREE_CHERRY;
      }
      cout << "Wow, three cherries have been added to your bucket!\n";
      
    } else {
      cout << "Come on! " << p1Name << ", the bird came";
      if (p1Turn) {
        if (p1Bucket == ONE_CHERRY) {
          p1Bucket--;
          p1Tree++;
          cout << " and took a cherry from your bucket.\n";
        } else if (p1Bucket > ONE_CHERRY) {
          p1Bucket -= TWO_CHERRY;
          p1Tree += TWO_CHERRY;
          cout << " and took two cherries from your bucket.\n";
        } else {
          cout << ", but no cherries have been taken.";
        }
        
      } else {
        if (p2Bucket == ONE_CHERRY) {
          p2Bucket--;
          p2Tree++;
          cout << " and took a cherry from your tree.\n";
        } else if (p2Bucket > ONE_CHERRY) {
          p2Bucket -= TWO_CHERRY;
          p2Tree += TWO_CHERRY;
          cout << " and took two cherries from your bucket.\n";
        } else {
          cout << ", but no cherries have been taken.";
        }
        
      }
    }
    
    if (p1Bucket > p2Bucket) {
      winner = p1Name;
    } else {
      winner = p2Name;
    }
    
    
    if (p1Turn) {
      if (p1Bucket > MAX_CHERRY) {
        cout << p1Name << ", you have 10 cherries." << endl;
      } else if (p1Bucket == ONE_CHERRY) {
        cout << p1Name << ", you have 1 cherry." << endl;
      } else {
        cout << p1Name << ", you have " << p1Bucket << " cherries." << endl;
      }
      p1Turn = false;
    } else {
      if (p2Bucket > MAX_CHERRY) {
        cout << p2Name << ", you have 10 cherries." << endl;
      } else if (p2Bucket == ONE_CHERRY) {
        cout << p2Name << ", you have 1 cherry." << endl;
      } else {
        cout << p2Name << ", you have " << p2Bucket << " cherries." << endl;
      }
      p1Turn = true;
    }

    
  }
    
  cout << endl << endl << winner << " wins!" << " Thank you for playing!";
  cout << endl << endl;
    
  return 0;
}
