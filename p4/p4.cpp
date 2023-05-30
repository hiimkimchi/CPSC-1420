// Bryan Kim
// p4.cpp
// This code creates a memory game where the user will have to match 6 pairs of
// cards together to win. The user can either choose expert or beginner modes,
// which alters the seconds waited by the program.

#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int COL = 3;
const int ROW = 4;
const char YES = 'y';
const char STAR = '*';
const string LEFT = " [";
const string RIGHT = "] ";
const char UNDERSC = '_';
const int MAX_MATCH = 6;

void welcome (int& secs);
// prints welcome message and asks for difficulty level
// adjusts secs accordingly

void wait (int secs);
// makes the program pause for secs

bool readFile (char board[][COL], string fileName);
// chooses one of the files at random and reads it
// initializes all the indexes of the array

int display (char board[][COL], int c1Row = -1, int c1Col = -1,
              int c2Row = -1, int c2Col = -1);
// displays the board and depending on the fx call, can display all * and _
// , one card and the * and _, or both cards and the * and _.
// returns 1 if match and 0 if not.

void getFirstCard (const char board[][COL], int& c1Row, int& c1Col);
// gets row and column of first card. checks for user errors.

void getSecondCard (char board[][COL], int& c2Row, int& c2Col,
                    int c1Row, int c1Col);
// gets row and column of second card. checks for user errors and if the card
// has already been chosen in the previous fx.

void clearScreen ();
// clears screens with a bunch of endls

char goodbye (int score);
// says goodbye and takes score as a parameter/prints score and returns
// y or n to continue or not.

int main()
{
  char board[ROW][COL];
  int c1Row;
  int c1Col;
  int c2Row;
  int c2Col;
  int secs;
  string fileName;
  bool isFileValid;
  int numMatches;
  int increment;
  int score = 0;
  char contPlaying = YES;
  
  srand(time(0));
  
  welcome(secs);

  while (contPlaying == YES) {
    numMatches = 0;
    isFileValid = readFile(board, fileName);
    if (!isFileValid) {
      cout << "File error. Press enter to exit code.";
      cin.get();
      return 0;
    }
    
    while (numMatches < MAX_MATCH) { 
      clearScreen();
      display(board);
      getFirstCard (board, c1Row, c1Col);
      clearScreen();
      display (board, c1Row, c1Col);
      getSecondCard (board, c2Row, c2Col, c1Row, c1Col);
      clearScreen();
      increment = display (board, c1Row, c1Col, c2Row, c2Col);
      numMatches += increment;
      score++;
      wait (secs);
    }
    contPlaying = goodbye(score);
  }
  cout << endl << "Goodbye!" << endl << endl;
  return 0;
}

void welcome (int& secs)
{
  const char EXPERT = 'e';
  const char BEGINNER = 'b';
  const int EXPERT_SECS = 2;
  const int BEGINNER_SECS = 4;
  char difficulty = ' ';
  cout << endl << endl;
  cout << "Welcome to the Memory Game!\n"
       << "Are you a beginner or an expert? (press b for beginner and"
       << " e for expert) ";
  while (difficulty != EXPERT && difficulty != BEGINNER) {
    cin >> difficulty;
    if (difficulty == EXPERT) {
      secs = EXPERT_SECS;
    } else if (difficulty == BEGINNER) {
      secs = BEGINNER_SECS;
    } else {
      cout << endl << "Please input a valid option.";
    }
  }
}

void wait (int secs)
{
  clock_t endwait;
  endwait = clock() + secs * CLOCKS_PER_SEC;
  while (clock() < endwait){}
}

bool readFile (char board[][COL], string fileName)
{
  const string FILE1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
  const string FILE2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";
  ifstream inFile;
  char currentChar;
  int randChoice = (rand() % 1);
  
  if (randChoice == 0) {
    fileName = FILE1;
  } else if (randChoice == 1) {
    fileName = FILE2;
  }
  
  inFile.open(fileName);

  if (inFile.fail()) {
    return false;
  }
  
  for (int r = 0; r < ROW; r++) {
    for (int c = 0; c < COL; c++) {
      inFile >> currentChar;
      board[r][c] = currentChar;
    }
  }
  inFile.close();
  return true;
}

int display (char board[][COL], int c1Row, int c1Col,
              int c2Row, int c2Col)
{
  const int SPACING = 5;
  const char SPACE = ' ';
  for (int r = 0; r < ROW - 1; r++) {
    cout << setw(SPACING) << r;
  }
  
  for (int r = 0; r < ROW; r++) {
    cout << endl << r << SPACE;
    for (int c = 0; c < COL; c++) {
      cout << LEFT;
      
      if (c1Row != -1 && c1Col != -1 && r == c1Row && c == c1Col) {
        cout << board[r][c];
      } else if (c2Row != -1 && c2Col != -1 && r == c2Row && c == c2Col) {
        cout << board[r][c];  
      } else if (board[r][c] == UNDERSC) {
        cout << UNDERSC;
      } else {
        cout << STAR;
      }
      cout << RIGHT;
    }
  }
  if (board[c1Row][c1Col] == board[c2Row][c2Col] && c1Row != -1 &&
      c1Col != -1 && c2Row != -1 && c2Col != -1) {
    cout << endl << "That's a match!" << endl;
    board[c1Row][c1Col] = '_';
    board[c2Row][c2Col] = '_';
    return 1;
  } else {
    if (c1Row != -1 && c1Col != -1 && c2Row != -1 && c2Col != -1) {
      cout << endl << "Oops, that's not a match..." << endl;
    }
    return 0;
  }
}

void getFirstCard (const char board[][COL], int& c1Row, int& c1Col)
{
  bool isTaken = true;
  while (isTaken) {
    cout << endl << "Please enter a row: ";
    cin >> c1Row;
    cout << "Please enter a column: ";
    cin >> c1Col;

    if (board[c1Row][c1Col] == '_') {
      cout << "Card already taken." << endl;
    } else if (c1Row > ROW - 1 || c1Col > COL - 1) {
      cout << "Card doesn't exist." << endl;
    } else {
      isTaken = false;
    }
  }
}

void getSecondCard (char board[][COL], int& c2Row, int& c2Col,
                    int c1Row, int c1Col)
{
  bool isTaken = true;
  while (isTaken) {
    cout << endl << "Please enter another row: ";
    cin >> c2Row;
    cout << "Please enter another column: ";
    cin >> c2Col;

    if (board[c2Row][c2Col] == '_') {
      cout << "Card already taken." << endl;
    } else if (c2Row == c1Row && c2Col == c1Col) {
      cout << "Card was just chosen." << endl;
    } else if (c2Row > ROW - 1 || c2Col > COL - 1) {
      cout << "Card doesn't exist." << endl;
    } else {
      isTaken = false;
    }
  }
}

void clearScreen ()
{
  const int SPACES = 40;
  for (int i = 0; i < SPACES; i++) {
    cout << endl;
  }
}

char goodbye(int score)
{
  char choice;
  cout << endl << endl;
  cout << "Thanks for playing!\nYou took " << score
       <<" turns.\n Would you like to play again?" << endl
       << "(y or n) ";
  cin >> choice;
  return choice;
}
