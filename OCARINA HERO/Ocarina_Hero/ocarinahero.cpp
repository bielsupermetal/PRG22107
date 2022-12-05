#include "ocarinahero.h"
#include "player.h"
#include "score.h"
#include "streak.h"
#include "health.h"

#include <QtWidgets>

OcarinaHero::OcarinaHero(QWidget *parent)
    : QWidget(parent){

    QGraphicsScene * scene = new QGraphicsScene();
    QGraphicsPixmapItem *background = scene->addPixmap(QPixmap(":/img/ocarina_tab.png"));
    scene->addItem(background);

    QBrush Ocarina_focus;
    Ocarina_focus.setTextureImage(QImage(":/img/icons_notes/ocarina_item.png"));

    //create key notes
    keynotes = new Player();
    keynotes->setRect(0,0,35,32); //change the rect from 0x0 (default) to 35x32 pixels
    keynotes->setPos(x()+420, y()+5);
    keynotes->setBrush(Ocarina_focus);
    scene->addItem(keynotes);

    //make key notes focusable
    keynotes->setFlag(QGraphicsItem::ItemIsFocusable);
    keynotes->setFocus();

    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    //create the score//streak/health
    score = new Score();
    scene->addItem(score);

    streak = new Streak();
    streak->setPos(x(),y()+20);
    scene->addItem(streak);

    health = new Health();
    health->setPos(x()+988, y()+5);
    scene->addItem(health);

    view->setFixedSize(1080,200);

    QHBoxLayout * mainLayout = new QHBoxLayout;
    mainLayout->addWidget(view);
    setFixedSize(1080,200);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(mainLayout);

    // spawn notes
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()), keynotes, SLOT(spawn()));
    timer->start(2000);
}

OcarinaHero::~OcarinaHero(){

}
