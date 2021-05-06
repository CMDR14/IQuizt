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
    //this->setFixedSize(600,600);
    setMinimumSize(400,500);
    dialog_ = new profile_creation_dialog();

    setWindowIcon(QIcon("IQuizt-icon-144x144.png"));
}
/// \brief Creates a Menu Bar and fills it with actions.
void MainWidget::create_menubar()
{
        QMenuBar* menu_bar = new QMenuBar();
        this->setLayout(VBoxLayout_);

        bool profile_exists = scan_for_profile();
        /// \arg If profile exists, then creates action to open it.
        if(profile_exists)
        {
            auto *load_profile_clicked = menu_bar->addAction("Load my Profile");
            connect(load_profile_clicked, &QAction::triggered, this, [=]()
            {
                my_profile_clicked();
            });
        }
        /// \arg If profile not exists, adds option to create a profile.
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

        /// \arg Adds action to edit the active quiz set.
        auto *edit_quiz_clicked = menu_bar->addAction("Edit a quiz");
        connect(edit_quiz_clicked, &QAction::triggered, this, [=]()
        {
            qDebug() << "Edit quiz clicked";
            if(model_->get_active_quiz_set_()==nullptr){
                QMessageBox msg;
                msg.setText("No quiz selected!");
                msg.exec();

            }else{
                remove_all_widgets(VBoxLayout_);
                QuizSetDisplay* qst = new QuizSetDisplay(model_->get_active_set_name_and_path().name, model_->get_active_quiz_set_(), false, model_->getProfile());
                connect(qst, &QuizSetDisplay::save_quiz, this, &MainWidget::save_quiz);
                VBoxLayout_->addWidget(qst);
                widgets_.append(qst);
                qst->show();

            }

        });

        /// \arg Adds action to fill the active quiz set.
        auto *fill_quiz_clicked = menu_bar->addAction("Fill a quiz");
        connect(fill_quiz_clicked, &QAction::triggered, this, [=]()
        {
            qDebug() << "Fill quiz clicked";
            if(model_->get_active_quiz_set_()==nullptr){
                QMessageBox msg;
                msg.setText("No quiz selected!");
                msg.exec();

            }else{
                remove_all_widgets(VBoxLayout_);
                QuizSetDisplay* qst = new QuizSetDisplay(model_->get_active_set_name_and_path().name, model_->get_active_quiz_set_(), true, model_->getProfile());
                connect(qst, &QuizSetDisplay::save_quiz, this, &MainWidget::save_quiz);
                connect(qst, &QuizSetDisplay::save_profile, this, [=](){
                    model_->save_my_profile(current_profile);
                });
                VBoxLayout_->addWidget(qst);
                widgets_.append(qst);
                qst->show();

            }

        });

        /// \arg Adds action to load the existing quiz sets.
        auto *load_quiz_clicked = menu_bar->addAction("Load Existing Quizzes");
        connect(load_quiz_clicked, &QAction::triggered, this, [=]()
        {
            list_quizzes_clicked();
        });

        /// \arg Adds action to set quiz directory.
        auto *set_quiz_dir_clicked = menu_bar->addAction("Set Quiz Directory");
        connect(set_quiz_dir_clicked, &QAction::triggered, this, [=]()
        {
            create_file_dialog();
        });

        menu_bar->setNativeMenuBar(false);
        menu_bar->show();
        this->layout()->setMenuBar(menu_bar);

        menu_bar->setFocus();
}

/// \brief Gets all the available quiz sets and displays them
void MainWidget::list_quizzes_clicked()
{
    remove_all_widgets(VBoxLayout_);
    list_ = new QListWidget();
    list_->setVisible(false);
    connect(list_, &QListWidget::itemSelectionChanged, this, [=](){
        if(list_->selectedItems().count()>0){
            int ind = list_->selectedItems().at(0)->text().split(" ").at(0).toInt();
            model_->set_active_set_name_and_path(model_->getList_of_quizzes().at(ind-1));

            model_->load_existing_quiz(model_->getList_of_quizzes().at(ind-1));
        }
    });
    VBoxLayout_->addWidget(list_);
    widgets_.append(list_);
    list_->clearSelection();
    list_->clear();
    list_->setVisible(true);
    model_->list_quizzes();
    QVector<NameAndPath> tmp = model_->getList_of_quizzes();
    for(int i = 0; i < tmp.size(); ++i)
    {
        list_->addItem(QString::number(i+1) + " : " + tmp.at(i).name + "\t" + tmp.at(i).path);
    }

    qDebug() << "MainWidget::list_quizzes_clicked.";
}

/// \brief If model can load profile, calls for profile displaying
void MainWidget::my_profile_clicked()
{

    if(model_->load_my_profile(current_profile))
    {
        //QMessageBox::information(this, "IQuizt", "Profile loaded!");
        display_profile_data();
    }
    else
    {
        QMessageBox::information(this, "IQuizt", "Error loading profile!");
    }
}

/// \brief Scans for existing profile files.
bool MainWidget::scan_for_profile()
{
    return model_->scan_for_profile(current_profile);
}

/// \brief Function that creates a new profile.
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

/// \brief Function that displays the data in the profile file.
void MainWidget::display_profile_data()
{
    remove_all_widgets(VBoxLayout_);
    QLabel* name = new QLabel("Név: " + model_->getProfile()->name());
    QLabel* level = new QLabel("Szint: " + QString::number(model_->getProfile()->getLevel()));
    QLabel* correct = new QLabel("Helyes válaszok: " + QString::number(model_->getProfile()->getCorrect_counter()));
    QLabel* wrong = new QLabel("Helytelen válaszok: " + QString::number(model_->getProfile()->getWrong_counter()));



    VBoxLayout_->addWidget(name);
    widgets_.append(name);
    VBoxLayout_->addWidget(level);
    widgets_.append(level);
    VBoxLayout_->addWidget(correct);
    widgets_.append(correct);
    VBoxLayout_->addWidget(wrong);
    widgets_.append(wrong);
}

/// \brief Conveniency function that deletes all widgets.
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

/// \brief create file dialog where you can select the .quiz files and it gets the folder path
void MainWidget::create_file_dialog()
{

     QFileDialog dialog;
     dialog.setNameFilter("quiz files (*.quiz)");
     dialog.exec();


     QDir d =  dialog.directory();
     QString absolute = d.absolutePath();

     qDebug() << "Utvonal: " << absolute;
     model_->setDirPath(absolute);

}

void MainWidget::save_quiz()
{
    qDebug() << "MainWidget::save_quiz\tfunction called\n";
    model_->save_active_quiz();
}

/// \brief Getter of the current profile.
QString MainWidget::getCurrent_profile() const
{
    return current_profile;
}


