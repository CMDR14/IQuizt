#include "profile.h"

Profile::Profile(QString const &name, int level, int correct_c, int wrong_c) :
    name_(name),
    level_(level),
    correct_counter(correct_c),
    wrong_counter(wrong_c)
{

}

QString Profile::name() const
{
    return name_;
}

void Profile::setName(const QString &name)
{
    name_ = name;
}

int Profile::getCorrect_counter() const
{
    return correct_counter;
}

void Profile::setCorrect_counter(int value)
{
    correct_counter = value;
    AdjustLevel();
}

int Profile::getLevel() const
{
    return level_;
}

void Profile::setLevel(int level)
{
    level_ = level;
}

int Profile::getWrong_counter() const
{
    return wrong_counter;
}

void Profile::setWrong_counter(int value)
{
    wrong_counter = value;
}

void Profile::AdjustLevel()
{
    if(correct_counter != 0 && correct_counter % 10 == 0)
    {
        ++level_;
    }
}
