#include "quizitem.h"

std::string QuizItem::getQuestion() const
{
    return qiuz_item_[0];
}

std::string QuizItem::getRightAnswer() const
{
    return qiuz_item_[1];
}

std::string QuizItem::getWrongAnswer1() const
{
    return qiuz_item_[2];
}

std::string QuizItem::getWrongAnswer2() const
{
    return qiuz_item_[3];
}

std::string QuizItem::getWrongAnswer3() const
{
    return qiuz_item_[4];
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

void QuizItem::setQuestion(std::string question)
{
    qiuz_item_[0] = question;
}

void QuizItem::setRightAnswer(std::string right_answer)
{
    qiuz_item_[1] = right_answer;
}

void QuizItem::setWrongAnswer1(std::string wrong_answer_1)
{
    qiuz_item_[2] = wrong_answer_1;
}

void QuizItem::setWrongAnswer2(std::string wrong_answer_2)
{
    qiuz_item_[3] = wrong_answer_2;
}

void QuizItem::setWrongAnswer3(std::string wrong_answer_3)
{
    qiuz_item_[4] = wrong_answer_3;
}

void QuizItem::setTrys(int trys)
{
    stat_[0] = trys;
}

void QuizItem::setCorrects(int corrects)
{
    stat_[1] = corrects;
}

std::ostream& operator<<(std::ostream& os, const QuizItem& q)
{
    os << q.getQuestion() << "\n"
       << q.getRightAnswer() << "\n"
       << q.getWrongAnswer1() << "\n"
       << q.getWrongAnswer2() << "\n"
       << q.getWrongAnswer3() << "\n"
       << q.getTrys() << "\t" << q.getCorrects() << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, QuizItem& q)
{
    std::string question, right, wrong1, wrong2, wrong3;
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
