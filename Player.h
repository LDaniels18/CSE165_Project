#ifndef PLAYER_H
#define PLAYER_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>

#include <QGraphicsEllipseItem>

#include <QGraphicsItem>
#include <QObject>
#include <QMediaPlayer>

//#include "Game.h"

class Player: public QObject,  public QGraphicsPixmapItem{ //changed to pixmap item
    Q_OBJECT

public:
        Player(QGraphicsItem * parent=0); // now our item is a pointer we can manipulate
    void keyPressEvent(QKeyEvent * event);

public slots:
    void EnemySpawn(); //spawn is an event that will be created by extension
    void GoalSpawn();
    void resetPlayer();

private:
     QGraphicsPixmapItem* characterSprite;
    QMediaPlayer* goalSound;

};

#endif // PLAYER_H
