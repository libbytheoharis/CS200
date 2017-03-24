/*
DON'T MODIFY THIS FILE

If this file doesn't compile for you in Code::Blocks,
go to the Build Options (Project > Build options...)
and select the flag for
"Have g++ follow the C++11 ISO C++ language standard"
*/

#ifndef _TESTER_HPP	// Don't allow duplicates
#define _TESTER_HPP	// Don't allow duplicates

#include <iostream>
#include <string>
using namespace std;

#include "cuTEST/TesterBase.hpp"
#include "cuTEST/Menu.hpp"
#include "cuTEST/StringUtil.hpp"

#include "hp2_program.hpp"

class Tester : public TesterBase
{
public:
	Tester()
	{
		AddTest(TestListItem("Setup()", bind(&Tester::Setup, this)));
		AddTest(TestListItem("PlaceMarker()", bind(&Tester::PlaceMarker, this)));
		AddTest(TestListItem("GetCurrentPlayerTurn()", bind(&Tester::GetCurrentPlayerTurn, this)));
		AddTest(TestListItem("SwapTurn()", bind(&Tester::SwapTurn, this)));
		AddTest(TestListItem("CheckForWinner()", bind(&Tester::CheckForWinner, this)));
	}

private:
	int Setup();
	int PlaceMarker();
	int GetCurrentPlayerTurn();
	int SwapTurn();
	int CheckForWinner();
};

int Tester::Setup()
{
    InitTest( "Setup()", { "Setup()" } );

    StartTest( "Test to make sure Setup() initializes the game board, turn counter, \n playerWins array, and playerMarker array" );

    Program p;
    p.Setup();

    bool boardIsEmpty = true;
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            if ( p.gameBoard[x][y] != ' ' )
            {
                boardIsEmpty = false;
            }
        }
    }

    if ( p.turn != 0
        || p.playerWins[0] != 0
        || p.playerWins[1] != 0 )
    {
        string message = "Expected values: ";
        message += "\n\t turn: 0, playerWins[0]: 0, playerWins[1]: 0";
        message += "Actual values: ";
        message += "\n\t turn: " + StringUtil::ToString( p.turn )
            + ", playerWins[0]: " + StringUtil::ToString( p.playerWins[0] )
            + ", playerWins[1]: " + StringUtil::ToString( p.playerWins[1] );
        ReportFailure( message );
        TestFail();
    }
    else if ( !boardIsEmpty )
    {
        string message = "Expected game board to contain empty char-literals, but it is not.";
        message += "\n\t Values: ";
        for ( int y = 0; y < 3; y++ )
        {
            for ( int x = 0; x < 3; x++ )
            {
                if ( ! ( x == 0 && y == 0 ) ) { message += ", "; }
                message += "\"";
                message += p.gameBoard[x][y];
                message += "\"";
            }
        }

        ReportFailure( message );
        TestFail();
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::PlaceMarker()
{
    /*
    * Check that placement to an empty cell updates the cell with a new char and returns true.
    * Check that placement to an occupied cell changes nothing and returns false.
    */

    InitTest( "PlaceMarker()", { "PlaceMarker()" } );

    Program p;

    // First placement tests
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            StartTest( "Test to make sure PlaceMarker() will update the gameBoard at the proper \n location and with the proper character" );

            // Clear board
            p.gameBoard[0][0] = p.gameBoard[0][1] = p.gameBoard[0][2]
                = p.gameBoard[1][0] = p.gameBoard[1][1] = p.gameBoard[1][2]
                = p.gameBoard[2][0] = p.gameBoard[2][1] = p.gameBoard[2][2]
                = ' ';

            char val = ( x*y % 2 == 0 ) ? 'x' : 'o';
            bool returnVal;

            // Placement
            returnVal = p.PlaceMarker( x, y, val );

            // Check
            if ( p.gameBoard[x][y] != val )
            {
                string message = "Tried to set board at ("
                    + StringUtil::ToString( x )
                    + ", "
                    + StringUtil::ToString( y )
                    + ") to '" +
                    val
                    + "', but instead it is '";
                message += p.gameBoard[0][0];
                message += "'";
                ReportFailure( message );
                TestFail();
            }
            else if ( returnVal == false )
            {
                string message = "Tried to set board at ("
                    + StringUtil::ToString( x )
                    + ", "
                    + StringUtil::ToString( y )
                    + ") to '" +
                    val
                    + ". Expected return value to be true, but it was false.";
                ReportFailure( message );
                TestFail();
            }
            else
            {
                TestPass();
            }

        }
    }

    // Fill board
    p.gameBoard[0][0] = p.gameBoard[0][1] = p.gameBoard[0][2]
        = p.gameBoard[1][0] = p.gameBoard[1][1] = p.gameBoard[1][2]
        = p.gameBoard[2][0] = p.gameBoard[2][1] = p.gameBoard[2][2]
        = '?';

    // Check placing to already full spot
    for ( int y = 0; y < 3; y++ )
    {
        for ( int x = 0; x < 3; x++ )
        {
            StartTest( "Test to make sure PlaceMarker() will NOT update the gameBoard if \n the location is already taken" );

            char newValue;
            char oldValue;
            bool returnVal;

            // Placement
            oldValue = p.gameBoard[x][y];
            returnVal = p.PlaceMarker( x, y, '!' );
            newValue = p.gameBoard[x][y];

            // Check
            if ( newValue != oldValue )
            {
                string message = "Tried to overwrite value at ("
                    + StringUtil::ToString( x )
                    + ", "
                    + StringUtil::ToString( y )
                    + "), which should have returned FALSE without changes, but the value was changed!";
                ReportFailure( message );
                TestFail();
            }
            else if ( returnVal == true )
            {
                string message = "Tried to overwrite value at ("
                    + StringUtil::ToString( x )
                    + ", "
                    + StringUtil::ToString( y )
                    + "), which should have returned FALSE, but it returned TRUE!";
                ReportFailure( message );
                TestFail();
            }
            else
            {
                TestPass();
            }

        }
    }

    DisplayScore();
    return TestResult();
}

