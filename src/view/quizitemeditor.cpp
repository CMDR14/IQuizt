#include "quizitemeditor.h"

QuizItemEditor::QuizItemEditor(QuizItem *quiz_item, QWidget *parent)
    : QWidget(parent)
{
    quiz_item_ = quiz_item;

    grid_layout_ = new QGridLayout();
    grid_layout_->setSpacing(5);


    question_line_ = new QLineEdit();
    question_line_->setText(QString::fromStdString(quiz_item_->getQuestion()));
    grid_layout_->addWidget(question_line_, 0, 0, 1, 2);

    right_line_ = new QLineEdit();
    right_line_->setText(QString::fromStdString(quiz_item_->getRightAnswer()));
    grid_layout_->addWidget(right_line_, 1, 0);

    wrong1_line_ = new QLineEdit();
    wrong1_line_->setText(QString::fromStdString(quiz_item_->getWrongAnswer1()));
    grid_layout_->addWidget(wrong1_line_, 1, 1);

    wrong2_line_ = new QLineEdit();
    wrong2_line_->setText(QString::fromStdString(quiz_item_->getWrongAnswer2()));
    grid_layout_->addWidget(wrong2_line_, 2, 0);

    wrong3_line_ = new QLineEdit();
    wrong3_line_->setText(QString::fromStdString(quiz_item_->getWrongAnswer3()));
    grid_layout_->addWidget(wrong3_line_, 2, 1);


    trys_layout_ = new QHBoxLayout();

    trys_spin_ = new QSpinBox();
    trys_spin_->setValue(quiz_item_->getTrys());
    trys_layout_->addWidget(trys_spin_);

    corrects_spin_ = new QSpinBox();
    corrects_spin_->setValue(quiz_item_->getCorrects());
    trys_layout_->addWidget(corrects_spin_);

    grid_layout_->addLayout(trys_layout_, 3, 0);

    setLayout(grid_layout_);
}
