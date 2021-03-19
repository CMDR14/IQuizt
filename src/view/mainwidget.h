#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "../model/model.h"
#include <QMenuBar>
#include <QVBoxLayout>
#include <QWidget>
#include "quizitemselector.h"
#include "../model/quizitem.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(QWidget *parent = nullptr);


private:
    Model* model_;
    void create_menubar();

signals:

public slots:
   void  on_my_profile();
   void  on_edit_quiz();
   void  on_load_existing_project();

};

#endif // MAINWIDGET_H
