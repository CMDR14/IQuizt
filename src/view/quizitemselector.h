#ifndef QUIZITEMSELECTOR_H
#define QUIZITEMSELECTOR_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include "../model/quizitem.h"

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
