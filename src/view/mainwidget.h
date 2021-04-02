#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "../model/model.h"
#include <QWidget>
#include <QListWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include "quizitemselector.h"
#include "../model/quizitem.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(Model *model, QWidget *parent = nullptr);


private:
    Model* model_;
    void create_menubar();
    Persistence* p_;
    QVBoxLayout* VBoxLayout_;
    QListWidget* list_;

signals:

public slots:
   void  on_my_profile();
   void  on_edit_quiz();

};

#endif // MAINWIDGET_H
