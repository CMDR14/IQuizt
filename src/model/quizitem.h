#ifndef QUIZITEM_H
#define QUIZITEM_H

#include <iostream>


class QuizItem
{
public:
    QuizItem(std::string question, std::string right_answer, std::string wrong_answer_1,
             std::string wrong_answer_2, std::string wrong_answer_3, int trys = 0, int correct = 0)
        : qiuz_item_{ question, right_answer, wrong_answer_1, wrong_answer_2, wrong_answer_3 },
          stat_{ trys, correct} {}

    std::string getQuestion() const;
    std::string getRightAnswer() const;
    std::string getWrongAnswer1() const;
    std::string getWrongAnswer2() const;
    std::string getWrongAnswer3() const;
    int getTrys() const;
    int getCorrects() const;

    void newTry(bool correct);

    void setQuestion(std::string question);
    void setRightAnswer(std::string right_answer);
    void setWrongAnswer1(std::string wrong_answer_1);
    void setWrongAnswer2(std::string wrong_answer_2);
    void setWrongAnswer3(std::string wrong_answer_3);
    void setTrys(int trys);
    void setCorrects(int corrects);

    friend std::ostream& operator<<(std::ostream& os, const QuizItem& q);
    friend std::istream& operator>>(std::istream& is, QuizItem& q);

private:
    std::string qiuz_item_[5];
    int stat_[2];

};

#endif // QUIZITEM_H
