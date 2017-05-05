#include <iostream>
using namespace std;

#include "Quizzer.hpp"

// In Quizzer, set QUESTIONS_IMPLEMENTED to 1
// once you're done implementing the Questions classes.

int main()
{
    Quizzer quizzer;

	#if QUESTIONS_IMPLEMENTED
    TrueFalseQuestion tf1, tf2, tf3;
    tf1.SetQuestionText( "Static arrays can be resized at run-time." );
    tf1.SetCorrectAnswer( "false" );
    quizzer.AddTrueFalseQuestion( &tf1 );

    tf2.SetQuestionText( "Classes can contain member variables and functions." );
    tf2.SetCorrectAnswer( "true" );
    quizzer.AddTrueFalseQuestion( &tf2 );

    tf3.SetQuestionText( "If you de-reference a nullptr, your program will crash." );
    tf3.SetCorrectAnswer( "true" );
    quizzer.AddTrueFalseQuestion( &tf3 );

    MultipleChoiceQuestion mc1, mc2, mc3;
    mc1.SetQuestionText( "Which of the following is the address-of operator?" );
    mc1.SetAnswerChoices( "&", "*", "->", "::" );
    mc1.SetCorrectAnswer( 0 );
    quizzer.AddMultipleChoiceQuestion( &mc1 );

    mc2.SetQuestionText( "Dynamic variables are allocated on the..." );
    mc2.SetAnswerChoices( "stack", "heap", "queue", "array" );
    mc2.SetCorrectAnswer( 1 );
    quizzer.AddMultipleChoiceQuestion( &mc2 );

    mc3.SetQuestionText( "When a value is being passed into a function call, it is known as a..." );
    mc3.SetAnswerChoices( "parameter", "structure", "reference", "argument" );
    mc3.SetCorrectAnswer( 3 );
    quizzer.AddMultipleChoiceQuestion( &mc3 );

    quizzer.Run();
	#endif

    return 0;
}
