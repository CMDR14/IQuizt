#ifndef QUIZITEMSELECTOR_H
#define QUIZITEMSELECTOR_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include "../model/quizitem.h"



/** \brief QuizItemSelector class is a widget to answer for a QuizItem by the user.
 *
 * This class is a child of the QWidget class. It shows all the information from one given QuizItem and let's the answer fro a question by select click on a button which cintains the wrong or the good answer.
 * The click effects that the QuizItem gets it was a good answer choice or not.
 * \see QuizItem
 * */
class quizitemselector : public QWidget
{
    Q_OBJECT
public:
    explicit quizitemselector(QuizItem* quiz_item, QWidget *parent = nullptr);


private:

   //components
   QuizItem* quiz_item_;
   QGridLayout* grid_layout_;
   QLineEdit* question_line_;
   QPushButton* right_button_;
   QPushButton* wrong1_button_;
   QPushButton* wrong2_button_;
   QPushButton* wrong3_button_;

   //functions
   void init_layout();
   void init_answer_buttons(QGridLayout*, int, int, QPushButton*, QPushButton*, QPushButton*, QPushButton*);
   void init_connects();

signals:


public slots:
   void on_answer_button_clicked();

};

#endif // QUIZITEMSELECTOR_H
