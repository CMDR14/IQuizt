#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <QTextStream>

/** \brief This class stores one question and it's answers for a quiz.  
 * 
 * This is one part of the quiz storing system. It contains a question, the right answer, and three wrong answers.  
 * Has methods to get and set these members.  
 * This also stores some statistics and member functions for these.  
 * */
class QuizItem
{
    friend class QuizItemEditorTest;

public:
    QuizItem(QString question = "", QString right_answer = "", QString wrong_answer_1 = "", QString wrong_answer_2 = "", QString wrong_answer_3 = "", int trys = 0, int correct = 0)
        : quiz_item_{ question, right_answer, wrong_answer_1, wrong_answer_2, wrong_answer_3 }, stat_{ trys, correct} {}
    QString getQuestion() const;
    QString getRightAnswer() const;
    QString getWrongAnswer1() const;
    QString getWrongAnswer2() const;
    QString getWrongAnswer3() const;
    int getTrys() const;
    int getCorrects() const;

    void newTry(bool correct);

    void setQuestion(QString const &question);
    void setRightAnswer(QString const &right_answer);
    void setWrongAnswer1(QString const &wrong_answer_1);
    void setWrongAnswer2(QString const &wrong_answer_2);
    void setWrongAnswer3(QString const &wrong_answer_3);
    void setTrys(int trys);
    void setCorrects(int corrects);

    friend QTextStream& operator<<(QTextStream& os, const QuizItem& q);
    friend QTextStream& operator>>(QTextStream& is, QuizItem& q);

private:
    ///This array stores all the string parts of the class, like the question and the answers.  
    QString quiz_item_[5];

    ///This array stores the statistic numbers, like count of tries and count of correct answers.  
    int stat_[2];

};

#endif // QUIZITEM_H
