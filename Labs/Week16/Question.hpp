#ifndef _QUESTION_HPP
#define _QUESTION_HPP

#include <string>
using namespace std;

// class declaration, function declarations, variable declarations

class QuestionBase
{
	protected:
		string m_questionText;

	public:
		void Display();

		void SetQuestionText(const string& text);
};

class TrueFalseQuestion : public QuestionBase
{
	private:
		string m_correctAnswer;

	public:
		void Display();

		void SetCorrectAnswer(const string& correctAnswer);

		bool CheckAnswer(const string& userAnswer);
};

class MultipleChoiceQuestion : public QuestionBase
{
	private: 
		int m_correctAnswer;
		string m_answers[4];

	public:
		void Display();

		void SetCorrectAnswer(int correctAnswer);

		bool CheckAnswer(int userAnswer);

		void SetAnswerChoices(const string& a0, const string& a1, const string& a2, const string& a3);
};



#endif
