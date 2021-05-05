#ifndef PERSISTENCE_H
#define PERSISTENCE_H

#include <QString>
#include <QVector>
#include "../model/quizitem.h"

/** \brief This struct can store a file's name and path.
 * */
struct NameAndPath {
    QString name;
    QString path;
};

/** \brief This class is used to connect the program and the computer's storage.
 * 
 * \arg Reads stored quiz sets and profiles.
 * \arg Saves quiz sets and profiles.
 * \arg Finds quiz sets.
 * \arg Can create a profile.
 * */
class Persistence
{
public:
    explicit Persistence() {}

    static bool get_quiz_sets(QVector<NameAndPath>& quiz_sets, QString path);

    static bool saveQuiz(const NameAndPath &NamePath, const QVector<QuizItem> &SaveQuizData);
    static bool loadQuiz(NameAndPath &NamePath, QVector<QuizItem*>* &loadQuizData);

    static bool saveProfile(QVector<QString> &SaveProfileData, QString const &profileName);
    static bool loadProfile(QVector<QString> &LoadProfileData, QString const &profileName);

    static bool createProfile(QString const &profileName, QVector<QString>& profileData);

    static bool scan_for_profile(QString &current_profile);

};

#endif // PERSISTENCE_H
