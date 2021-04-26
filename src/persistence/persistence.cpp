#include "persistence.h"

#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>

bool Persistence::get_quiz_sets(QVector<NameAndPath>& quiz_sets) {
    //quiz_sets = new QVector<NameAndPath>();
    //path_ = "";
    //QDir dir(path_);
    QDir dir(QDir::currentPath());
    //qDebug() << QDir::currentPath();
    for (auto &entry : dir.entryList(QDir::Files)) {
        if(entry.split('.').last()!="quiz")
            continue;

        NameAndPath current;
        current.path = entry;

        QFile file(entry);
        if(!file.open(QFile::ReadOnly))
                return false;

        //qDebug() << "Eljut a stream(&file)ig";
        QTextStream stream(&file);
        //qDebug() << entry;
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

bool Persistence::saveProfile(QVector<QString> &SaveProfileData, QString const &profileName)
{
    QFile file(profileName + ".profile"); //vagy .quiz
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

bool Persistence::loadProfile(QVector<QString> &LoadProfileData, QString const &profileName)
{
    QFile file(profileName + ".profile");
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

bool Persistence::createProfile(QString const &profileName, QVector<QString>& profileData)
{
    QFile file(profileName + ".profile");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);

    for(int i = 0; i < profileData.size(); ++i)
    {
        out << profileData[i] << "\n";
    }

    file.close();

    return true;
}
