#ifndef _QUIZZER_HPP
#define _QUIZZER_HPP

#include "Question.hpp"

#define QUESTIONS_IMPLEMENTED 1 // Set this to 1 once you've implemented the questions classes

class TrueFalseQuestion;
class MultipleChoiceQuestion;

class Quizzer
{
public:
    Quizzer();

    void AddTrueFalseQuestion( TrueFalseQuestion* q );
    void AddMultipleChoiceQuestion( MultipleChoiceQuestion* q );

    void Run();

private:
    TrueFalseQuestion* m_tfQuestions[3];
    MultipleChoiceQuestion* m_mcQuestions[3];

    int m_count_tfQuestions;
    int m_count_mcQuestions;
};

#endif
