/*
MODIFY THIS FILE
*/

#include "hp2_program.hpp"
#include "cuTEST/Menu.hpp"

#include <iostream>
using namespace std;

char gameBoard[3][3];
int turn;
int playerWins[PLAYER_COUNT];
char playerMarker[PLAYER_COUNT];

/* Main() - Program entry point
 * */
void Program::Main() // DONE
{
    Setup();
    bool done = false;

    while ( !done )
    {
        ClearBoard();
        GameLoop();

        // If we get to this point, it means one of the players
        // has won. We want to see if they want to play again!

        cout << "Play again? \t 1. YES \t 2. NO" << endl;
        int choice = GetValidInput( 1, 2 );
        if ( choice == 2 )  // quit
        {
            done = true;
        }
        // Otherwise we will loop again and
        // another game will start.
    }
}

/* Setup() - 	Should initialize all ELEMENTS of the gameBoard to a space character: ' '
 * 				Set the turn marker to 0
 * 				Set playerWins for both players to 0
 * 				Set playerMarker for each player: 'x' and 'o'.
 * */
void Program::Setup()
{
	turn = 0;
	playerWins[0] = { 0 };
	playerWins[1] = { 0 };
	playerMarker[0] = { 'x' };
	playerMarker[1] = { 'o' };

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			gameBoard[x][y] = ' ';
		}
	}
}

/* ClearBoard() -	Clear the game board of all pieces
 * */
void Program::ClearBoard() // DONE
{
    // Set up game board
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            gameBoard[x][y] = ' ';
        }
    }
}

/* GameLoop() -		Create a game loop that will keep running until the user quits.
 * 					Each cycle of the loop, call DrawStats() and DrawBoard(),
 * 					then have the player choose an x, y coordinate.
 *
 * 					Use the PlaceMarker function to attempt to place the player's
 * 					marker at the given x, y. If successful, then go to the other
 * 					player's turn. (Otherwise, they will have to select again.)
 *
 *
 * */
void Program::GameLoop()
{
	bool gameLoopContinues = true;
	int results = -1;
	int playerXChoiceX = 0;
	int playerXChoiceY = 0;
	int playerOChoiceX = 0;
	int playerOChoiceY = 0;


	while (gameLoopContinues)
	{
		if (turn = 0)
		{
			DrawStats();
			DrawBoard();
			bool placeMarkerX;
			cout << endl << endl
				<< "Please choose a x coordinate for Player x: ";
			cin >> playerXChoiceX;
			cout << "Please choose a y coordinate for Player x: ";
			cin >> playerXChoiceY;
			placeMarkerX = PlaceMarker(playerXChoiceX, playerXChoiceY, playerMarker[0]);
			if (placeMarkerX == false)
			{
				turn = 0;
			}
			else
			{
				turn = 1;
			}
		}
		if (turn = 1)
		{
			DrawStats();
			DrawBoard();
			bool placeMarkerO;
			cout << endl << endl
				<< "Please choose a x coordinate for Player o: ";
			cin >> playerOChoiceX;
			cout << "Please choose a y coordinate for Player o: ";
			cin >> playerOChoiceY;
			placeMarkerO = PlaceMarker(playerOChoiceX, playerOChoiceY, playerMarker[1]);
			if (placeMarkerO == false)
			{
				turn = 1;
			}
			else
			{
				turn = 0;
			}
		}

		 results = CheckForWinner();
		 if (results == 0)
		 {
			 playerWins[0] += 1;
			 gameLoopContinues = false;
		 }
		 else if (results == 1)
		 {
			 playerWins[1] += 1;
			 gameLoopContinues = false;
		 }
		 else
		 {
			 ;
		 }

	}

}

/* GetValidInput( int min, int max ) - Get user to enter their decision.
 * 	While their input is invalid (< min or > max), have them re-enter their selection.
 * 	Return the user's input once valid input has been provided.
 * */
