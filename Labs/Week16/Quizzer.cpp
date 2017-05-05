#include "Quizzer.hpp"

#include <iostream>
#include <string>
using namespace std;

Quizzer::Quizzer()
{
    m_count_mcQuestions = 0;
    m_count_tfQuestions = 0;
}

void Quizzer::AddTrueFalseQuestion( TrueFalseQuestion* q )
{
    if ( m_count_tfQuestions >= 3 ) { return; }
    m_tfQuestions[ m_count_tfQuestions++ ] = q;
}

void Quizzer::AddMultipleChoiceQuestion( MultipleChoiceQuestion* q )
{
    if ( m_count_mcQuestions >= 3 ) { return; }
    m_mcQuestions[ m_count_mcQuestions++ ] = q;
}

void Quizzer::Run()
{
	#if QUESTIONS_IMPLEMENTED
	int totalQuestions = m_count_tfQuestions + m_count_mcQuestions;
	int totalRight = 0;

	for ( int i = 0; i < m_count_tfQuestions; i++ )
	{
		m_tfQuestions[ i ]->Display();

		string answer;
		cin >> answer;

		bool correct = m_tfQuestions[i]->CheckAnswer( answer );

		if ( correct )
		{
			cout << "CORRECT!" << endl;
			totalRight++;
		}
		else
		{
			cout << "INCORRECT!" << endl;
		}
	}

	for ( int i = 0; i < m_count_mcQuestions; i++ )
	{
		m_mcQuestions[ i ]->Display();

		int answer;
		cin >> answer;

		bool correct = m_mcQuestions[i]->CheckAnswer( answer );

		if ( correct )
		{
			cout << "CORRECT!" << endl;
			totalRight++;
		}
		else
		{
			cout << "INCORRECT!" << endl;
		}
	}

	cout << endl << endl;
	cout << "Final Score: " << totalRight << " out of " << totalQuestions << endl;
	#endif
}
