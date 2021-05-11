
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


//extern  QGraphicsRectItem * rectangle3;

Enemy2::Enemy2(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    //Adding sound when player collides with car(wall)

    resetSound = new QMediaPlayer();
    resetSound->setMedia(QUrl("qrc:/audio/zoom.wav"));
    resetSound->setVolume(25);


    //to generate the walls we see in the game:

     setPixmap(QPixmap(":/sprites/FATCAT.png"));
    int random_number = rand() % 950;
   // int random_enemySize = rand() %100;
    setPos(0,random_number);



    // connect signal to object, bullet's constructor //every timeout bullet will move

        QTimer * timer = new QTimer(this);

   // if(game->score->getScore() >= 2){ //if the score is 1

        connect(timer,SIGNAL(timeout()),this,SLOT(moveLeftToRight()));
        timer->start(105);

}



void Enemy2::moveLeftToRight(){ //we also want different types of walls moving


    QList<QGraphicsItem *> Enemy2Hit = collidingItems();

    for (int i = 0, n = Enemy2Hit.size(); i<n; i++){
        if(typeid(*(Enemy2Hit[i])) == typeid(Player)){

            game->score->decrease();
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


    setPos(x() + 30 , y() ); //move right 30 spaces:

    //when blocks move off the screen delete them waste of memoory walls deleted from memory
    if (pos().y() + pixmap().height() > 1020 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this; //NO MORE LAGGING

    }



} //end of move Down


void Enemy2::moveLeft(){ //we also want different types of walls moving

    setPos(x() + 50 ,y());


//    setPos(x()+ 0, y() + 0);


    setPos(x() + 10,y() + 0);
    //rectangle2->setPos(x(),y()+ 10);

    /*
    //when bullets move off the screen delete them waste of memoory
    if (pos().y() + rect().height() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the
        scene() -> removeItem(this);
        delete this;
//        qDebug() << "Bullet dead";
    }

    */
} //end of move Left
