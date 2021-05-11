#ifndef COINSCORE_H
#define  COINSCORE_H

#include <QGraphicsTextItem>


class coinScore: public QGraphicsTextItem{
public:
    coinScore(QGraphicsItem * parent= 0);
    void increase();
    void decrease();
    int getScore();

private:
int score;
};

#endif //  COINSCORE_H
