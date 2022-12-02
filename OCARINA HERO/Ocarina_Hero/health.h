#ifndef HEALTH_H
#define HEALTH_H

#include <QtWidgets>

class Health: public QGraphicsRectItem{
public:
    Health(QGraphicsItem * parent=0);
    void decrease();
    int getHeart();

private:
    int heart;
    QBrush full_health;
    QBrush one_dmg;
    QBrush two_dmg;
    QBrush game_over;
};

#endif // SCORE_H
