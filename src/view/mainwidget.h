#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "../model/model.h"
#include <QWidget>
#include <QListWidget>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QLayout>
#include "quizitemselector.h"
#include "../model/quizitem.h"
#include "profilecreationdialog.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(Model *model, QWidget *parent = nullptr);


    QString getCurrent_profile() const;

private:
    void create_menubar();
    void list_quizzes_clicked();
    void my_profile_clicked();
    bool scan_for_profile();
    void create_profile();
    void display_profile_data();
    void remove_all_widgets(QLayout* layout);

    Model* model_; 
    Persistence* p_;
    QVBoxLayout* VBoxLayout_;
    QListWidget* list_;
    profile_creation_dialog* dialog_;
    QString current_profile;
    QVector<QWidget*> widgets_;

signals:


};

#endif // MAINWIDGET_H
