#ifndef MODEL_H
#define MODEL_H

#include "quizitem.h"
#include <QDebug>
#include <QVector>



class Model
{
public:
    Model();
    QVector<QuizItem> active_quiz;
    void open_my_profile();
    void edit_active_quiz();
    void choose_active_quiz();


private:

};

#endif // MODEL_H
