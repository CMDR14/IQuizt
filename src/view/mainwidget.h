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


/** \brief This class functions as the main GUI of the program.
 * 
 * MainWidget is inherited from the \link https://doc.qt.io/qt-5/qwidget.html QWidget \endlink class.
 * Has a few spaces for different functions.
 * 
 * \see \link https://doc.qt.io/qt-5/qwidget.html QWidget \endlink
 */
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

    /// Reference for the program's busines logic
    Model* model_; 
    /// Reference for the persistence
    Persistence* p_;
    QVBoxLayout* VBoxLayout_;
    /// Widget for displaying available quiz sets
    QListWidget* list_;
    profile_creation_dialog* dialog_;
    QString current_profile;
    QVector<QWidget*> widgets_;

signals:


};

#endif // MAINWIDGET_H
