#include <QtTest>

// add necessary includes here
#include "../../src/persistence/persistence.cpp"

class PersistenceTest : public QObject
{
    Q_OBJECT

public:
    PersistenceTest();
    ~PersistenceTest();
    Persistence* persistence;

private slots:
    void test_case1();

};

PersistenceTest::PersistenceTest()
{
    persistence = new Persistence();
}

PersistenceTest::~PersistenceTest()
{

}

void PersistenceTest::test_case1()
{
    QCOMPARE(1,1);
}

QTEST_APPLESS_MAIN(PersistenceTest)

#include "tst_persistencetest.moc"
