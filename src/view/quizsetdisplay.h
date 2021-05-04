#ifndef QUIZSETDISPLAY_H
#define QUIZSETDISPLAY_H

#include <QLabel>
#include <QScrollArea>
#include <QWidget>

#include "../model/quizitem.h"
#include "quizitemselector.h"
#include "quizitemeditor.h"

/** \brief This class is used to display a quiz set
 *
 *  With the cunstructor, one can choose if its a selector or editor.
 *  */
class QuizSetDisplay : public QWidget
{
    Q_OBJECT
public:
    explicit QuizSetDisplay(const QString& name, QVector<QuizItem*> *items, bool is_selector = true, QWidget *parent = nullptr);

private:
    QString name_;
    QVector<QuizItem*> *items_;
    bool is_selector_;

    QScrollArea *scroll_area_;
    QVBoxLayout *layout_;
    QLabel* name_label_;
    QLabel* result_label_;
    QVector<quizitemselector*> selectors_;
    QVector<QuizItemEditor*> editors_;
    QVector<QPushButton*> remove_item_btns_;
    QPushButton *add_item_btn_;

    void init_layout();
    void init_selector_layout();
    void init_editor_layout();

public slots:
    void quiz_answered();
    void add_new_item();
    void rem_item();
};

#endif // QUIZSETDISPLAY_H
