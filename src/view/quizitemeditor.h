#ifndef QUIZITEMEDITOR_H
#define QUIZITEMEDITOR_H

#include <QGridLayout>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>
#include "../model/quizitem.h"

class QuizItemEditor : public QWidget
{
    Q_OBJECT
public:
    explicit QuizItemEditor(QuizItem* quiz_item = nullptr, QWidget *parent = nullptr);

private:
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

signals:

};

#endif // QUIZITEMEDITOR_H
