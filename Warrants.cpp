//#include "Bullet.h"
#include "Game.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QDebug>
#include <QList>
//#include <Enemy.h>
#include <QLabel>


extern Game * game; // there is an external global object called game

Attack::Attack(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){ //every time space is pressed

    QTimer * timerUp = new QTimer();
    connect(timerUp,SIGNAL(timeout()),this,SLOT(moveUp())); // connect signal to object, bullet's constructor //every timeout bullet will move


    timerUp->start(100); //every 50 ms timeout signals move to move bullet
}

// Score::int count= 0;


void Attack::moveUp(){
    //before anything check if bullet collides with an enemy
    //if bullet collides with enemy destroy both

    QList<QGraphicsItem *> colliding_items = collidingItems(); //we cand find what the bullet is colliding with


    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy1)){
            //remove both
            //              // count++;
            game->score->increase();


            scene() ->removeItem(colliding_items[i]);
            scene() ->removeItem(this);
            //remove from heap
            delete colliding_items[i];
            delete this; //bullet
            //                qDebug()<<count;
            return;//no memory errors
        }
    }

    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy2)){
            //remove both
            //              // count++;
            game->score->increase();


            scene() ->removeItem(colliding_items[i]);
            scene() ->removeItem(this);
            //remove from heap
            delete colliding_items[i];
            delete this; //bullet
            //                qDebug()<<count;
            return;//no memory errors
        }
    }

    setPos(x(),-10); //direction of bullet coordinates

    //when bullets move off the screen delete them waste of memoory
    if (pos().y() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the bullet moves offscreen it is deleted
        scene() -> removeItem(this);
        delete this;

    }
}

void Attack::moveDown()
{
    QList<QGraphicsItem *> colliding_items = collidingItems(); //we cand find what the bullet is colliding with


    for (int i = 0, n = colliding_items.size(); i<n; i++){
        if(typeid(*(colliding_items[i])) == typeid(Enemy1)){
            //remove both
            // count++;
            game->score->increase();


            scene() ->removeItem(colliding_items[i]);
            scene() ->removeItem(this);
            //remove from heap
            delete colliding_items[i];
            delete this; //bullet

            return;//no memory errors
        }
    }

    setPos(x(),10); //direction of warrant coordinates

    if (pos().y() < 0 ){// 0 is origin for y (Topleft)// with rect().height()we now have that after the size of the book moves offscreen it is deleted
        scene() -> removeItem(this);
        delete this;
    }
}



