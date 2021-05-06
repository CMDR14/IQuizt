#ifndef PROFILE_H
#define PROFILE_H

#include <QDebug>
#include <QString>
#include <QVector>



class Profile
{
public:
    Profile(QString const &name = "", int level = 1, int correct_c = 0, int wrong_c = 0);

    QString name() const;
    void setName(const QString &name);

    int getCorrect_counter() const;
    void setCorrect_counter(int value);

    int getLevel() const;
    void setLevel(int level);

    int getWrong_counter() const;
    void setWrong_counter(int value);

    void AdjustLevel();

private:
    QString name_;
    int level_;
    int correct_counter;
    int wrong_counter;

};

#endif // PROFILE_H
