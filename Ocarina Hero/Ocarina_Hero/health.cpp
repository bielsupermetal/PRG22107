#include "health.h"

#include <QtWidgets>

Health::Health(QGraphicsItem *parent): QGraphicsRectItem(parent){
    // initialize the health
    heart = 3;


    full_health.setTextureImage(QImage(":/img/health/full_health.png"));
    setRect(0,0,87,25);
    setBrush(full_health);

    one_dmg.setTextureImage(QImage(":/img/health/one_dmg.png"));
    two_dmg.setTextureImage(QImage(":/img/health/two_dmg.png"));
    game_over.setTextureImage(QImage(":/img/health/game_over.png"));

}

void Health::decrease(){
    heart--;
    if (heart == 2)
        setBrush(one_dmg);
    else if (heart == 1)
        setBrush(two_dmg);
    else
        setBrush(game_over);
    update();
}

int Health::getHeart(){
    return heart;
}
