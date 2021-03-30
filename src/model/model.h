#ifndef MODEL_H
#define MODEL_H

#include "quizitem.h"
#include <QDebug>
#include <QVector>
#include "persistence/persistence.h"



class Model
{
public:
    Model(Persistence* p);
    ~Model();
    QVector<QuizItem> active_quiz;
    void open_my_profile();
    void edit_active_quiz();
    void load_existing_quiz();
    void list_quizzes();


    QVector<NameAndPath> *getList_of_quizzes() const;

private:
    Persistence* p_;
    QVector<NameAndPath> *list_of_quizzes;
};

#endif // MODEL_H
