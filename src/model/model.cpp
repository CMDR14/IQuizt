#include "model.h"
#include <QDebug>


Model::Model(Persistence* p) : profile_(new Profile())
{
    p_ = p;

}

Model::Model(const Model &m) : profile_(new Profile())
{
    p_ = m.p_;
}

Model& Model::operator=(const Model& other)
{
  if (this == &other) //self-assignment guard;
      return *this;

  if (list_of_quizzes.size() != other.list_of_quizzes.size())
  {
      list_of_quizzes.clear();
  }
  p_ = other.p_;
  profile_ = other.profile_;
  std::copy(other.list_of_quizzes.begin(), other.list_of_quizzes.end(), list_of_quizzes.begin());
  return *this;
}


Model::~Model()
{
}

bool Model::load_my_profile(QString prof_name)
{
    QVector<QString> loadProfData;
    if(p_->loadProfile(loadProfData,prof_name))
    {
        profile_->setName(loadProfData[0]);
        profile_->setLevel(loadProfData[1].toInt());
        profile_->setCorrect_counter(loadProfData[2].toInt());
        profile_->setWrong_counter(loadProfData[3].toInt());

        return true;
    }
    return false;
}

bool Model::create_my_profile(QString prof_name)
{
    profile_->setName(prof_name);
    QVector<QString> profData;
    profData.append(profile_->name());
    profData.append(QString::number(profile_->getLevel()));
    profData.append(QString::number(profile_->getCorrect_counter()));
    profData.append(QString::number(profile_->getWrong_counter()));



    return p_->createProfile(prof_name, profData);
}

bool Model::scan_for_profile(QString &current_profile)
{
    return p_->scan_for_profile(current_profile);
}

void Model::load_existing_quiz()
{
    //qDebug() << "Model::load_existing_quiz";

}

void Model::list_quizzes()
{
    qDebug() << "list quizzes func";
    list_of_quizzes.clear();
    qDebug() << "list quizzes func2";
    if(!(p_->get_quiz_sets(list_of_quizzes)))
    {
        qDebug() << "Quiz loading unsuccesful!";
        return;
    }

    qDebug() << "Quiz loading succesful!";
}

QVector<NameAndPath> Model::getList_of_quizzes() const
{
    return list_of_quizzes;
}

Profile *Model::getProfile() const
{
    return profile_;
}


