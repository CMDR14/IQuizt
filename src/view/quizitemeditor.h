#ifndef QUIZITEMEDITOR_H
#define QUIZITEMEDITOR_H

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>
#include "../model/quizitem.h"


/** \brief QuizItemEditor class is a widget to edit a QuizItem by the user.  
 * 
 * This class is a childer of the QWidget class. It shows all the information from one given QuizItem and let's the user edit those informations.  
 * The user changes the content of the line edits and then he can save these to the QuizItem.  
 * \see QuizItem  
 * */
class QuizItemEditor : public QWidget
{
    Q_OBJECT

    friend class QuizItemEditorTest;

public:
    explicit QuizItemEditor(QuizItem* quiz_item, QWidget *parent = nullptr);

private:
    ///The QuizItem which can be edited.  
    QuizItem* quiz_item_;
    QGridLayout* grid_layout_;
    QHBoxLayout* trys_layout_;
    QLineEdit* question_line_;
    QLineEdit* right_line_;
    QLineEdit* wrong1_line_;
    QLineEdit* wrong2_line_;
    QLineEdit* wrong3_line_;
    QSpinBox* trys_spin_;
    QSpinBox* corrects_spin_;
    QPushButton* save_button_;
    QString new_str_[5];
    int new_int_[2];

    void init_layout();
    void init_connects();

public slots:
    void on_textEdited(const QString &text);
    void on_valueChanged(int value);
    void on_save();

};

#endif // QUIZITEMEDITOR_H
