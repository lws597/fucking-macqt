#ifndef ANIMATIONDEMO_H
#define ANIMATIONDEMO_H

#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <QGraphicsPixmapItem>

#define WIDGET 100
#define HEIGHT 100

class MyLabel : public QLabel, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(int pos_x READ getX WRITE setX)
    Q_PROPERTY(int pos_y READ getY WRITE setY)

public:
    int pos_x, pos_y;

public:
    MyLabel(QWidget *parent = nullptr): QLabel(parent){}
    void setX(int xx){ move(xx, QLabel::y()); }
    void setY(int yy){ move(QLabel::x(), yy); }
    int getX(){ return pos_x; }
    int getY(){ return pos_y; }


};

class AnimationDemo : public QWidget
{
public:
    AnimationDemo(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *);

private:
    void initUI();
    void initConnect();
    void startAnimation();

private:
    MyLabel *m_pBall;
    QSize m_ballSize;
};

#endif // ANIMATIONDEMO_H
