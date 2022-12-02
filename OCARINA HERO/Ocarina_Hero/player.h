#ifndef PLAYER_H
#define PLAYER_H

#include <QtWidgets>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    Player();

    //QBitArray note_Pressed;

public slots:
    void spawn();
};

#endif // PLAYER_H
