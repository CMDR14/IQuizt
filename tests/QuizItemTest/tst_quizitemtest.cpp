#include <QtTest>

// add necessary includes here
#include "../../src/model/quizitem.h"

class QuizItemTest : public QObject
{
    Q_OBJECT

public:
    QuizItemTest();
    ~QuizItemTest();

    QuizItem* quiz_item_;

private slots:
    void test_getQuestion();
    void test_getRightAnswer();
    void test_getWrongAnswer1();
    void test_getWrongAnswer2();
    void test_getWrongAnswer3();
    void test_getTrys();
    void test_getCorrects();

    void test_newTry();

    void test_setQuestion();
    void test_setRightAnswer();
    void test_setWrongAnswer1();
    void test_setWrongAnswer2();
    void test_setWrongAnswer3();
    void test_setTrys();
    void test_setCorrects();

};

QuizItemTest::QuizItemTest()
{
    quiz_item_ = new QuizItem("Question", "Right_answer", "Wrong_answer_1",
                              "Wrong_answer_2", "Wrong_answer_3", 10, 8);
}

QuizItemTest::~QuizItemTest()
{

}

void QuizItemTest::test_getQuestion()
{
    QCOMPARE(quiz_item_->getQuestion(), "Question");
}

void QuizItemTest::test_getRightAnswer()
{
    QCOMPARE(quiz_item_->getRightAnswer(), "Right_answer");
}

void QuizItemTest::test_getWrongAnswer1()
{
    QCOMPARE(quiz_item_->getWrongAnswer1(), "Wrong_answer_1");
}

void QuizItemTest::test_getWrongAnswer2()
{
     QCOMPARE(quiz_item_->getWrongAnswer2(), "Wrong_answer_2");
}

void QuizItemTest::test_getWrongAnswer3()
{
    QCOMPARE(quiz_item_->getWrongAnswer3(), "Wrong_answer_3");
}

void QuizItemTest::test_getTrys()
{
    QCOMPARE(quiz_item_->getTrys(), 10);
}

void QuizItemTest::test_getCorrects()
{
    QCOMPARE(quiz_item_->getCorrects(), 8);
}

void QuizItemTest::test_newTry()
{
    //default trys: 10 , corrects: 8 from constructor
    quiz_item_->newTry(false);
    QCOMPARE(quiz_item_->getTrys(), 11);
    QCOMPARE(quiz_item_->getCorrects(), 8);

    quiz_item_->newTry(true);
    QCOMPARE(quiz_item_->getTrys(), 12);
    QCOMPARE(quiz_item_->getCorrects(), 9);

}

void QuizItemTest::test_setQuestion()
{
    quiz_item_->setQuestion("set_Question");
    QCOMPARE(quiz_item_->getQuestion(), "set_Question");
}

void QuizItemTest::test_setRightAnswer()
{
    quiz_item_->setRightAnswer("set_Right_answer");
    QCOMPARE(quiz_item_->getRightAnswer(), "set_Right_answer");
}

void QuizItemTest::test_setWrongAnswer1()
{
    quiz_item_->setWrongAnswer1("set_Wrong_answer_1");
    QCOMPARE(quiz_item_->getWrongAnswer1(), "set_Wrong_answer_1");
}

void QuizItemTest::test_setWrongAnswer2()
{
    quiz_item_->setWrongAnswer2("set_Wrong_answer_2");
    QCOMPARE(quiz_item_->getWrongAnswer2(), "set_Wrong_answer_2");
}

void QuizItemTest::test_setWrongAnswer3()
{
    quiz_item_->setWrongAnswer3("set_Wrong_answer_3");
    QCOMPARE(quiz_item_->getWrongAnswer3(), "set_Wrong_answer_3");
}

void QuizItemTest::test_setTrys()
{
    quiz_item_->setTrys(20);
    QCOMPARE(quiz_item_->getTrys(), 20);
}

void QuizItemTest::test_setCorrects()
{
    quiz_item_->setCorrects(16);
    QCOMPARE(quiz_item_->getCorrects(), 16);
}




QTEST_APPLESS_MAIN(QuizItemTest)

#include "tst_quizitemtest.moc"
