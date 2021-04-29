#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <QString>
#include <QVector>
#include "../model/quizitem.h"

struct NameAndPath {
    QString name;
    QString path;
};

class Persistence
{
public:
    explicit Persistence() {}

    static bool get_quiz_sets(QVector<NameAndPath>& quiz_sets);

    static bool saveQuiz(const QVector<QuizItem> &SaveQuizData);
    bool loadQuiz(QVector<QuizItem> &loadQuizData);

    static bool saveProfile(QVector<QString> &SaveProfileData, QString const &profileName);
    static bool loadProfile(QVector<QString> &LoadProfileData, QString const &profileName);

    static bool createProfile(QString const &profileName, QVector<QString>& profileData);

};

#endif // PERSISTENCE_H
