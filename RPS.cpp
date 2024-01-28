#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

// Function to generate a random move from rock, paper, and scissor
char get_Computer_Move()
{
      int move;
      // Generating a random number and storing it in 'move' variable
      srand(time(NULL));
      move = rand() % 3;

      // Nested if-else for moves
      if (move == 0)
      {
            cout<<"computer move: p"<<endl;
            return 'p';
      }
      else if (move == 1)
      {
            cout<<"computer move: s"<<endl;
            return 's';
      }
      else
      {
            cout<<"computer move: r"<<endl;
            return 'r';
      }
}


// Function to get player move
char get_Player_Move()
{
      // Local variable to store input
      char player_Move;
      cout << "Enter your move (r, p, or s): ";
      cin >> player_Move;

      // Validate if the move is correct
      if (player_Move == 'r' || player_Move == 'p' || player_Move == 's')
      {
            return player_Move;
      }
      else
      {
            cout << "Invalid move! Please enter 'r', 'p', or 's': ";
            // Recursion
            return get_Player_Move();
      }
}


// Function to return the result of the game
int result(char player_Move, char computer_Move)
{
      // It's a tie
      if (player_Move == computer_Move)
      {
            cout << "It's a tie!" << endl;
            return 0;
      }
      // Player wins
      else if ((player_Move == 's' && computer_Move == 'p') || (player_Move == 'p' && computer_Move == 'r') || (player_Move == 'r' && computer_Move == 's'))
      {
            cout << "Player wins!" << endl;
            return 1;
      }
      // Computer wins
      else
      {
            cout << "Computer wins!" << endl;
            return -1;
      }
}


// Main function
int main()
{
      cout << "Welcome to stone, paper, and scissor game!" << endl;
      cout << "Enter 'r' for ROCK, 'p' for PAPER, and 's' for SCISSOR: ";
      // This variable will store the player move returned from the get player move function
      char player_Move = get_Player_Move(); // Calling the player move function
      // This variable will store the computer move returned from the get computer move function
      char computer_Move = get_Computer_Move(); // Calling the computer move function
      // Get result
      int gameResult = result(player_Move, computer_Move);
      return 0;
}
