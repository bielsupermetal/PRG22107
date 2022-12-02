#include "player.h"
#include "Notes.h"
#include "ocarinahero.h"

#include <QtWidgets>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <stdlib.h>

Player * keynote_Up = new Player();
Player * keynote_Left = new Player();
Player * keynote_Right = new Player();
Player * keynote_Down = new Player();

extern OcarinaHero * game;

// KEY NOTES PRESSED
void Player::keyPressEvent(QKeyEvent *event){
    QAudioOutput * audioOutput = new QAudioOutput();
    QList<QGraphicsItem *> colliding_note = keynote_Up->collidingItems();
    colliding_note.append(keynote_Left->collidingItems());
    colliding_note.append(keynote_Right->collidingItems());
    colliding_note.append(keynote_Down->collidingItems());

    if (event->key()== Qt::Key_Up){
        //qDebug() << "   >>> key up press";
        //note_Pressed.setBit(0, true);
        QBrush Up;
        Up.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteUp_pressed-rbg.png"));
        keynote_Up->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Up->setPos(x()-330.5, y()+47);
        keynote_Up->setBrush(Up);
        scene()->addItem(keynote_Up);

        QGraphicsItem * item;
        foreach (item, colliding_note){
            Player * notes_item = dynamic_cast<Player*>(item);
            if (notes_item){
                QMediaPlayer * note_sound_D2 = new QMediaPlayer();
                note_sound_D2->setAudioOutput(audioOutput);
                connect(note_sound_D2, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
                note_sound_D2->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Up_D2_short.wav"));
                audioOutput->setVolume(75);
                note_sound_D2->play();
            }
            else{
                //decrease
                game->health->decrease();
                game->streak->streak_equal_zero();
                game->score->streak_equal_zero_s();
                QMediaPlayer * note_sound_miss = new QMediaPlayer();
                note_sound_miss->setAudioOutput(audioOutput);
                connect(note_sound_miss, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
                note_sound_miss->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Song_Error.wav"));
                audioOutput->setVolume(50);
                note_sound_miss->play();

            }
        }
    }
    if (event->key()== Qt::Key_Left){
        //qDebug() << "   >>> key left  press";
        //note_Pressed.setBit(1, true);
        QBrush Left;
        Left.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteLeft_pressed-rbg.png"));
        keynote_Left->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Left->setPos(x()-330.5, y()+73);
        keynote_Left->setBrush(Left);
        scene()->addItem(keynote_Left);
        QMediaPlayer * note_sound_B = new QMediaPlayer();
        note_sound_B->setAudioOutput(audioOutput);
        connect(note_sound_B, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        note_sound_B->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Left_B_short.wav"));
        audioOutput->setVolume(75);
        note_sound_B->play();
    }
    if (event->key()== Qt::Key_Right){
        //qDebug() << "   >>> key right press";
        //note_Pressed.setBit(2, true);
        QBrush Right;
        Right.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteRight_pressed-rbg.png"));
        keynote_Right->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Right->setPos(x()-330.5, y()+99);
        keynote_Right->setBrush(Right);
        scene()->addItem(keynote_Right);
        QMediaPlayer * note_sound_A = new QMediaPlayer();
        note_sound_A->setAudioOutput(audioOutput);
        connect(note_sound_A, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        note_sound_A->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Right_A_short.wav"));
        audioOutput->setVolume(75);
        note_sound_A->play();
    }
    if (event->key()== Qt::Key_Down){
        //qDebug() << "   >>> key down press";
        //note_Pressed.setBit(3, true);
        QBrush Down;
        Down.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteDown_pressed-rbg.png"));
        keynote_Down->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Down->setPos(x()-330.5, y()+125);
        keynote_Down->setBrush(Down);
        scene()->addItem(keynote_Down);
        QMediaPlayer * note_sound_F = new QMediaPlayer();
        note_sound_F->setAudioOutput(audioOutput);
        connect(note_sound_F, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
        note_sound_F->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Down_F_short.wav"));
        audioOutput->setVolume(75);
        note_sound_F->play();
    }
/*
    for (int i = 0; i < note_Pressed.size(); i++) {
         qDebug() << note_Pressed[i];
    }
*/
}

// KEY NOTES RELEASED
void Player::keyReleaseEvent(QKeyEvent *event){
    if (event->key()== Qt::Key_Up){
        //qDebug() << "   >>> key up release";
        //note_Pressed.setBit(0, false);
        scene()->removeItem(keynote_Up);
    }
    if (event->key()== Qt::Key_Left){
        //qDebug() << "   >>> key left release";
        //note_Pressed.setBit(1, false);
        scene()->removeItem(keynote_Left);
    }
    if (event->key()== Qt::Key_Right){
        //qDebug() << "   >>> key right release";
        //note_Pressed.setBit(2, false);
        scene()->removeItem(keynote_Right);
    }
    if (event->key()== Qt::Key_Down){
        //qDebug() << "   >>> key left release";
        //note_Pressed.setBit(3, false);
        scene()->removeItem(keynote_Down);
    }
/*
    for (int i = 0; i < note_Pressed.size(); i++){
         //qDebug() << note_Pressed[i];
    }
*/
}

Player::Player(){
    //note_Pressed.resize(4);
    //note_Pressed.fill(false);
}

void Player::spawn(){
    // create an note
    srand(time(NULL));

    int random_number_up = 1080+ rand() % 726;
    int random_number_left = 1080+ rand() % 635;
    int random_number_right = 1080 + rand() % 587;
    int random_number_down = 1080+ rand() % 643;

    QBrush Up;
    QBrush Left;
    QBrush Right;
    QBrush Down;

    Up.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteUp_pressed-rbg.png"));
    Left.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteLeft_pressed-rbg.png"));
    Right.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteRight_pressed-rbg.png"));
    Down.setTextureImage(QImage("C:/Users/gabri/Desktop/Ocarina Hero/Ocarina_Hero/icons_notes/noteDown_pressed-rbg.png"));

    Notes * note_Up = new Notes();
    note_Up->setPos(x()+random_number_up, y()+47);
    note_Up->setBrush(Up);
    scene()->addItem(note_Up);

    Notes * note_Left= new Notes();
    note_Left->setPos(x()+random_number_left, y()+73);
    note_Left->setBrush(Left);
    scene()->addItem(note_Left);

    Notes * note_Right = new Notes();
    note_Right->setPos(x()+random_number_right, y()+99);
    note_Right->setBrush(Right);
    scene()->addItem(note_Right);

    Notes * note_Down = new Notes();
    note_Down->setPos(x()+random_number_down, y()+125);
    note_Down->setBrush(Down);
    scene()->addItem(note_Down);
}
