#include "persistence.h"

#include <QFileInfo>
#include <QFile>
#include <QTextStream>



bool Persistence::saveQuiz(const QVector<QString> &SaveQuizData)
{
    QFile file("valaminev.sav"); //vagy .quiz, ha a savequizdataban tároljuk akkor annak mondjuk a 0. indexű eleme
    if(!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);

    for(int i = 0; i < SaveQuizData.size(); ++i)
    {
        stream << SaveQuizData[i] << Qt::endl;
    }

    file.close();

    return true;
}

bool Persistence::loadQuiz(QVector<QString> &loadQuizData)
{
    QFile file("valaminev.sav");
    if(!file.open(QFile::ReadOnly))
            return false;

    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        loadQuizData.append(stream.readLine());
    }

    file.close();

    return true;
}

bool Persistence::saveProfile(QVector<QString> &SaveProfileData)
{
    QFile file("valaminev.profile"); //vagy .quiz
    if(!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);

    for(int i = 0; i < SaveProfileData.size(); ++i)
    {
        stream << SaveProfileData[i] << Qt::endl;
    }

    file.close();

    return true;
}

bool Persistence::loadProfile(QVector<QString> &LoadProfileData)
{
    QFile file("valaminev.profile");
    if(!file.open(QFile::ReadOnly))
            return false;

    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        LoadProfileData.append(stream.readLine());
    }

    file.close();

    return true;
}