int Program::GetValidInput( int min, int max )
{
    int choice;
	bool loopForChoice = false;

	while (loopForChoice == false)
	{
		cout << endl << "Please input your selection: ";
		cin >> choice;

		if (choice >= min && choice <= max)
		{
			cout << endl << "Your " << choice << "is a valid selection." << endl;
			loopForChoice = true;
		}
		
	}
    return choice; 
}

/* DrawStats() - 	Display game stats, such as how many wins per player, and whose turn it is.
 * */
void Program::DrawStats()
{
	cout << "******************************" << endl; 
	cout << "\tStats" << endl;
	cout << "******************************" << endl;
	cout << endl << "Player 1  (X) has won"
		<< playerMarker[0] << "games. " << endl;
	cout << endl << "Player 2  (O) has won"
		<< playerMarker[1] << "games. " << endl;
	
	if (turn == 0)
	{
		cout << "It is Player 1's turn." << endl << endl;
	}
	else if (turn == 1)
	{
		cout << "It is Player 2's turn."<< endl << endl;
	}	
}

/* DrawBoard() - 	Draw the 2D game board
 * */
void Program::DrawBoard() // Done
{
    cout << "\t";
    for ( int x = 0; x < 3; x++ )
    {
        cout << "\t";
        if ( x != 0 ) { cout << "\t"; }
        cout << x;
    }
    cout << endl;

    for ( int y = 0; y < 3; y++ )
    {
        if ( y != 0 ) { cout << endl << "\t---------------------------------------------------"; }
        cout << endl << y << "\t\t";

        for ( int x = 0; x < 3; x++ )
        {
            if ( x != 0 ) { cout << "\t|\t"; }
            cout << gameBoard[x][y];
        }
    }
    cout << endl << endl;
}

/* GetCurrentPlayerTurn() - Return the value of the *turn* variable.
 * */
int Program::GetCurrentPlayerTurn()
{
	if (turn == 0)
	{
		cout << "It is Player 1's turn." << endl;
		cout << "Thank you!" << endl;
	}
	else if (turn == 1)
	{
		cout << "It is Player 2's turn." << endl;
		cout << "Thank you!" << endl;
	}
    return turn; // temp
}

/* SwapTurn()	- Change to the other player's turn.
 * */
void Program::SwapTurn()
{
	if (turn == 0)
	{
		turn = 1;
	}
	else if (turn == 1)
	{
		turn = 0;
	}
}

/* PlaceMarker( int x, int y, char marker ) - Set the location on
 * 	the game board to a specific marker (will be player's 'x' or 'o'...)
 * 	However, you need to check to see if that spot on the board is available.
 *  If it is available, place the marker there, and return true.
 *  Otherwise, if it is unavailable ('x' or 'o' is already there), return false.
 * */
bool Program::PlaceMarker( int x, int y, char marker )
{
	bool playerInputValid = false;

	if (gameBoard[x][y] == ' ')
	{
		playerInputValid = true;
		gameBoard[x][y] = { marker };
	}
	else
	{
		playerInputValid = false;
	}

    return playerInputValid; 
}

/* CheckForWinner() -	Check the gameBoard for various win-scenarios.
 * 						Return -1 if nobody has a winning move, otherwise
 * 						return 0 for player 0 win, and return 1 for player 1 win.
 * 						( Player 0 should have 'x', Player 1 should have 'o'. )
 *
 * OPTIONS: You can either use if-statements to make an exhaustive
 * list of all possible win combinations (normal points).
 * There should be 8 possible winning moves, per player.
 * (See documentation)
 *
 * OR:
 *
 * Use a more generic approach, where you can use for-loop(s) to iterate
 * through the game board positions and figure out if there is a winner
 * or not. (Extra credit)
 * */
int Program::CheckForWinner()
{
	int winner = -1;
	int sizeOfXInGameBoard = 3;
	int sizeOfYInGameBoard = 3;

		for (int i = 0; i < sizeOfYInGameBoard; i++)
		{
			for (int j = 0; j < sizeOfXInGameBoard; j++)
			{
				gameBoard[j][i];

				if()
			}
		}

	return -1;  // temp
}
