#include "mainwidget.h"


MainWidget::MainWidget(QWidget *parent) : QWidget(parent)
{
    model_ = new Model();
    create_menubar();
}

void MainWidget::create_menubar()
{

        QVBoxLayout* boxLayout = new QVBoxLayout(this); // Main layout of widget

        QMenuBar* menu_bar = new QMenuBar();
        menu_bar->addAction("My Profile", this, SLOT(on_my_profile()));
        menu_bar->addAction("Edit Quiz", this, SLOT(on_edit_quiz()));
        menu_bar->addAction("Load Existing Project", this, SLOT(on_load_existing_project()));


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

void MainWidget::on_load_existing_project()
{
    qDebug() << "in on_load_existing_project slot";
    model_->choose_active_quiz();
}
