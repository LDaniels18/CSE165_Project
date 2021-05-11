#include "Game.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent)
{ // this will have a parent too

    score = 0; //intitially starting at 0

    //draw text - onlyworks when cpp has Qgraphics text Item

    setPlainText("Served Score: " + QString::number(score));
    setDefaultTextColor(Qt::black);

    setFont(QFont("Times New Roman", 20));
}

void Score::increase()
{

    //###############################################################
    //IDEA:
    //lets increase when we hit the circle?
    //###############################################################

    score++;

    //if(score == 4){

        //delete this;
  // }

    setPlainText(QString("Served Score: ") + QString::number(score)); // Score: 1


}

void Score::decrease()
{
    score--;
    setPlainText(QString("Served Score: ") + QString::number(score)); //decreasing the score
}

int Score::getScore()
{
    return score; //gathering our score
}
