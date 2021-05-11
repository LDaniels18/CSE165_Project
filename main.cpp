

#include <QApplication>
#include "Game.h"
#include "titlewindow.h"



Game * game;//CLASS game is from game.h is now parenting main.cpp
TitleWindow * title;
 //StartWindow title;

int main(int argc, char *argv[]){

    //In order to start the Game:

   QApplication Title(argc, argv);

   title = new TitleWindow();

   title->show();

   return Title.exec();






}
