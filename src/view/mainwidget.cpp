#include "mainwidget.h"
#include "../persistence/persistence.h"
#include <QDebug>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>


MainWidget::MainWidget(Model *model, QWidget *parent) : QWidget(parent)
{
    model_ = model;
    VBoxLayout_ = new QVBoxLayout();
    create_menubar();
    list_ = new QListWidget();
    list_->setVisible(false);
    VBoxLayout_->addWidget(list_);
    widgets_.append(list_);
    this->setFixedSize(600,600);
    dialog_ = new profile_creation_dialog();

}

void MainWidget::create_menubar()
{
        QMenuBar* menu_bar = new QMenuBar();
        this->setLayout(VBoxLayout_);

        bool profile_exists = scan_for_profile();
        if(profile_exists)
        {
            auto *load_profile_clicked = menu_bar->addAction("Load my Profile");
            connect(load_profile_clicked, &QAction::triggered, this, [=]()
            {
                my_profile_clicked();
            });
        }
        else
        {
            auto *create_profile_clicked = menu_bar->addAction("Create my Profile");
            connect(create_profile_clicked, &QAction::triggered, this, [=]()
            {
                create_profile();
                menu_bar->removeAction(create_profile_clicked);
                auto *load_profile_clicked = menu_bar->addAction("Load my profile");
                connect(load_profile_clicked, &QAction::triggered, this, [=]()
                {
                    my_profile_clicked();
                });
            });
        }


        auto *edit_quiz_clicked = menu_bar->addAction("Edit a quiz");
        connect(edit_quiz_clicked, &QAction::triggered, this, [=]()
        {
            qDebug() << "Edit quiz clicked";
        });

        auto *load_quiz_clicked = menu_bar->addAction("Load Existing Quizzes");
        connect(load_quiz_clicked, &QAction::triggered, this, [=]()
        {
            list_quizzes_clicked();
        });

        menu_bar->setNativeMenuBar(false);
        menu_bar->show();
        this->layout()->setMenuBar(menu_bar);

        menu_bar->setFocus();
}

void MainWidget::list_quizzes_clicked()
{
    list_->clear();
    list_->setVisible(true);
    model_->list_quizzes();
    QVector<NameAndPath> tmp = model_->getList_of_quizzes();
    for(int i = 0; i < tmp.size(); ++i)
    {

        list_->addItem(tmp.at(i).name);
    }
}

void MainWidget::my_profile_clicked()
{

    if(model_->load_my_profile(current_profile))
    {
        QMessageBox::information(this, "IQuizt", "Profile loaded!");
        display_profile_data();
    }
    else
    {
        QMessageBox::information(this, "IQuizt", "Error loading profile!");
    }
}

bool MainWidget::scan_for_profile()
{
    bool profile_exists = false;
    qDebug() << "szkenneles";
    QDir dir(QDir::currentPath());
    for(auto &entry : dir.entryList(QDir::Files))
    {
        if(entry.split('.').last()=="profile")
        {

            profile_exists = true;
            current_profile = entry.split('.').first();
        }
    }

    return profile_exists;
}

void MainWidget::create_profile()
{
    dialog_->setWindowTitle("Enter your name");
    connect(dialog_, &QDialog::accepted, this, [=]()
    {
        current_profile = dialog_->profile_name();
        delete dialog_;
    });
    dialog_->exec();

    if(model_->create_my_profile(current_profile))
    {
        QMessageBox::information(this, "IQuizt", "Profile created!");
    }
    else
    {
        QMessageBox::information(this, "IQuizt", "Error creating profile!");
    }



}

void MainWidget::display_profile_data()
{
    remove_all_widgets(VBoxLayout_);
    QLabel* name = new QLabel(model_->getProfile()->name());
    QLabel* level = new QLabel(QString::number(model_->getProfile()->getLevel()));
    QLabel* correct = new QLabel(QString::number(model_->getProfile()->getCorrect_counter()));
    QLabel* wrong = new QLabel(QString::number(model_->getProfile()->getWrong_counter()));



    VBoxLayout_->addWidget(name);
    widgets_.append(name);
    VBoxLayout_->addWidget(level);
    widgets_.append(level);
    VBoxLayout_->addWidget(correct);
    widgets_.append(correct);
    VBoxLayout_->addWidget(wrong);
    widgets_.append(wrong);
}

void MainWidget::remove_all_widgets(QLayout *layout)
{
    QWidget* w;
    while ( !widgets_.isEmpty() && ( (w = widgets_.takeFirst()) != 0 ) )
    {
       layout->removeWidget(w);
       delete w;
    }
    widgets_.clear();
}

QString MainWidget::getCurrent_profile() const
{
    return current_profile;
}


