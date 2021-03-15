#include "quizitemeditor.h"
#include <QDebug>

QuizItemEditor::QuizItemEditor(QuizItem *quiz_item, QWidget *parent)
    : QWidget(parent)
{
    quiz_item_ = quiz_item;

    init_layout();
    init_connects();
}

void QuizItemEditor::init_layout()
{
    grid_layout_ = new QGridLayout(this);
    grid_layout_->setSpacing(5);


    question_line_ = new QLineEdit(this);
    question_line_->setText(QString::fromStdString(quiz_item_->getQuestion()));
    grid_layout_->addWidget(question_line_, 0, 0, 1, 2);

    right_line_ = new QLineEdit(this);
    right_line_->setText(QString::fromStdString(quiz_item_->getRightAnswer()));
    grid_layout_->addWidget(right_line_, 1, 0);

    wrong1_line_ = new QLineEdit(this);
    wrong1_line_->setText(QString::fromStdString(quiz_item_->getWrongAnswer1()));
    grid_layout_->addWidget(wrong1_line_, 1, 1);

    wrong2_line_ = new QLineEdit(this);
    wrong2_line_->setText(QString::fromStdString(quiz_item_->getWrongAnswer2()));
    grid_layout_->addWidget(wrong2_line_, 2, 0);

    wrong3_line_ = new QLineEdit(this);
    wrong3_line_->setText(QString::fromStdString(quiz_item_->getWrongAnswer3()));
    grid_layout_->addWidget(wrong3_line_, 2, 1);


    trys_layout_ = new QHBoxLayout(this);

    trys_spin_ = new QSpinBox(this);
    trys_spin_->setValue(quiz_item_->getTrys());
    trys_layout_->addWidget(trys_spin_);

    corrects_spin_ = new QSpinBox(this);
    corrects_spin_->setValue(quiz_item_->getCorrects());
    trys_layout_->addWidget(corrects_spin_);

    grid_layout_->addLayout(trys_layout_, 3, 0);

    save_button_ = new QPushButton("Save", this);
    save_button_->setEnabled(false);
    grid_layout_->addWidget(save_button_, 3, 1);

    setLayout(grid_layout_);
}

void QuizItemEditor::init_connects()
{
    connect(question_line_, SIGNAL(textEdited(const QString&)), this, SLOT(on_textEdited(const QString&)));
    connect(right_line_, SIGNAL(textEdited(const QString&)), this, SLOT(on_textEdited(const QString&)));
    connect(wrong1_line_, SIGNAL(textEdited(const QString&)), this, SLOT(on_textEdited(const QString&)));
    connect(wrong2_line_, SIGNAL(textEdited(const QString&)), this, SLOT(on_textEdited(const QString&)));
    connect(wrong3_line_, SIGNAL(textEdited(const QString&)), this, SLOT(on_textEdited(const QString&)));

    connect(trys_spin_, SIGNAL(valueChanged(int)), this, SLOT(on_valueChanged(int)));
    connect(corrects_spin_, SIGNAL(valueChanged(int)), this, SLOT(on_valueChanged(int)));

    connect(save_button_, SIGNAL(clicked()), this, SLOT(on_save()));
}

void QuizItemEditor::on_textEdited(const QString &text)
{
    //qDebug() << "Text edited\n";
    save_button_->setEnabled(true);

    if(sender() == question_line_)
        new_str_[0] = text.toStdString();
    if(sender() == right_line_)
        new_str_[1] = text.toStdString();
    if(sender() == wrong1_line_)
        new_str_[2] = text.toStdString();
    if(sender() == wrong2_line_)
        new_str_[3] = text.toStdString();
    if(sender() == wrong3_line_)
        new_str_[4] = text.toStdString();

    //qDebug() << new_str_[0].c_str();

}

void QuizItemEditor::on_valueChanged(int value)
{
    save_button_->setEnabled(true);

    if(sender() == trys_spin_)
        new_int_[0] = value;
    if(sender() == corrects_spin_)
        new_int_[1] = value;
}

void QuizItemEditor::on_save()
{
    //qDebug() << "Saved\n";
    save_button_->setEnabled(false);

    quiz_item_->setQuestion(new_str_[0]);
    quiz_item_->setRightAnswer(new_str_[1]);
    quiz_item_->setWrongAnswer1(new_str_[2]);
    quiz_item_->setWrongAnswer2(new_str_[3]);
    quiz_item_->setWrongAnswer3(new_str_[4]);
    quiz_item_->setTrys(new_int_[0]);
    quiz_item_->setCorrects(new_int_[1]);

    //qDebug() << quiz_item_->getQuestion().c_str();
}
