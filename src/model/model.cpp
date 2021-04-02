#include "model.h"
#include <QDebug>

Model::Model(Persistence* p)
{
    p_ = p;
    //QVector<NameAndPath> list_of_quizzes;
    QVector<NameAndPath> *list_of_quizzes = new QVector<NameAndPath>();

}

Model::~Model()
{
    delete list_of_quizzes;
}

void Model::open_my_profile()
{
    qDebug() << "Model::open_my_profile";
}

void Model::edit_active_quiz()
{
    qDebug() << "Model::edit_active_quiz(";
}

void Model::load_existing_quiz()
{
    //qDebug() << "Model::load_existing_quiz";

}

void Model::list_quizzes()
{
    qDebug() << "list quizzes func";
    list_of_quizzes = new QVector<NameAndPath>();
    qDebug() << "list quizzes func2";
    if(!(p_->get_quiz_sets(*list_of_quizzes)))
    {
        qDebug() << "Quiz loading unsuccesful!";
        return;
    }

    qDebug() << "Quiz loading succesful!";
}

QVector<NameAndPath> *Model::getList_of_quizzes() const
{
    return list_of_quizzes;
}


