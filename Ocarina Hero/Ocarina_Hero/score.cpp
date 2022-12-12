#include "score.h"
#include <QtWidgets>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score and streak to 0
    score = 0;
    streak = 0;

    // draw the text
    setPlainText("Score: " + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",14));
}

void Score::increase_score(){
    streak++;
    if (streak < 10)
        score++;
    else if (streak < 20)
        score += 2;
    else if (streak < 30)
        score += 3;
    else if (streak >= 30)
        score += 4;

    setPlainText(QString("Score: ") + QString::number(score));
}


void Score::streak_equal_zero_s(){
    streak=0;
}


int Score::getScore(){
    return score;
}




