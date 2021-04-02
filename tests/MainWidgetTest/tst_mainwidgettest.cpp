#include <QtTest>

// add necessary includes here
#include "../../src/view/mainwidget.cpp"

class MainWidgetTest : public QObject
{
    Q_OBJECT

public:
    MainWidgetTest();
    ~MainWidgetTest();
    MainWidget* mainwidget;

private slots:
    void test_case1();

};

MainWidgetTest::MainWidgetTest()
{
    mainwidget = new MainWidget();
}

MainWidgetTest::~MainWidgetTest()
{

}

void MainWidgetTest::test_case1()
{
    QCOMPARE(1,1);
}

QTEST_APPLESS_MAIN(MainWidgetTest)

#include "tst_mainwidgettest.moc"
