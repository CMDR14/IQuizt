#ifndef MODEL_H
#define MODEL_H

#include "quizitem.h"
#include <QDebug>
#include <QVector>
#include "../persistence/persistence.h"
#include "../profile/profile.h"



class Model
{
public:
    Model(Persistence* p);
    ~Model();
    QVector<QuizItem> active_quiz;
    bool load_my_profile(QString prof_name);
    bool create_my_profile(QString prof_name);
    void edit_active_quiz();
    void load_existing_quiz();
    void list_quizzes();


    QVector<NameAndPath> getList_of_quizzes() const;

    Profile *getProfile() const;

private:
    Persistence* p_;
    QVector<NameAndPath> list_of_quizzes;
    Profile* profile_;
};

#endif // MODEL_H
