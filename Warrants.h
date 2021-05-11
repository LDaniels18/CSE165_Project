#ifndef WARRANTS_H
#define WARRANTS_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject> //any object using signals (line 12-13) and slots needs this

class Attack: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT //Macro

public:
    Attack(QGraphicsItem * parent=nullptr);
public slots: //a member function that can be accesed by .cpp
    void moveUp(); //refactor, adds definition to bullet.cpp
    void moveDown(); //this is for player

};

#endif // WARRANTS_H
