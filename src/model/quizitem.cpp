#include "quizitem.h"

QString QuizItem::getQuestion() const
{
    return quiz_item_[0];
}

QString QuizItem::getRightAnswer() const
{
    return quiz_item_[1];
}

QString QuizItem::getWrongAnswer1() const
{
    return quiz_item_[2];
}

QString QuizItem::getWrongAnswer2() const
{
    return quiz_item_[3];
}

QString QuizItem::getWrongAnswer3() const
{
    return quiz_item_[4];
}

int QuizItem::getTrys() const
{
    return stat_[0];
}

int QuizItem::getCorrects() const
{
    return stat_[1];
}

void QuizItem::newTry(bool correct)
{
    stat_[0]++;
    stat_[1] = correct ? stat_[1] + 1 : stat_[1];
}

void QuizItem::setQuestion(QString question)
{
    quiz_item_[0] = question;
}

void QuizItem::setRightAnswer(QString right_answer)
{
    quiz_item_[1] = right_answer;
}

void QuizItem::setWrongAnswer1(QString wrong_answer_1)
{
    quiz_item_[2] = wrong_answer_1;
}

void QuizItem::setWrongAnswer2(QString wrong_answer_2)
{
    quiz_item_[3] = wrong_answer_2;
}

void QuizItem::setWrongAnswer3(QString wrong_answer_3)
{
    quiz_item_[4] = wrong_answer_3;
}

void QuizItem::setTrys(int trys)
{
    stat_[0] = trys;
}

void QuizItem::setCorrects(int corrects)
{
    stat_[1] = corrects;
}

QTextStream& operator<<(QTextStream& os, const QuizItem& q)
{
    os << q.getQuestion() << "\n"
       << q.getRightAnswer() << "\n"
       << q.getWrongAnswer1() << "\n"
       << q.getWrongAnswer2() << "\n"
       << q.getWrongAnswer3() << "\n"
       << q.getTrys() << "\t" << q.getCorrects() << "\n";
    return os;
}

QTextStream& operator>>(QTextStream& is, QuizItem& q)
{
    QString question, right, wrong1, wrong2, wrong3;
    int trys, corrects;
    is >> question
       >> right
       >> wrong1
       >> wrong2
       >> wrong3
       >> trys >> corrects;
    q.setQuestion(question);
    q.setRightAnswer(right);
    q.setWrongAnswer1(wrong1);
    q.setWrongAnswer2(wrong2);
    q.setWrongAnswer3(wrong3);
    q.setTrys(trys);
    q.setCorrects(corrects);
    return is;
}
