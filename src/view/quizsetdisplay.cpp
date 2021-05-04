#include "quizsetdisplay.h"
#include <QDebug>

QuizSetDisplay::QuizSetDisplay(const QString& name, QVector<QuizItem*> *items, bool is_selector, QWidget *parent)
    : QWidget(parent), name_(name), items_(items), is_selector_(is_selector)
{
    init_layout();
}

void QuizSetDisplay::init_layout()
{
    scroll_area_ = new QScrollArea(this);
    scroll_area_->setWidgetResizable(true);
    new QVBoxLayout(this);
    this->layout()->addWidget(scroll_area_);
    QWidget *d_scroll_area_widget = new QWidget();
    scroll_area_->setWidget(d_scroll_area_widget);
    layout_ = new QVBoxLayout(d_scroll_area_widget);

    //layout_ = new QVBoxLayout();
    //setLayout(layout_);
    //scroll_area_->setLayout(layout_);

    name_label_ = new QLabel(this);
    name_label_->setText(name_);
    layout_->addWidget(name_label_);


    if(is_selector_){
        init_selector_layout();

        result_label_ = new QLabel(this);
        layout_->addWidget(result_label_);
        quiz_answered();
    }else{
        init_editor_layout();
    }
}

void QuizSetDisplay::init_selector_layout()
{
    for (int i=0; i<items_->count(); ++i) {
        quizitemselector* qs = new quizitemselector((*items_)[i], this);
        layout_->addWidget(qs);
        qs->show();
        connect(qs, &quizitemselector::quiz_answered, this, &QuizSetDisplay::quiz_answered);
        selectors_.append(qs);
    }
}

void QuizSetDisplay::init_editor_layout()
{
    //QuizItemEditor* qs = new QuizItemEditor((*items_)[0], this);
    //qs->show();
    for (int i=0; i<items_->count(); ++i) {
        //qDebug() << (*items_)[i]->getQuestion();
        QuizItemEditor* qs = new QuizItemEditor((*items_)[i]);
        layout_->addWidget(qs);
        qs->show();

        editors_.append(qs);
    }
}

void QuizSetDisplay::quiz_answered()
{
    int all=items_->count(), answered=0, good=0;
    for (int i=0; i<items_->count(); ++i) {
        switch(selectors_[i]->is_answered()){
        case  1 : good++;
        case  2 : answered++;
        default : break;
        }
    }
    result_label_->setText("You filled: " + QString::number(answered) + "/" + QString::number(all)
                       + "\nYou got: " + QString::number(good) + "/" + QString::number(all));
}
