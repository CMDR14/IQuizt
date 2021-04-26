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
bool Persistence::get_quiz_sets(QVector<NameAndPath>& quiz_sets) {
    //quiz_sets = new QVector<NameAndPath>();
    //path_ = "";
    //QDir dir(path_);
    QDir dir(QDir::currentPath());
    //qDebug() << QDir::currentPath();
    for (auto &entry : dir.entryList(QDir::Files)) {
        if(entry.split('.').last()!="quiz")
            continue;

        NameAndPath current;
        current.path = entry;

        QFile file(entry);
        if(!file.open(QFile::ReadOnly))
                return false;

        //qDebug() << "Eljut a stream(&file)ig";
        QTextStream stream(&file);
        //qDebug() << entry;
        current.name = stream.readLine();

        file.close();
        quiz_sets.append(current);
    }
    return true;
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
bool Persistence::saveQuiz(const NameAndPath &NamePath, const QVector<QuizItem> &SaveQuizData)
{
    QFile file(NamePath.path);
    if(!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);

    stream << NamePath.name << "\n";

    for(int i = 0; i < SaveQuizData.size(); ++i)
    {
        //stream << SaveQuizData[i] << Qt::endl;
        stream << SaveQuizData[i] << "\n";
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
bool Persistence::loadQuiz(const NameAndPath &NamePath, QVector<QuizItem> &loadQuizData)
{
    QFile file(NamePath.path);
    if(!file.open(QFile::ReadOnly))
            return false;

    QTextStream stream(&file);
    loadQuizData = QVector<QuizItem>();
    QuizItem tmp("", "", "", "", "");

    stream >> NamePath.name;

    while( !stream.atEnd() ) {
        stream >> tmp;
        loadQuizData.append(tmp);
    }

    file.close();

    return true;
}

bool Persistence::saveProfile(QVector<QString> &SaveProfileData, QString const &profileName)
{
    QFile file(profileName + ".profile"); //vagy .quiz
    if(!file.open(QFile::WriteOnly))
        return false;

    QTextStream stream(&file);

    for(int i = 0; i < SaveProfileData.size(); ++i)
    {
        //stream << SaveProfileData[i] << Qt::endl;
        stream << SaveProfileData[i] << "\n";
    }

    file.close();

    return true;
}

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
