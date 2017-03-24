/*
DON'T MODIFY THIS FILE
*/

#ifndef _PROGRAM_HPP	// Don't allow duplicates
#define _PROGRAM_HPP	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std;

const int PLAYER_COUNT = 2;

class Program
{
public:
    void Main();

    void Setup();
    void ClearBoard();
    void GameLoop();
    void DrawBoard();
    void DrawStats();
    int GetValidInput( int min, int max );

    int GetCurrentPlayerTurn();
    void SwapTurn();

    bool PlaceMarker( int x, int y, char marker );
    int CheckForWinner();

private:
    char gameBoard[3][3];
    int turn;
    int playerWins[PLAYER_COUNT];
    int playerMarker[PLAYER_COUNT];

    friend class Tester;
};

#endif
