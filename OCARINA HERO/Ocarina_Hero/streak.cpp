#include "streak.h"
#include <QtWidgets>

Streak::Streak(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the streak to 0
    streak = 0;

    // draw the text
    setPlainText("Streak: " + QString::number(streak));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",10));
}

void Streak::increase_streak(){
    streak++;
    setPlainText(QString("Streak: ") + QString::number(streak));
}


void Streak::streak_equal_zero(){
    streak=0;
    setPlainText(QString("Streak: ") + QString::number(streak));
}


int Streak::getStreak(){
    return streak;
}

