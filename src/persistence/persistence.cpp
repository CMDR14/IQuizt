#include "persistence.h"

#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QTextStream>

bool Persistence::get_quiz_sets(QVector<NameAndPath>& quiz_sets) {
    //quiz_sets = QVector<NameAndPath>();
    QDir dir(path_);
    for (auto entry : dir.entryList(QDir::Files)) {
        NameAndPath current;
        current.path = entry;

        QFile file(entry);
        if(!file.open(QFile::ReadOnly))
                return false;

        QTextStream stream(&file);
        current.name = stream.readLine();

        file.close();
        quiz_sets.append(current);
    }
    return true;
}

bool Persistence::saveQuiz(const QVector<QuizItem> &SaveQuizData)
{
    QFile file("valaminev.sav"); //vagy .quiz, ha a savequizdataban tároljuk akkor annak mondjuk a 0. indexű eleme
    if(!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);

    for(int i = 0; i < SaveQuizData.size(); ++i)
    {
        //stream << SaveQuizData[i] << Qt::endl;
        stream << SaveQuizData[i] << "\n";
    }

    file.close();

    return true;
}

bool Persistence::loadQuiz(QVector<QuizItem> &loadQuizData)
{
    QFile file("valaminev.sav");
    if(!file.open(QFile::ReadOnly))
            return false;

    QTextStream stream(&file);
    loadQuizData = QVector<QuizItem>();
    QuizItem tmp("", "", "", "", "");
    while( !stream.atEnd() ) {
        stream >> tmp;
        loadQuizData.append(tmp);
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
        //stream << SaveProfileData[i] << Qt::endl;
        stream << SaveProfileData[i] << "\n";
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
