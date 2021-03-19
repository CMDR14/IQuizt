#include "quizitemselector.h"

#include <QRandomGenerator>
#include <QDebug>

quizitemselector::quizitemselector(QuizItem *quiz_item, QWidget *parent)
    : QWidget(parent)
{

    qDebug() << "quizitemselector constr";
    quiz_item_ = quiz_item;

    init_layout();
    init_connects();

}



void quizitemselector::init_layout()
{
    qDebug() << "quizitemselector::init_layout";
    grid_layout_ = new QGridLayout(this);
    grid_layout_->setAlignment(Qt::AlignHCenter | Qt::AlignTop);
    //grid_layout_->setSpacing(5);

    question_line_ = new QLineEdit(this);
    question_line_->setText(QString::fromStdString(quiz_item_->getQuestion()));
    question_line_->setEnabled(false);
    grid_layout_->addWidget(question_line_, 0, 0, 1, 2);

    //buttons
    int right_button_x = QRandomGenerator::global()->bounded(1,3); //1-2
    int right_button_y = QRandomGenerator::global()->bounded(0,2); //0-1

    right_button_ = new QPushButton(this);
    right_button_->setText(QString::fromStdString(quiz_item_->getRightAnswer()));
    //grid_layout_->addWidget(right_button_, 1, 0);

    wrong1_button_ = new QPushButton(this);
    wrong1_button_->setText(QString::fromStdString(quiz_item_->getWrongAnswer1()));
    //grid_layout_->addWidget(wrong1_button_, 1, 1);

    wrong2_button_ = new QPushButton(this);
    wrong2_button_->setText(QString::fromStdString(quiz_item_->getWrongAnswer2()));
    //grid_layout_->addWidget(wrong2_button_, 2, 0);

    wrong3_button_ = new QPushButton(this);
    wrong3_button_->setText(QString::fromStdString(quiz_item_->getWrongAnswer3()));
    //grid_layout_->addWidget(wrong3_button_, 2, 1);

    init_answer_buttons(grid_layout_, right_button_x, right_button_y, right_button_, wrong1_button_, wrong2_button_, wrong3_button_);


}

void quizitemselector::init_answer_buttons(QGridLayout* layout, int coord_x, int coord_y, QPushButton* right_button_,
                                           QPushButton* wrong1_button_, QPushButton* wrong2_button_, QPushButton* wrong3_button_)
{
    if(coord_x == 1 && coord_y == 0){
         layout->addWidget(right_button_, 1, 0);
         layout->addWidget(wrong1_button_, 1, 1);
         layout->addWidget(wrong2_button_, 2, 0);
         layout->addWidget(wrong3_button_, 2, 1);

    }

    if(coord_x == 1 && coord_y == 1){
        layout->addWidget(wrong1_button_, 1, 0);
        layout->addWidget(right_button_, 1, 1);
        layout->addWidget(wrong2_button_, 2, 0);
        layout->addWidget(wrong3_button_, 2, 1);
    }

    if(coord_x == 2 && coord_y == 0){
        layout->addWidget(wrong1_button_, 1, 0);
        layout->addWidget(wrong2_button_, 1, 1);
        layout->addWidget(right_button_, 2, 0);
        layout->addWidget(wrong3_button_, 2, 1);
    }

    if(coord_x == 2 && coord_y == 1){
        layout->addWidget(wrong1_button_, 1, 0);
        layout->addWidget(wrong2_button_, 1, 1);
        layout->addWidget(wrong3_button_, 2, 0);
        layout->addWidget(right_button_, 2, 1);
    }



}


void quizitemselector::init_connects()
{
    connect(right_button_, SIGNAL(clicked()), this, SLOT(on_answer_button_clicked()));
    connect(wrong1_button_, SIGNAL(clicked()), this, SLOT(on_answer_button_clicked()));
    connect(wrong2_button_, SIGNAL(clicked()), this, SLOT(on_answer_button_clicked()));
    connect(wrong3_button_, SIGNAL(clicked()), this, SLOT(on_answer_button_clicked()));

}



void quizitemselector::on_answer_button_clicked()
{
    if(sender() == right_button_){
        quiz_item_->newTry(true);
    }else{
        quiz_item_->newTry(false);
    }

}

