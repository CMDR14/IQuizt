#include "mainwidget.h"
#include "../persistence/persistence.h"
#include <QDebug>


MainWidget::MainWidget(Model* model, QWidget *parent) : QWidget(parent)
{
    model_ = model;
    VBoxLayout_ = new QVBoxLayout();
    create_menubar();
    list_ = new QListWidget();
    list_->setVisible(false);
    VBoxLayout_->addWidget(list_);
    this->setFixedSize(600,600);
}

void MainWidget::create_menubar()
{

        //QVBoxLayout* boxLayout = new QVBoxLayout(this); // Main layout of widget
        this->setLayout(VBoxLayout_);

        QMenuBar* menu_bar = new QMenuBar();
        /*menu_bar->addAction("My Profile", this, SLOT(on_my_profile()));
        menu_bar->addAction("Edit Quiz", this, SLOT(on_edit_quiz()));
        menu_bar->addAction("Load Existing Quizzes", this, SLOT(on_load_existing_project()));
        */

        menu_bar->addAction("My Profile");
        menu_bar->addAction("Edit Quiz");
        auto *load_quiz_clicked = menu_bar->addAction("Load Existing Quizzes");
        connect(load_quiz_clicked, &QAction::triggered,this,[=]()
        {
            list_->clear();
            qDebug() << "load_quiz-clicked";
            list_->setVisible(true);
            model_->list_quizzes();
            qDebug() << "quizzes loaded";
            QVector<NameAndPath>* tmp = model_->getList_of_quizzes();
            for(int i = 0; i < tmp->size(); ++i)
            {

                list_->addItem(tmp->at(i).name);
            }

        });

        menu_bar->setNativeMenuBar(false);
        menu_bar->show();
        this->layout()->setMenuBar(menu_bar);

}

void MainWidget::on_my_profile()
{
    qDebug() << "in on_my_profile slot";
    model_->open_my_profile();
}

void MainWidget::on_edit_quiz()
{
    qDebug() << "in on_edit_quiz slot";
    model_->edit_active_quiz();
}
/*
void MainWidget::on_load_existing_project()
{
    //qDebug() << "in on_load_existing_project slot";
    model_->load_existing_quiz();
}
*/
