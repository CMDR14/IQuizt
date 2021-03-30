#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <QTextStream>


class QuizItem
{
public:
    QuizItem(QString question, QString right_answer, QString wrong_answer_1, QString wrong_answer_2, QString wrong_answer_3, int trys = 0, int correct = 0)
        : quiz_item_{ question, right_answer, wrong_answer_1, wrong_answer_2, wrong_answer_3 }, stat_{ trys, correct} {}
    QString getQuestion() const;
    QString getRightAnswer() const;
    QString getWrongAnswer1() const;
    QString getWrongAnswer2() const;
    QString getWrongAnswer3() const;
    int getTrys() const;
    int getCorrects() const;

    void newTry(bool correct);

    void setQuestion(QString question);
    void setRightAnswer(QString right_answer);
    void setWrongAnswer1(QString wrong_answer_1);
    void setWrongAnswer2(QString wrong_answer_2);
    void setWrongAnswer3(QString wrong_answer_3);
    void setTrys(int trys);
    void setCorrects(int corrects);

    friend QTextStream& operator<<(QTextStream& os, const QuizItem& q);
    friend QTextStream& operator>>(QTextStream& is, QuizItem& q);

private:
    QString quiz_item_[5];
    int stat_[2];

};

#endif // QUIZITEM_H
