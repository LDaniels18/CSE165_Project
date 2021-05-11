#include "Game.h"
#include <QFont>

coinScore::coinScore(QGraphicsItem *parent): QGraphicsTextItem(parent)
{ // this will have a parent too

    score = 0; //intitially starting at 0

    //draw text - onlyworks when cpp has Qgraphics text Item

    setPlainText("Taxes Attained: " + QString::number(score));
    setDefaultTextColor(Qt::black);


    setFont(QFont("Times New Roman", 20));
}

void coinScore::increase()
{

    //###############################################################
    //IDEA:
    //lets increase when we hit the circle?
    //###############################################################

    score++;

    if(score == 4){

        delete this; //ending the game
    }

    setPlainText(QString("Taxes Attained: ") + QString::number(score)); // Score: 1


}

void coinScore::decrease()
{
    score=0;
    setPlainText(QString("Taxes Attained: ") + QString::number(score)); //decreasing the score
}

int coinScore::getScore()
{
    return score; //gathering our score
}
