#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <QString>
#include <QVector>



class Persistence
{
public:
    explicit Persistence() {}

    bool saveQuiz(const QVector<QString> &SaveQuizData);
    bool loadQuiz(QVector<QString> &loadQuizData);

    bool saveProfile(QVector<QString> &SaveProfileData);
    bool loadProfile(QVector<QString> &LoadProfileData);

};

#endif // PERSISTENCE_H
