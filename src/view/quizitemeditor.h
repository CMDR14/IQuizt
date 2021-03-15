#ifndef QUIZITEMEDITOR_H
#define QUIZITEMEDITOR_H

#include <QGridLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QWidget>
#include "../model/quizitem.h"

class QuizItemEditor : public QWidget
{
    Q_OBJECT
public:
    explicit QuizItemEditor(QuizItem* quiz_item, QWidget *parent = nullptr);

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
    QPushButton* save_button_;
    std::string new_str_[5];
    int new_int[2];

    void init_layout();
    void init_connects();

public slots:
    void on_textEdited(const QString &text);
    void on_save();

};

#endif // QUIZITEMEDITOR_H
