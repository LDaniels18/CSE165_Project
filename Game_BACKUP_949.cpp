#include <QApplication>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QGraphicsEllipseItem>
#include <QFont>
#include <QColor>
#include <QPushButton>

#include "Enemy.h"
#include "Game.h"
//#include "Button.h"

extern Game * game;
//-Qgraphics TextItem setplainText() font and textcolor
//GAME IS IN CHARGEOF ALL THE ITEMS TO POP UP

Game::Game(QWidget * parent){



    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)

    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //titleworks
         setWindowTitle("Final Game");

<<<<<<< HEAD
         show();
=======

    //adding the button onto the game:

        my_button = new Button; //a new object of Button

       // my_button->showMaximized();
        my_button->setGeometry(QRect(QPoint(700,0) , QSize(100, 100))); //to set the block shown in the app window
        scene->addWidget(my_button); //To add the button onto the scene!!
>>>>>>> a850f2dd99d5084a47b7bcf14255c5db9ce3351d

    //CREATE NEW PLAYER

    player = new Player();
    player->setRect(0,0,30,30); // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(400,500);
    // add the item to the scene


    // make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);
   // setting location of the player according to window view

//SCORE UPDATE
     score = new Score();
     scene->addItem(score);

    //SPAWN enemy
    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player, SLOT(spawn()));
   timer -> start(1000);//makes it so rectangles appear every 1 second


//   parent = new QWidget(this);
//  setGeometry(0, 0, 800, 600);
//   setStyleSheet("background-color:lightGray");



}
