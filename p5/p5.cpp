// Bryan Kim
// p5.cpp
// This code does stuff replicates a simple version of the hit board game
// Monopoly. Up to 6 players can play and the winner is the 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>

using namespace std;

struct Location
{
  string name;
  int owner;
  int cost;
  int rent;
};

struct Player
{
  string name;
  int position;
  int money;
};

const string FILE_NAME = "/home/fac/sreeder/class/cs1420/p5input.dat";
const string CHANCE = "Chance";
const string CHAPEL = "Chapel of St. Ignatius";
const string GO = "Go";
const string TAX = "Income Tax";
const string FEES = "Fees";
const char YES = 'y';
const int MAX_SPACES = 45;
const int MAX_PLAYERS = 6;
const int MIN_PLAYERS = 2;
const int BEGIN_MONEY = 1500;
const int GO_MONEY = 200;
const int TAX_MONEY = 200;
const int CHANCE_ROLL = 3;
const int CHANCE_MONEY = 50;

void welcome();
// prints a welcome statement.

bool makeBoard(Location board[], int& count);
// makes the monopoly board by reading in the reference file.
// returns true if there is a file error, false if not.
// also returns an int of the number of spaces through passby reference.

int askPlayers(Player players[]);
// asks how many players and inputs the necessary information
// returns number of players.

int rollDice();
// rolls a die (1-6) and returns that as an int. 

int takeTurn(Player players[], Location board[], int currentPlayer,
              int numSpaces); 
// rolls both dice for current player and change location accordingly
// returns int that returns 0 if player passed Go, and -1 if not.

void checkLocation(Player players[], Location board[], int currentPlayer,
                   int passedGo, int numSpaces);
// checks the current location of current player and if its not an ownable
// space, does an action according to the space. Otherwise call property().

int linSearchBoard (Location board[], int numE, string target);
// linear search through the board array. returns int of index of target val.
  
void property(Player players[], Location board[], int currentPlayer);
// deals with property according to ownership or availibility and updates
// current player's money. Called by checkLocation.

bool checkForBankrupcy(Player players[], int numPlayers);
// checks each player if they have more than 0 dollars.
// return true if one player is bankrupt, false if not.

void result(Player players[], int numE);
// sorts through the players and prints the winner.

char playAgain();
// asks to play again. returns a char.

void goodbye();
// prints a goodbye message.

int main()
{
  Location board[MAX_SPACES];
  Player players[MAX_PLAYERS];
  bool isFaultyFile;
  int numPlayers = 0;
  int numSpaces = 0;
  int currentPlayer = 0;
  int passedGo;
  bool isBankrupt = false;
  char cont = YES;

  srand(time(0));
  
  welcome();
  isFaultyFile = makeBoard(board, numSpaces);
  
  if (isFaultyFile) {
    cout << endl << "Error reading the file... Press enter to exit code...";
    cin.ignore();
    return 0;
  }
  
  while (cont == YES) {
    numPlayers = askPlayers(players);
    while (!isBankrupt) {
      passedGo = takeTurn(players, board, currentPlayer, numSpaces);
      checkLocation(players, board, currentPlayer, passedGo, numSpaces);
      isBankrupt = checkForBankrupcy(players, numPlayers);
      
      if (currentPlayer < numPlayers - 1) {
        currentPlayer++;
      } else {
        currentPlayer = 0;
      }
    }
    result(players, numPlayers);
    cont = playAgain();
  }
  
  goodbye();
  return 0;
}

void welcome ()
{
  cout << endl << endl;
  cout << "Welcome to SU Monopoly!\nEach player will start with $1500"
       << " and two to six people are able to play.";
}

bool makeBoard (Location board[MAX_SPACES], int& count)
{
  ifstream inFile;
  inFile.open(FILE_NAME);

  if (inFile.fail()) {
    return true;
  }

  while (count < MAX_SPACES && getline (inFile, board[count].name)) {
    inFile >> board[count].owner;
    inFile >> board[count].cost;
    inFile >> board[count].rent;
    inFile.ignore();
    count++;
  }
  inFile.close();
  return false;
}

int askPlayers (Player players[])
{
  int numPlayers = 0;
  cout << endl << endl;
  
  while (numPlayers < MIN_PLAYERS || numPlayers > MAX_PLAYERS) {
    cout << "How many players will be playing? (2-6): ";
    cin >> numPlayers;
    cout << endl;
  }

  cin.ignore();
  for (int i = 0; i < numPlayers; i++) {
    players[i].position = 0;
    players[i].money = BEGIN_MONEY;
    cout << endl << "Player " << i + 1 << " what is your name? ";
    getline(cin, players[i].name);
    cout << endl;
  }
  return numPlayers;
}

int rollDice ()
{
  int die;
  const int MAX_SPIN = 5;
  die = (rand() % MAX_SPIN) + 1;
  return die;
}

int takeTurn (Player players[], Location board[], int currentPlayer,
               int numSpaces)
{
  int die1;
  int die2;
  int totalDice;
  int newPosition;
  cout << endl << endl << players[currentPlayer].name
       << ", press enter to roll ";
  cin.ignore();
  die1 = rollDice();
  cout << "The first die reads " << die1 << endl;
  die2 = rollDice();
  cout << "The second die reads " << die2 << endl;
  totalDice = die1 + die2;
  newPosition = totalDice + players[currentPlayer].position;
  
  if (newPosition > numSpaces) {
    players[currentPlayer].position = newPosition - numSpaces;
    return 0;
  } else {
    players[currentPlayer].position = newPosition;
    return -1;
  }
}

