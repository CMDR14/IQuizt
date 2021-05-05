#ifndef MODEL_H
#define MODEL_H

#include "quizitem.h"
#include <QDebug>
#include <QVector>
#include "../persistence/persistence.h"
#include "../profile/profile.h"


/** \brief The business logic of the quiz game.
 * */
class Model
{
public:
    explicit Model(Persistence* p);
    Model(const Model &m) = delete; //copy constructor
    Model& operator=(const Model &other); //overload

    ~Model();
    bool load_my_profile(QString prof_name);
    bool create_my_profile(QString prof_name);
    bool scan_for_profile(QString &current_profile);
    void edit_active_quiz();
    static void load_existing_quiz();
    void list_quizzes();


    QVector<NameAndPath> getList_of_quizzes() const;

    Profile *getProfile() const;
    QString getDirPath() const;
    void setDirPath(const QString& path);

private:
    QString dir_path_;
    Persistence* p_ = nullptr;
    QVector<NameAndPath> list_of_quizzes;
    Profile* profile_;
    QVector<QuizItem> active_quiz;
};

#endif // MODEL_H
