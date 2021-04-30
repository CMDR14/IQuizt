#include "quizitemeditor.h"
#include <QDebug>

QuizItemEditor::QuizItemEditor(QuizItem *quiz_item, QWidget *parent)
    : QWidget(parent)
{
    quiz_item_ = quiz_item;

    init_layout();
    init_connects();
}

/** \brief This method sets up the layout of the widget.  
 * 
 * Inits all the widgets, which are needed to display the `quiz_item_`.  
 * Then fills them with the informations.  
 * Then arenges them in the layout.  
 * */
void QuizItemEditor::init_layout()
{
    grid_layout_ = new QGridLayout(this);
    grid_layout_->setSpacing(5);


    question_line_ = new QLineEdit(this);
    question_line_->setText(quiz_item_->getQuestion());
    grid_layout_->addWidget(question_line_, 0, 0, 1, 2);

    right_line_ = new QLineEdit(this);
    right_line_->setText(quiz_item_->getRightAnswer());
    grid_layout_->addWidget(right_line_, 1, 0);

    wrong1_line_ = new QLineEdit(this);
    wrong1_line_->setText(quiz_item_->getWrongAnswer1());
    grid_layout_->addWidget(wrong1_line_, 1, 1);

    wrong2_line_ = new QLineEdit(this);
    wrong2_line_->setText(quiz_item_->getWrongAnswer2());
    grid_layout_->addWidget(wrong2_line_, 2, 0);

    wrong3_line_ = new QLineEdit(this);
    wrong3_line_->setText(quiz_item_->getWrongAnswer3());
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


/** \brief Connects the user input events with the needed slots.  
 * 
 * The line edits are signaling when their content is edited.  
 * The spin boxes are also signaling when their value is changed.  
 * Then the editor works with these informations.  
 * The save button signals when it is clicked, then the editor saves the new contents.  
 * */
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

/** \brief When triggered, finds which edit is the sender and saves the new string according.  
 * 
 * Checks if the sender is any of the known line edits and saves the string in the right buffer string.  
 * The save button is not enabled in default. It gets enabled when one of the values change.  
 * */
void QuizItemEditor::on_textEdited(const QString &text)
{
    //qDebug() << "Text edited\n";
    save_button_->setEnabled(true);

    if(sender() == question_line_)
        new_str_[0] = text;
    if(sender() == right_line_)
        new_str_[1] = text;
    if(sender() == wrong1_line_)
        new_str_[2] = text;
    if(sender() == wrong2_line_)
        new_str_[3] = text;
    if(sender() == wrong3_line_)
        new_str_[4] = text;

    //qDebug() << new_str_[0].c_str();

}

/** \brief When triggered, finds which spin box is the sender and saves the new value according.  
 * 
 * Checks if the sender is any of the known spin boxes and saves the value in the right buffer integer.  
 * The save button is not enabled in default. It gets enabled when one of the values change.  
 * */
void QuizItemEditor::on_valueChanged(int value)
{
    save_button_->setEnabled(true);

    if(sender() == trys_spin_)
        new_int_[0] = value;
    if(sender() == corrects_spin_)
        new_int_[1] = value;
}

/** \brief When triggered, saves the values from the buffer.
 * 
 * Saves all the values from the right buffers to the `quiz_item_`.
 * Sets the save button unavailable to press after save.
 * */
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
