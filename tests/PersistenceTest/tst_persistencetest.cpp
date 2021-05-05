#include <QtTest>
#include <QFile>
#include <QDir>
#include <QTextStream>

// add necessary includes here
#include "../../src/persistence/persistence.h"

class PersistenceTest : public QObject
{
    Q_OBJECT
public:
    PersistenceTest();
    ~PersistenceTest();
    Persistence* persistence;

private slots:
    void test_get_quiz_sets_for_null_file();
    void test_get_quiz_sets_for_existing_file();
    void test_wrong_file_name();

};

PersistenceTest::PersistenceTest()
{
    persistence = new Persistence();
}

PersistenceTest::~PersistenceTest()
{

}

void PersistenceTest::test_get_quiz_sets_for_null_file()
{
    QVector<NameAndPath> sets;

    persistence->get_quiz_sets(sets, QDir::currentPath());

    QCOMPARE(sets.count(),0);
}

void PersistenceTest::test_get_quiz_sets_for_existing_file()
{
    QFile file(QDir::currentPath() + "/test.quiz");
    if(!file.open(QFile::WriteOnly))
            QCOMPARE(1,0);

    QTextStream stream(&file);

    stream << "Test line writed" << "\n";

    file.close();

    QVector<NameAndPath> sets;
    persistence->get_quiz_sets(sets, QDir::currentPath());

    QCOMPARE(sets.count(),1);
    QCOMPARE(sets.at(0).name, "Test line writed");
    QCOMPARE(sets.at(0).path,"test.quiz");
    file.remove();

}



void PersistenceTest::test_wrong_file_name()
{
    QFile file(QDir::currentPath() + "/test.text");
    if(!file.open(QFile::WriteOnly))
            QCOMPARE(1,0);

    QTextStream stream(&file);

    stream << "Test" << "\n";

    file.close();

    QVector<NameAndPath> sets;
    persistence->get_quiz_sets(sets, QDir::currentPath());


    QCOMPARE(sets.count(),0);

    file.remove();
}


QTEST_APPLESS_MAIN(PersistenceTest)

#include "tst_persistencetest.moc"
