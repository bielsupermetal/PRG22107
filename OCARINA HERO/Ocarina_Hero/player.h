#ifndef PLAYER_H
#define PLAYER_H

#include "Notes.h"
#include <QtWidgets>
#include <QMediaPlayer>

class Player:public QObject, public QGraphicsRectItem{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    void keyCheckNoteUp();
    void keyCheckNoteLeft();
    void keyCheckNoteRight();
    void keyCheckNoteDown();

    Notes * note_Up;
    Notes * note_Left;
    Notes * note_Right;
    Notes * note_Down;

    QAudioOutput * audioOutput;

    Player();

    QBitArray note_Pressed;

public slots:
    void spawn();
};

#endif // PLAYER_H
