#include <QApplication>
#include <QGraphicsView>
#include <QTimer>
#include <QGraphicsTextItem>

#include <QFont>
#include <QColor>
#include <QBrush>
#include <QPushButton>
//#include <QMediaPlayer>
#include <QMovie>
#include <QLabel>
#include <QBrush>
#include <QColor>
#include <QImage>
//#include "Enemy.h"
//#include "Button.h"

#include "Game.h"


extern Game * game;


//-Qgraphics TextItem setplainText() font and textcolor
//GAME IS IN CHARGEOF ALL THE ITEMS TO POP UP

Game::Game(QWidget * parent){

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,1000,1000); //make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QColor("lightgray")); //or if you want a img background do QImage() instead of color


    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(1000,1000);

    //COLOR WINDOW
    //  QColor * color;
    //color->setNamedColor(QColor(255, 0, 0, 127));


    //titleworks
    setWindowTitle("Tax Collector");
    show();


    //adding the button onto the game:

    my_button = new Button(); //a new object of Button


    my_button->setGeometry(QRect(QPoint(900,0) , QSize(100, 100))); //to set the block shown in the app window
    scene->addWidget(my_button); //To add the button onto the scene!



    //CREATE NEW PLAYER

    player = new Player();

     // change the rect from 0x0 (default) to 100x100 pixels
    player->setPos(500,950);

    //negative Y is ^
    // add the item to the scene

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);
    // setting location of the player according to window view

    //SCORE UPDATE
    coinScores = new coinScore();
    scene->addItem(coinScores);
    coinScores->setPos(690, 0);


    score = new Score();
    scene->addItem(score);

    //SPAWN Enemies

    QTimer * timer = new QTimer();

    QObject::connect(timer,SIGNAL(timeout()),player, SLOT(EnemySpawn()));
    timer->start(500);

    for(int i = 0; i<8; i++){ //TESTER for how many things we can spawn
        //   player->spawnWall();
        player->GoalSpawn();

    }

    // Attempts at sound
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/audio/Sad_theme_Song.wav")); //https://ia802607.us.archive.org/23/items/soundkeeperrecordings-formats/sr002-01-16
    music->setVolume(50);
    music->play();

    show();

}
