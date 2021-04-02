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

    bool saveProfile(QVector<QString> &SaveProfileData);
    bool loadProfile(QVector<QString> &LoadProfileData);

private:
    QString path_;

};

#endif // PERSISTENCE_H
