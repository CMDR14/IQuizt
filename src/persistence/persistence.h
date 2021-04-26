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

    bool get_quiz_sets(QVector<NameAndPath>& quiz_sets);

    bool saveQuiz(const QVector<QuizItem> &SaveQuizData);
    bool loadQuiz(QVector<QuizItem> &loadQuizData);

    bool saveProfile(QVector<QString> &SaveProfileData, QString const &profileName);
    bool loadProfile(QVector<QString> &LoadProfileData, QString const &profileName);

    bool createProfile(QString const &profileName, QVector<QString>& profileData);

private:
    QString path_;

};

#endif // PERSISTENCE_H
