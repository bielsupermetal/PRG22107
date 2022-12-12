#ifndef STREAK_H
#define STREAK_H


#include <QtWidgets>

class Streak: public QGraphicsTextItem{
public:
    Streak(QGraphicsItem * parent=0);
    void increase_streak();
    void streak_equal_zero();
    int getStreak();
private:
    int streak;
};

#endif // SCORE_H
