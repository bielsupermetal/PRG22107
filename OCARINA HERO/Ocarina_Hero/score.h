#ifndef SCORE_H
#define SCORE_H

#include <QtWidgets>

class Score: public QGraphicsTextItem{
public:
    Score(QGraphicsItem * parent=0);
    void increase_score();
    void streak_equal_zero_s();
    int getScore();
    int getStreak();
private:
    int score;
    int streak;
};

#endif // SCORE_H
