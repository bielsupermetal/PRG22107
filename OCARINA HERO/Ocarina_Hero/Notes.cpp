#include "Notes.h"
#include "ocarinahero.h"
#include "score.h"
#include "health.h"
#include "streak.h"

#include <QMediaPlayer>
#include <QAudioOutput>
#include <QtWidgets>
#include <stdlib.h>

extern OcarinaHero * game;
extern Player * keynote_up;

Notes::Notes(): QObject(), QGraphicsRectItem(){
    // drew the notes
    setRect(0,0,23,23);

    // connect
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Notes::move(){
    //if note collide with keynote, destroy note.
    QList<QGraphicsItem *> colliding_note = collidingItems();
    foreach (QGraphicsItem * i, colliding_note){
        if (i->type() == 3){
            //increase the score
            game->score->increase_score();
            game->streak->increase_streak();
            delete this;
            return;
        }
    }

    // move notes L<-R
    setPos(x()-10,y());
    if(pos().x() + rect().height() < 0){
        //decrease the health
        game->health->decrease();
        game->score->streak_equal_zero_s();
        game->streak->streak_equal_zero();
        QMediaPlayer * note_sound_miss = new QMediaPlayer();
        QAudioOutput * audioOutput = new QAudioOutput();
        note_sound_miss->setAudioOutput(audioOutput);
        connect(note_sound_miss, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        note_sound_miss->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Song_Error.wav"));
        audioOutput->setVolume(50);
        note_sound_miss->play();
        scene()->removeItem(this);
        delete this;
    }

}
