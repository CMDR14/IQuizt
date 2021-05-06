#include "quizsetdisplay.h"
#include <QDebug>

/** \brief Constructs a widget to display a quiz set.
 *
 *  Can be used to as an editor or a quiz filler.
 *
 *  \param name is the name of the given QuizSet.
 *  \param items is the vector that contains the QuizItems of the set. It's a pointer because it changes the set.
 *  \param is_selector is used to chose if its a filler or editor of the set. Default is filler.
 *  \param parent is the tointer to its parent.
 *  */
QuizSetDisplay::QuizSetDisplay(const QString& name, QVector<QuizItem*> *items, bool is_selector, QWidget *parent)
    : QWidget(parent), name_(name), items_(items), is_selector_(is_selector)
{
    init_layout();
}

QuizSetDisplay::~QuizSetDisplay()
{
    emit save_quiz();
}

/** \brief Sets up the layout of the widget.
 *
 *  The base is the same for the editor and the filler.
 *  */
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

    ///The lower part of the wiget is layed according to its functionality.
    if(is_selector_){
        init_selector_layout();

        result_label_ = new QLabel(this);
        layout_->addWidget(result_label_);
        quiz_answered();
    }else{
        init_editor_layout();

        add_item_btn_ = new QPushButton("Add",this);
        layout_->addWidget(add_item_btn_);
        connect(add_item_btn_, &QPushButton::clicked, this, &QuizSetDisplay::add_new_item);
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

        QPushButton* rem_btn_ = new QPushButton("Remove",this);
        layout_->addWidget(rem_btn_);
        connect(rem_btn_, &QPushButton::clicked, this, &QuizSetDisplay::rem_item);
        remove_item_btns_.append(rem_btn_);
    }
}

/// \brief If a quiz is answered the ui refreshes the results.
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

/// \brief Adds a new item to the collection and refreshes the ui according.
void QuizSetDisplay::add_new_item()
{
    items_->append(new QuizItem());
    layout_->removeWidget(add_item_btn_);
    QuizItemEditor* qs = new QuizItemEditor(items_->last());
    layout_->addWidget(qs);
    qs->show();

    editors_.append(qs);

    QPushButton* rem_btn_ = new QPushButton("Remove",this);
    layout_->addWidget(rem_btn_);
    connect(rem_btn_, &QPushButton::clicked, this, &QuizSetDisplay::rem_item);
    remove_item_btns_.append(rem_btn_);

    layout_->addWidget(add_item_btn_);
}

/// \brief Removes a item from the collection and refreshes the ui according.
void QuizSetDisplay::rem_item()
{
    int ind;
    for(int i=0; i<remove_item_btns_.count(); i++){
        if(sender()==remove_item_btns_[i]){
            ind = i;
        }
    }
    layout_->removeWidget(remove_item_btns_[ind]);
    layout_->removeWidget(editors_[ind]);
    editors_[ind]->deleteLater();
    editors_.remove(ind);
    remove_item_btns_[ind]->deleteLater();
    remove_item_btns_.remove(ind);
    delete items_->at(ind);
    items_->remove(ind);
}
