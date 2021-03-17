#include "mainwidget.h"


MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    qDebug() << "MainWidget constr";
    q_ = new QuizItem("Hány éves a kapitány?", "21", "11", "12", "13");

    qs_ = new quizitemselector(q_, this);


}
