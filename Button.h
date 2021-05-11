
#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>
#include <QMouseEvent>


//#include <QMainWindow>
#include <QGraphicsRectItem>

#include "Player.h"


class Button: public QPushButton , public QGraphicsRectItem{ //, public QMouseEvent{ // public Player{ //to ensure there is only one Player object

public:

    //https://wiki.qt.io/How_to_Use_QPushButton -- on how to create and use the pushButton feature in Qt
     Button(QPushButton * parent = nullptr); //member object of Button (class) -- as to not to convert between constructors

     //void resetPosition(); //make a function to move the player

private slots:
    void reloadGame();

private:

    QPushButton * my_button;



};
#endif // BUTTON_H
