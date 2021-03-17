#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include "quizitemselector.h"
#include "../model/quizitem.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);

private:
    QuizItem* q_;
    quizitemselector* qs_;

signals:

};

#endif // MAINWIDGET_H