void checkLocation (Player players[], Location board[], int currentPlayer,
                    int passedGo, int numSpaces)
{
  int currentPos = players[currentPlayer].position;
  int chanceRoll;
  
  if (passedGo == 0) {
    cout << endl << "You passed Go! Collect $200!";
    players[currentPlayer].money += GO_MONEY;
  }
  
  if (board[currentPos].owner == -1) {
    if (board[currentPos].name == GO) {
      cout << endl << "You landed on Go! Collect $200!";
      players[currentPlayer].money += 200;
    } else if (board[currentPos].name == CHAPEL) {
      cout << endl << "You landed on the Chapel of St. Ignatius."
           << " Take a rest...";
    } else if (board[currentPos].name == TAX) {
      cout << endl << "You landed on Income Tax. Pay up! You lost $200.";
      players[currentPlayer].money -= TAX_MONEY;
    } else if (board[currentPos].name == FEES) {
      cout << endl << "You landed on Fees. Pay up! You lost $200.";
      players[currentPlayer].money -= TAX_MONEY;
    } else {
      cout << endl << "You landed on Chance! Press enter to roll a die."
           << " If it lands on 1-3, earn $50!\nIf it lands on 4-6, earn a"
           << " free trip to the Chapel of St. Ignatius for a rest.";
      cin.ignore();
      chanceRoll = rollDice();
      cout << endl << "You rolled a " << chanceRoll << ". ";
      
      if (chanceRoll < 4) {  
        cout << "You earned $50!";
        players[currentPlayer].money += CHANCE_MONEY;
      } else {
        cout << "You're now at the Chapel of St. Ignatius.";
        players[currentPlayer].position =
          linSearchBoard(board, numSpaces, CHAPEL);
      }
    }
    
    if (players[currentPlayer].money < 0) {
      cout << endl << "You don't have any more money...";
    } else {
    cout << endl << "You have $" << players[currentPlayer].money << ".";
    }
    cout << endl << "(Press enter to continue...)";
    cin.ignore();
  } else {
    property(players, board, currentPlayer);
  }
}

int linSearchBoard (Location board[], int numE, string target)
{
  int index = 0;
  while (index < numE && board[index].name != target) {
    index++;
  }

  if (index < numE) {
    return index;
  } else {
    return -1;
  }
}

void property (Player players[], Location board[], int currentPlayer)
{
  int playerNum = currentPlayer + 1;
  int currentLocation = players[currentPlayer].position;
  int ownerNum = board[currentLocation].owner - 1;
  char ans;
  
  cout << endl << "You landed on " << board[currentLocation].name << ".";
  if (board[currentLocation].owner == 0) {
    cout << endl << "This building is availible to purchase ($"
         << board[currentLocation].cost << ")."
         << endl << "Would you like to purchase it? (y/n) ";
    cin >> ans;
    if (tolower(ans) == YES) {
      cout << endl << "You have purchased " << board[currentLocation].name
           << ".";
      players[currentPlayer].money -= board[currentLocation].cost;
      board[currentLocation].owner = playerNum; 
    } else {
      cout << endl << "You did not purchase "
           << board[currentLocation].name << ".";
    }
    
    if (players[currentPlayer].money < 0) {
      cout << endl << "You don't have any more money...";
    } else {
      cout << endl << "You have $" << players[currentPlayer].money << ".";
    }
    
    cout << endl << "(Press enter to continue...)";
    cin.ignore();
  } else {
    cout << endl << "This building is owned by " << players[ownerNum].name
         << ".";
    players[currentPlayer].money -= board[currentLocation].rent;
    players[ownerNum].money += board[currentLocation].rent;
    cout << endl << "You owe " << board[currentLocation].rent << ".";

    if (players[currentPlayer].money < 0) {
      cout << endl << "You don't have any more money...";
    } else {
    cout << endl << "You now have $" << players[currentPlayer].money
         << " and " << players[ownerNum].name << " now has $"
         << players[ownerNum].money << "." << endl;
    }
    cout << "(Press enter to continue...)";
    cin.ignore();
  }
}

bool checkForBankrupcy (Player players[], int numPlayers)
{
  for (int i = 0; i < numPlayers; i++) {
    if (players[i].money <= 0) {
      return true;
    }
  }
  return false;
}

void result (Player players[], int numE)
{
  int index;
  int money = -1;
  for (int i = 0; i < numE; i++) {
    if (players[i].money > money) {
      index = i;
      money = players[i].money;
    }
  }
  cout << endl << endl << "The winner is " << players[index].name << " with $"
       << players[index].money << "."; 
  cout << endl << endl;
}

char playAgain ()
{
  char answer;
  cout << endl << endl;
  cout << "Would you like to play again? (y/n): ";
  cin >> answer;
  return answer;
}

void goodbye ()
{
  cout << endl;
  cout << "Thank you so much for playing! Come again soon!";
  cout << endl << endl;
}
  
