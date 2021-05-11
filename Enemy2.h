#ifndef ENEMY2_H
#define ENEMY2_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this
#include <QMediaPlayer>

class Enemy2: public QObject,public QGraphicsPixmapItem{  //, public Player{
    Q_OBJECT; //Macro

    //making new objects to represent rectangles
    QGraphicsRectItem * rectangle1;
    QGraphicsRectItem * rectangle2;
    //QGraphicsRectItem * rectangle3;



public:
    Enemy2(QGraphicsItem * parent = 0);
//    QMediaPlayer *resetSound;

public slots: //a member function that can be accesed by .cpp all of these slots are attributes that can change the direction and type of but will not create new types
    void moveLeftToRight();
    void moveLeft();

private:
QMediaPlayer *resetSound;

    //refactor, adds definition to bullet.cpp
};


#endif // ENEMY2_H
