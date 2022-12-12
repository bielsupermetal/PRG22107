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
    if (event->key()== Qt::Key_Up){
        QBrush Up;
        Up.setTextureImage(QImage(":/img/icons_notes/noteUp.png"));
        keynote_Up->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Up->setPos(x()-330.5, y()+47);
        keynote_Up->setBrush(Up);
        scene()->addItem(keynote_Up);
        keyCheckNoteUp();

    }
    if (event->key()== Qt::Key_Left){
        note_Pressed.setBit(1, true);
        QBrush Left;
        Left.setTextureImage(QImage(":/img/icons_notes/noteLeft.png"));
        keynote_Left->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Left->setPos(x()-330.5, y()+73);
        keynote_Left->setBrush(Left);
        scene()->addItem(keynote_Left);
        keyCheckNoteLeft();
    }
    if (event->key()== Qt::Key_Right){
        note_Pressed.setBit(2, true);
        QBrush Right;
        Right.setTextureImage(QImage(":/img/icons_notes/noteRight.png"));
        keynote_Right->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Right->setPos(x()-330.5, y()+99);
        keynote_Right->setBrush(Right);
        scene()->addItem(keynote_Right);
        keyCheckNoteRight();
    }
    if (event->key()== Qt::Key_Down){
        note_Pressed.setBit(3, true);
        QBrush Down;
        Down.setTextureImage(QImage(":/img/icons_notes/noteDown.png"));
        keynote_Down->setRect(0,0,23,23); //change the rect from 0x0 (default) to 23x23 pixels
        keynote_Down->setPos(x()-330.5, y()+125);
        keynote_Down->setBrush(Down);
        scene()->addItem(keynote_Down);
        keyCheckNoteDown();
    }
}

// KEY NOTES RELEASED
void Player::keyReleaseEvent(QKeyEvent *event){
    if (event->key()== Qt::Key_Up){
        note_Pressed.setBit(0, false);
        scene()->removeItem(keynote_Up);
    }
    if (event->key()== Qt::Key_Left){
        note_Pressed.setBit(1, false);
        scene()->removeItem(keynote_Left);
    }
    if (event->key()== Qt::Key_Right){
        note_Pressed.setBit(2, false);
        scene()->removeItem(keynote_Right);
    }
    if (event->key()== Qt::Key_Down){
        //qDebug() << "   >>> key left release";
        note_Pressed.setBit(3, false);
        scene()->removeItem(keynote_Down);
    }
}

void Player::keyCheckNoteUp(){
        if (!collidingItems().empty()){ //remover '!' para testar o erro de tocar fora do tempo (implementação incompleta)
            QMediaPlayer * note_sound_D2 = new QMediaPlayer();
            note_sound_D2->setAudioOutput(audioOutput);
            connect(note_sound_D2, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
            note_sound_D2->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Up_D2_short.wav"));
            audioOutput->setVolume(75);
            note_sound_D2->play();
        }
        else{
            game->health->decrease();
            game->score->streak_equal_zero_s();
            game->streak->streak_equal_zero();
            QMediaPlayer * note_sound_miss = new QMediaPlayer();
            note_sound_miss->setAudioOutput(audioOutput);
            connect(note_sound_miss, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
            note_sound_miss->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Song_Error.wav"));
            audioOutput->setVolume(50);
            note_sound_miss->play();
        }
}


void Player::keyCheckNoteLeft(){
    QMediaPlayer * note_sound_B = new QMediaPlayer();
    note_sound_B->setAudioOutput(audioOutput);
    connect(note_sound_B, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    note_sound_B->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Left_B_short.wav"));
    audioOutput->setVolume(75);
    note_sound_B->play();
}

void Player::keyCheckNoteRight(){
    QMediaPlayer * note_sound_A = new QMediaPlayer();
    note_sound_A->setAudioOutput(audioOutput);
    connect(note_sound_A, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    note_sound_A->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Right_A_short.wav"));
    audioOutput->setVolume(75);
    note_sound_A->play();
}

void Player::keyCheckNoteDown(){
    QMediaPlayer * note_sound_F = new QMediaPlayer();
    note_sound_F->setAudioOutput(audioOutput);
    connect(note_sound_F, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    note_sound_F->setSource(QUrl("qrc:/sounds/sound_ocarina/OOT_Notes_Ocarina_Down_F_short.wav"));
    audioOutput->setVolume(75);
    note_sound_F->play();
}

Player::Player(){
    audioOutput = new QAudioOutput();

    note_Pressed.resize(4);
    note_Pressed.fill(false);
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

    Up.setTextureImage(QImage(":/img/icons_notes/noteUp.png"));
    Left.setTextureImage(QImage(":/img/icons_notes/noteLeft.png"));
    Right.setTextureImage(QImage(":/img/icons_notes/noteRight.png"));
    Down.setTextureImage(QImage(":/img/icons_notes/noteDown.png"));

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
