#ifndef NOTES_H
#define NOTES_H

#include "health.h"
#include <QtWidgets>

class Notes : public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    Notes();
public slots:
    void move();
private:
    int health = 3;
    Health * health_img;
    QBrush full_health;
    QBrush one_dmg;
    QBrush two_dmg;
    QBrush game_over;
};

#endif // NOTES_H
