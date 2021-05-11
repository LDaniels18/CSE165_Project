
#include "Game.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsItem>
#include <QObject>
#include <QList>
#include <stdlib.h> //rand()

extern coinScore* score;
extern Game * game; //ALLOWS WALLS TO DESTROY PLAYER



extern  QGraphicsRectItem * rectangle1;
extern Button * my_button;
extern QGraphicsRectItem * rectangle2;



Enemy1::Enemy1(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //Adding sound when player collides with car(wall)

    resetSound = new QMediaPlayer();

    resetSound->setMedia(QUrl("qrc:/audio/zoom.wav"));
    resetSound->setVolume(25);


    //to generate the walls we see in the game:

  setPixmap(QPixmap(":/sprites/FATCAT2.png"));

    int random_number = rand() % 950;
   // int random_enemySize = rand() %100;
    setPos(900,random_number);


  QTimer * timer = new QTimer(this);
    //if(game->score->getScore()>=0){ //if a player's score is 0:
        connect(timer,SIGNAL(timeout()),this,SLOT(moveDown()));
      timer->start(75);

    }



void Enemy1::moveDown(){ //we also want different types of walls moving

    QList<QGraphicsItem *> Enemy1Hit = collidingItems();

    for (int i = 0, n = Enemy1Hit.size(); i<n; i++){
        if(typeid(*(Enemy1Hit[i])) == typeid(Player)){
            game->score->decrease();
            game->coinScores->decrease();
            game->player->resetPlayer();

            if (resetSound->state() == QMediaPlayer::PlayingState){
                resetSound->setPosition(0);
            }

            else if (resetSound->state() == QMediaPlayer::StoppedState){ //this will decide when music will play
                resetSound->play();
            }

            delete this;

            return;//no memory errors
        }
    }

    setPos(x() - 30, y() );

    //when blocks move off the screen delete them waste of memoory walls deleted from memory
    if (pos().y() + pixmap().height() > 1020 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this; //NO MORE LAGGING

    }
} //end of move Down


void Enemy1::moveLeft(){ //we also want different types of walls moving

    setPos(x() + 50 ,y());


    setPos(x() + 10,y() + 0);

} //end of move Left
