#ifndef PROFILECREATIONDIALOG_H
#define PROFILECREATIONDIALOG_H

#include <QDialog>
#include <QObject>
#include <QGridLayout>
#include <QLabel>
#include <QPushButton>
#include <QString>
#include <QLineEdit>

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
