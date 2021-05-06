#include "model.h"
#include <QDebug>


Model::Model(Persistence* p) : dir_path_("."), profile_(new Profile()), quiz_set_(nullptr)
{
    p_ = p;
}


/** \brief operator '=' overload
 *
 * Overload the '=' operator which willbe used in copy cpnstructor
 * \param gets a Model which you want to copy
 * */
Model& Model::operator=(const Model& other)
{
  if (this == &other) //self-assignment guard;
      return *this;

  if (list_of_quizzes.size() != other.list_of_quizzes.size() || quiz_set_->size() != other.quiz_set_->size())
  {
      list_of_quizzes.clear();
      quiz_set_->clear();
  }
  p_ = other.p_;
  profile_ = other.profile_;
  dir_path_ = other.dir_path_;
  std::copy(other.list_of_quizzes.begin(), other.list_of_quizzes.end(), list_of_quizzes.begin());
  std::copy(other.quiz_set_->begin(), other.quiz_set_->end(), quiz_set_->begin());

  return *this;
}


Model::~Model()
{
}

/** \brief Load a profile
 *
 * Load a profile and use loadProfile function from persistence
 * \param gets a profile name
 * * \returns boolean which will be true if the load was successfull
 * */
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

/** \brief Create a profile
 *
 * Create a profile and use createProfile function from persistence
 * \param gets a profile name
 * * \returns boolean which will be true if the load was successfull
 * */
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

bool Model::save_active_quiz()
{
    return p_->saveQuiz(quiz_set_name_and_path_, quiz_set_);
}

void Model::load_existing_quiz(NameAndPath nap)
{
    qDebug() << "Model::load_existing_quiz";
    if(p_->loadQuiz(nap, quiz_set_))
            qDebug() << "Model::load_existing_quiz" << quiz_set_;
    else
        quiz_set_ = nullptr;
}


/** \brief List quizzes
 *
 * List the quizzes from your folder
 * Use get_quiz_sets function from Persistence
 * */
void Model::list_quizzes()
{
    qDebug() << "list quizzes func";
    list_of_quizzes.clear();
    qDebug() << "list quizzes func2";
    if(!(p_->get_quiz_sets(list_of_quizzes, dir_path_)))
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

QString Model::getDirPath() const
{
    return dir_path_;
}

void Model::setDirPath(const QString& path)
{
    dir_path_ = path;
}



