#include "persistence.h"

#include <QFileInfo>
#include <QFile>
#include <QDir>
#include <QTextStream>
#include <QDebug>

/** \brief Lists all the available quiz sets in a folder.
 * 
 * Opens the directorey (now the current directory).
 * Goes through all the files in the directory.
 * If the file's extention is "quiz" the program considers it as a saved quiz.
 * In every save the first lline is the name of the quiz set.
 * 
 * \param quiz_sets is the storage where the function will put all the right items.
 *      It is a vector of NameAndPath type.
 * \returns `true` if everithing works fine.
 * */
bool Persistence::get_quiz_sets(QVector<NameAndPath>& quiz_sets, QString path) {

    bool success = true;

    //QDir dir(QDir::currentPath());
    //qDebug() << "Persistence::get_quiz_sets path: " << QDir::currentPath();
    QDir dir(path);
    qDebug() << "Persistence::get_quiz_sets path: " << path;
    for (auto &entry : dir.entryList(QDir::Files)) {
        if(entry.split('.').last()!="quiz")
            continue;

        NameAndPath current;
        current.path = path+"/"+entry;

        QFile file(path+"/"+entry);
        if(!file.open(QFile::ReadOnly))
                success = false;

        QTextStream stream(&file);
        current.name = stream.readLine();

        file.close();
        quiz_sets.append(current);
    }
    return success;
}

/** \brief Saves a quiz set to a file.
 * 
 * Opens the file given by the path.
 * Creates a <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a> from the file.
 * Writes the name of the quiz set.
 * Goes through all the quizes in the set and writes them into the stream and closes the file.
 * \param NamePath NameAndPath which sould contain tha name of the quiz set and the save file's path.
 * \param SaveQuizData vector of QuizItem which contains all the quiz items in the set.
 * \returns true if everything is correct.
 * \see <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a>
 * */
bool Persistence::saveQuiz(const NameAndPath &NamePath, QVector<QuizItem*>* &SaveQuizData)
{
    QFile file(NamePath.path);
    if(!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);

    stream << NamePath.name << "\n\n";

    for(int i = 0; i < SaveQuizData->size(); ++i)
    {
        stream << *((*SaveQuizData)[i]) << "\n";
    }

    file.close();

    return true;
}


/** \brief Loads a quiz set from a file.
 * 
 * Opens the file given by the path.
 * Creates a <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a> from the file.
 * Reads the name of the quiz set.
 * Goes through the file and reads all the quizes from the stream and writes them in the storage vector.
 * \param NamePath NameAndPath which sould contain the save file's path.
 * \param SaveQuizData vector of QuizItem which will contain all the quiz items in the set.
 * \returns true if everything is correct.
 * \see <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a>
 * */
bool Persistence::loadQuiz(NameAndPath &NamePath, QVector<QuizItem*>* &loadQuizData)
{
    try{
    QFile file(NamePath.path);
    if(!file.open(QFile::ReadOnly))
            return false;

    QTextStream stream(&file);
    //loadQuizData->clear();
    loadQuizData = new QVector<QuizItem*>();

    NamePath.name = stream.readLine(); stream.readLine();

    while( !stream.atEnd() ) {
        QuizItem *tmp = new QuizItem("", "", "", "", "");
        stream >> (*tmp);
        stream.readLine();
        loadQuizData->append(tmp);
        //qDebug() << tmp->getQuestion();
        //qDebug() << loadQuizData->last()->getQuestion();
    }

    file.close();

    return true;
    }catch(...){
        return false;
    }
}


/** \brief Function that saves profile data into a file.
 *
 * Opens the file given by the path.
 * Creates a <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a> from the file.
 * Goes through the vector and writes the data into the file.
 * \param SaveProfileData is the data that will be written into the file.
 * \param profileName, this is needed to find the correct file to write into.
 * \returns true if everything is correct.
 * \see <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a>
 * */

bool Persistence::saveProfile(QVector<QString> &SaveProfileData, QString const &profileName)
{
    QFile file(profileName + ".profile");
    if(!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);

    for(int i = 0; i < SaveProfileData.size(); ++i)
    {
        stream << SaveProfileData[i] << "\n";
    }

    file.close();

    return true;
}

/** \brief Function that loads profile data and writes it to a vector.
 *
 * Opens the file given by the path.
 * Creates a <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a> from the file.
 * Goes through the file and writes the data into a vector
 * \param LoadProfileData is the vector that will be appended with data.
 * \param profileName, this is needed to find the correct file to write from.
 * \returns true if everything is correct.
 * \see <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a>
 * */

bool Persistence::loadProfile(QVector<QString> &LoadProfileData, QString const &profileName)
{
    QFile file(profileName + ".profile");
    if(!file.open(QFile::ReadOnly))
            return false;

    QTextStream stream(&file);

    while(!stream.atEnd())
    {
        LoadProfileData.append(stream.readLine());
    }

    file.close();

    return true;
}

/** \brief Function that creates a profile.
 *
 * Opens the file given by the path.
 * Creates a <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a> from the file.
 * Goes through the vector and writes the data into the file.
 * \param profileName is the name of the current profile.
 * \param profileData is a vector which has the data that will be written into the file.
 * \returns true if everything is correct.
 * \see <a href="https://doc.qt.io/qt-5/qtextstream.html">QTextStream</a>
 * */

bool Persistence::createProfile(QString const &profileName, QVector<QString>& profileData)
{
    QFile file(profileName + ".profile");
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text))
        return false;

    QTextStream out(&file);

    for(int i = 0; i < profileData.size(); ++i)
    {
        out << profileData[i] << "\n";
    }

    file.close();

    return true;
}

/** \brief Function that scans for a profile.
 *
 * Opens the current working directory.
 * Function uses <a href="https://doc.qt.io/qt-5/qdir.html">QDir</a> to open the directory and go through files.
 * Searches for any file that has the .profile extension.
 * \param current_profile is the name of the current profile.
 * \returns true if everything is correct.
 * \see <a href="https://doc.qt.io/qt-5/qdir.html">QDir</a>
 * */

bool Persistence::scan_for_profile(QString &current_profile)
{
    bool profile_exists = false;
    qDebug() << "szkenneles";
    QDir dir(QDir::currentPath());
    for(auto &entry : dir.entryList(QDir::Files))
    {
        if(entry.split('.').last()=="profile")
        {

            profile_exists = true;
            current_profile = entry.split('.').first();
        }
    }

    return profile_exists;
}


