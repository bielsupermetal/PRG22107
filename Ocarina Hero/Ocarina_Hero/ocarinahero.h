#ifndef OCARINAHERO_H
#define OCARINAHERO_H

#include <QtWidgets>
#include <vector>

#include "player.h"
#include "score.h"
#include "streak.h"
#include "health.h"

class OcarinaHero : public QWidget{
    Q_OBJECT

public:
    OcarinaHero(QWidget *parent = nullptr);
    Score * score;
    Streak * streak;
    Health * health;
    Player * keynotes;
    ~OcarinaHero();

private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsPixmapItem *background;
    QTimer *timer;

    QHBoxLayout *mainlayout;
    QBrush Ocarina_focus;

};
#endif // OCARINAHERO_H
