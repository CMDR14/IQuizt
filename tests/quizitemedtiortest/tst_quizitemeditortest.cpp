#include <QtTest>
#include <QCoreApplication>
#include <QtWidgets>
#include <QDebug>

#include "../../src/view/quizitemeditor.h"

class QuizItemEditorTest : public QObject
{
    Q_OBJECT


public:
    QuizItemEditorTest();
    ~QuizItemEditorTest();
    QuizItemEditor* qie;
    QuizItem* qi;

private slots:
    void initTestCase();
    void test_case_QuizItem();
    void test_case_getQuestion();
    void test_case_getRightAnswer();
    void test_case_getWrongAnswer1();
    void test_case_getWrongAnswer2();
    void test_case_getWrongAnswer3();
    void test_case_getTrys();
    void test_case_getCorrects();
    void test_gui_lineEdit();
    //void test_gui_saveButton();
    void test_layout_GridLayout();

};

void QuizItemEditorTest::initTestCase()
{
    qi = new QuizItem("Hány éves a kapitány?","42", "100", "2", "1");
    qie = new QuizItemEditor(qi);
    //connect(qie->save_button_, &QPushButton::clicked, qie, &QuizItemEditor::on_save);
}

QuizItemEditorTest::QuizItemEditorTest()
{

}

QuizItemEditorTest::~QuizItemEditorTest()
{

}

void QuizItemEditorTest::test_case_QuizItem()
{
    QVERIFY(qi != NULL);
}

void QuizItemEditorTest::test_case_getQuestion()
{
    qi->setQuestion("Melyik évben volt az '56-os forradalom?");
    QVERIFY(qi->getQuestion() == "Melyik évben volt az '56-os forradalom?");
    qi->setQuestion("Hány éves a kapitány?");
    QVERIFY(qi->getQuestion() == "Hány éves a kapitány?");
}

void QuizItemEditorTest::test_case_getRightAnswer()
{
    QVERIFY(qi->getRightAnswer() == "42");
}

void QuizItemEditorTest::test_case_getWrongAnswer1()
{
    QVERIFY(qi->getWrongAnswer1() == "100");
}

void QuizItemEditorTest::test_case_getWrongAnswer2()
{
    QVERIFY(qi->getWrongAnswer2() == "2");
}

void QuizItemEditorTest::test_case_getWrongAnswer3()
{
    QVERIFY(qi->getWrongAnswer3() == "1");
}

void QuizItemEditorTest::test_case_getTrys()
{
   qi->setTrys(5);
   QVERIFY(qi->getTrys() == 5);
}

void QuizItemEditorTest::test_case_getCorrects()
{
   qi->setCorrects(5);
   QVERIFY(qi->getCorrects() == 5);
}
/*
void QuizItemEditorTest::test_gui_saveButton()
{
    qie->new_str_[0] = "Mikor volt a '48-as szabadságharc?";
    qie->new_str_[1] = "48-ban";
    qie->new_str_[2] = "49-ben";
    qie->new_str_[3] = "50-ben";
    qie->new_str_[4] = "47-ben";

    qie->new_int_[0] = 6;
    qie->new_int_[1] = 6;

    QSignalSpy spy(qie->save_button_, &QPushButton::clicked);
    Q_ASSUME(connect(qie->save_button_, &QPushButton::clicked, qie, &QuizItemEditor::on_save));
    QTest::mouseClick(qie->save_button_, Qt::AllButtons);

    QCOMPARE(spy.count(),1);

    qDebug() << qie->quiz_item_->getQuestion();
    qDebug() << qie->new_str_[0];

    //QVERIFY(qie->quiz_item_->getQuestion() == qie->new_str_[0]);
}
*/
void QuizItemEditorTest::test_layout_GridLayout()
{
    QVERIFY(qie->grid_layout_->itemAtPosition(0,0)->widget() == qie->question_line_);
    QVERIFY(qie->grid_layout_->itemAtPosition(1,0)->widget() == qie->right_line_);
    QVERIFY(qie->grid_layout_->itemAtPosition(1,1)->widget() == qie->wrong1_line_);
    QVERIFY(qie->grid_layout_->itemAtPosition(2,0)->widget() == qie->wrong2_line_);
    QVERIFY(qie->grid_layout_->itemAtPosition(2,1)->widget() == qie->wrong3_line_);

}

void QuizItemEditorTest::test_gui_lineEdit()
{
    //qDebug() << qie->question_line_->text();
    qie->question_line_->setText("Mikor volt a '48-as szabadságharc?");
    QVERIFY(qie->question_line_->text() == "Mikor volt a '48-as szabadságharc?"); //IF IT WORKS FOR ONE, IT WORKS FOR ALL
}



QTEST_MAIN(QuizItemEditorTest)

#include "tst_quizitemeditortest.moc"
