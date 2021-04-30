#include "profilecreationdialog.h"
#include <QDebug>


/** \brief This method creates a dialog for where the user can create a profile.
 *
 * This method arrenges the layout.
 * Inits a button, a label, and two button for ok and cancel.
 * If you created a new profile, then you can load it from the menubar.
 * */
profile_creation_dialog::profile_creation_dialog() :
    label_(new QLabel),
    gridLayout_(new QGridLayout)
{
        setFixedSize(300,300);
        okButton_ = new QPushButton("OK");
        cancelButton_ = new QPushButton("Cancel");
        lineEdit_ = new QLineEdit();

        label_.setText("Enter profile name: ");

        gridLayout_->addWidget(&label_,0,1);
        gridLayout_->addWidget(lineEdit_,1,1);
        gridLayout_->addWidget(okButton_,2,0);
        gridLayout_->addWidget(cancelButton_,2,2);

        setLayout(gridLayout_);

        okButton_->setEnabled(false);

        connect(okButton_, &QPushButton::clicked, this, [=](){
            setProfile_name(lineEdit_->text());
            //qDebug() << profile_name_;
            this->accept();
        });

        //connect(okButton_, SIGNAL(clicked()), this, SLOT(accept()));
        connect(cancelButton_, &QPushButton::clicked, this, [=](){
            this->reject();
        });

        connect(lineEdit_, &QLineEdit::textChanged, this, [=]()
        {
            if(lineEdit_->text() == "")
            {
                okButton_->setEnabled(false);
            }
            else
            {
                okButton_->setEnabled(true);
            }
        });
}


QString profile_creation_dialog::profile_name() const
{
    return profile_name_;
}


void profile_creation_dialog::setProfile_name(const QString &profile_name)
{
    profile_name_ = profile_name;
}
