#ifndef PROFILECREATIONDIALOG_H
#define PROFILECREATIONDIALOG_H

#include <QDialog>
#include <QObject>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QLineEdit>

/** \brief profile_creation_dialog class is for creating a new profile by teh user.
 *
 * This class is a child of the QDialog class.
 * When the user selects the "Create a new profile" on menubar a QDialog pops up where the user can write in his name and press ok to create the profil.
 * Or the user can cancel this action by clicking on the cancel button.
 * When there is a profile the user can load it in.
 * When its loaded the information showed on in a layout.
 * \see QDialog
 * */
class profile_creation_dialog : public QDialog
{
    Q_OBJECT
public:
    profile_creation_dialog();

    QString profile_name() const;
    void setProfile_name(const QString &profile_name);

private:
    QString profile_name_;
    QLabel label_;
    QGridLayout* gridLayout_;
    QPushButton* okButton_;
    QPushButton* cancelButton_;
    QLineEdit* lineEdit_;

};

#endif // PROFILECREATIONDIALOG_H
