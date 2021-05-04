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
    void load_existing_quiz(NameAndPath nap);
    void list_quizzes();


    QVector<NameAndPath> getList_of_quizzes() const;

    Profile *getProfile() const;

    void set_active_set_name_and_path(NameAndPath nap){quiz_set_name_and_path_=nap;}
    NameAndPath get_active_set_name_and_path(){return quiz_set_name_and_path_;}

    QVector<QuizItem*>* get_active_quiz_set_() {return quiz_set_;}

private:
    Persistence* p_ = nullptr;
    QVector<NameAndPath> list_of_quizzes;
    Profile* profile_;
    NameAndPath quiz_set_name_and_path_;
    QVector<QuizItem*> *quiz_set_;
};

#endif // MODEL_H
