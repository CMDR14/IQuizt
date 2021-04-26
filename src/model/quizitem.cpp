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


/** \brief A new try with this item  
 * 
 * User tried to answer this quiz question and the item can store this in it's own *statistic*.  
 * \param correct is the boolean to specify if the user answered the question correctly.  
 * */
void QuizItem::newTry(bool correct)
{
    stat_[0]++;
    stat_[1] = correct ? stat_[1] + 1 : stat_[1];
}

void QuizItem::setQuestion(QString const &question)
{
    quiz_item_[0] = question;
}

void QuizItem::setRightAnswer(QString const &right_answer)
{
    quiz_item_[1] = right_answer;
}

void QuizItem::setWrongAnswer1(QString const &wrong_answer_1)
{
    quiz_item_[2] = wrong_answer_1;
}

void QuizItem::setWrongAnswer2(QString const &wrong_answer_2)
{
    quiz_item_[3] = wrong_answer_2;
}

void QuizItem::setWrongAnswer3(QString const &wrong_answer_3)
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

/** \brief Operator overload to write a QuizItem to a QTextStream  
 * 
 * With this operator you can easily write a QuizItem to a QTextStream.  
 * Sysntax:  
 * ~~~~~~~~~~~~~~~
 * QTestStream ts;  
 * QuizItem qi;  
 * ts << qi;  
 * ~~~~~~~~~~~~~~~
 * \param os a short name for outstream. This is the reference of a QTextStream to write in.  
 * \param q a short QuizItem. This constant reference to a QuizItem which will be writen in the QTextStream  
 * \returns QTextSream which helps to use it like this: `c++ os << something << otherthing;`  
 * \see QTextStream  
 * */
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

/** \brief Operator overload to read a QuizItem from a QTextStream  
 * 
 * With this operator you can easily read a QuizItem from a QTextStream.  
 * Sysntax:  
 * ~~~~~~~~~~~~~~~
 * QTestStream ts;  
 * QuizItem qi;  
 * ts >> qi;  
 * ~~~~~~~~~~~~~~~
 * \param is a short name for instream. This is the reference of a QTextStream to read from.  
 * \param q a short QuizItem. This reference to a QuizItem which will be filled with the read information from the QTextStream  
 * \returns QTextSream which helps to use it like this: `c++ os >> something >> otherthing;`  
 * \see QTextStream  
 * */
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