int Tester::GetCurrentPlayerTurn()
{
    InitTest( "GetCurrentPlayerTurn()", {} );

    Program p;
    p.turn = 0;

    StartTest( "Test to make sure function returns correct value" );
    if ( p.GetCurrentPlayerTurn() != 0 )
    {
        string message = "Assigned 0 to the turn variable, but instead "
            + StringUtil::ToString( p.GetCurrentPlayerTurn() ) + " was returned!";
        ReportFailure( message );
        TestFail();
    }
    else
    {
        TestPass();
    }


    p.turn = 1;

    StartTest( "Test to make sure function returns correct value" );
    if ( p.GetCurrentPlayerTurn() != 1 )
    {
        string message = "Assigned 1 to the turn variable, but instead "
            + StringUtil::ToString( p.GetCurrentPlayerTurn() ) + " was returned!";
        ReportFailure( message );
        TestFail();
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::SwapTurn()
{
    InitTest( "SwapTurn()", { "SwapTurn()" } );

    Program p;

    StartTest( "Check to make sure turn is changed to the correct player" );
    p.turn = 0;
    p.SwapTurn();

    if ( p.turn != 1 )
    {
        string message = "Tried to swap turn from 0 to 1 but "
            + StringUtil::ToString( p.turn ) + " was returned!";
        ReportFailure( message );
        TestFail();
    }
    else
    {
        TestPass();
    }

    StartTest( "Check to make sure turn is changed to the correct player" );
    p.turn = 1;
    p.SwapTurn();

    if ( p.turn != 0 )
    {
        string message = "Tried to swap turn from 1 to 0 but "
            + StringUtil::ToString( p.turn ) + " was returned!";
        ReportFailure( message );
        TestFail();
    }
    else
    {
        TestPass();
    }

    DisplayScore();
    return TestResult();
}

int Tester::CheckForWinner()
{
    /*
        Check all possible combinations to win
        Check for combinations for each player
        Check for no win as well
    */

    InitTest( "CheckForWinner()", {} );

    Program p;

    char playerChars[2] = { 'x', 'o' };

	for (int c = 0; c < 2; c++)
	{
		string label = "Test 1 "; label += playerChars[c]; label += ": ";

		// Test 1
		StartTest(label + " Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[0][1] = p.gameBoard[0][2] = playerChars[c];
		p.gameBoard[1][0] = p.gameBoard[1][1] = p.gameBoard[1][2] = ' ';
		p.gameBoard[2][0] = p.gameBoard[2][1] = p.gameBoard[2][2] = ' ';

		int result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}

		// Test 2
		label = "Test 2 "; label += playerChars[c]; label += ": ";

		StartTest(label + "Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[0][1] = p.gameBoard[0][2] = ' ';
		p.gameBoard[1][0] = p.gameBoard[1][1] = p.gameBoard[1][2] = playerChars[c];
		p.gameBoard[2][0] = p.gameBoard[2][1] = p.gameBoard[2][2] = ' ';

		result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(message);
			p.DrawBoard();
			TestFail();
		}

		// Test 3
		label = "Test 3 "; label += playerChars[c]; label += ": ";

		StartTest(label + "Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[0][1] = p.gameBoard[0][2] = ' ';
		p.gameBoard[1][0] = p.gameBoard[1][1] = p.gameBoard[1][2] = ' ';
		p.gameBoard[2][0] = p.gameBoard[2][1] = p.gameBoard[2][2] = playerChars[c];

		result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}

		// Test 4
		label = "Test 4 "; label += playerChars[c]; label += ": ";

		StartTest(label + "Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[1][0] = p.gameBoard[2][0] = playerChars[c];
		p.gameBoard[0][1] = p.gameBoard[1][1] = p.gameBoard[2][1] = ' ';
		p.gameBoard[0][2] = p.gameBoard[1][2] = p.gameBoard[2][2] = ' ';

		result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}

		// Test 5
		label = "Test 5 "; label += playerChars[c]; label += ": ";

		StartTest(label + "Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[1][0] = p.gameBoard[2][0] = ' ';
		p.gameBoard[0][1] = p.gameBoard[1][1] = p.gameBoard[2][1] = playerChars[c];
		p.gameBoard[0][2] = p.gameBoard[1][2] = p.gameBoard[2][2] = ' ';

		result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}

		// Test 6
		label = "Test 6 "; label += playerChars[c]; label += ": ";

		StartTest(label + "Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[1][0] = p.gameBoard[2][0] = ' ';
		p.gameBoard[0][1] = p.gameBoard[1][1] = p.gameBoard[2][1] = ' ';
		p.gameBoard[0][2] = p.gameBoard[1][2] = p.gameBoard[2][2] = playerChars[c];

		result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}

		// Test 7
		label = "Test 7 "; label += playerChars[c]; label += ": ";

		StartTest(label + "Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[1][0] = p.gameBoard[2][0] = ' ';
		p.gameBoard[0][1] = p.gameBoard[1][1] = p.gameBoard[2][1] = ' ';
		p.gameBoard[0][2] = p.gameBoard[1][2] = p.gameBoard[2][2] = ' ';

		p.gameBoard[0][0] = p.gameBoard[1][1] = p.gameBoard[2][2] = playerChars[c];

		result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}

		// Test 8
		label = "Test 8 "; label += playerChars[c]; label += ": ";

		StartTest(label + "Check to see if winning combinations result in a win result return.");
		p.gameBoard[0][0] = p.gameBoard[1][0] = p.gameBoard[2][0] = ' ';
		p.gameBoard[0][1] = p.gameBoard[1][1] = p.gameBoard[2][1] = ' ';
		p.gameBoard[0][2] = p.gameBoard[1][2] = p.gameBoard[2][2] = ' ';

		p.gameBoard[2][0] = p.gameBoard[1][1] = p.gameBoard[0][2] = playerChars[c];

		result = p.CheckForWinner();

		if (result == -1)
		{
			string message = "Set up a winning board, but no winner (-1) was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}
		else if (result == c)
		{
			TestPass();
		}
		else
		{
			string message = "Set up a winning board, but the wrong player (" + StringUtil::ToString(result) + ") was returned!";
			ReportFailure(label + message);
			p.DrawBoard();
			TestFail();
		}


	}



    DisplayScore();
    return TestResult();
}

#endif
