#include "titlewindow.h"
#include "ui_titlewindow.h"
#include "Game.h"

extern Game * game;


TitleWindow::TitleWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TitleWindow)
{
    ui->setupUi(this);



    // Adding a song at the title screen:


      QMediaPlayer * music = new QMediaPlayer();
      music->setMedia(QUrl("qrc:/audio/Peaceful_Inrtro.wav")); //https://ia802607.us.archive.org/23/items/soundkeeperrecordings-formats/sr002-01-16
      music->setVolume(50);
      music->play();

      show();




}

TitleWindow::~TitleWindow()
{
    delete ui;
}

void TitleWindow::on_pushButton_clicked()
{



    //Effectively links two windows together:

    game = new Game(); //generates game window


    game->show();

    delete this; //deletes the instance of memory allocated to the Title window... allowing us to move after pressing it...



}
