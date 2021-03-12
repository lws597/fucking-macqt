#include "animationdemo.h"

#include <QDebug>
#include <QPropertyAnimation>
#include <QParallelAnimationGroup>
#include <QEasingCurve>

AnimationDemo::AnimationDemo(QWidget *parent):
    QWidget(parent)
{
    initUI();
    initConnect();
}

void AnimationDemo::initUI()
{
    setFixedSize(QSize(WIDGET, HEIGHT));

    m_ballSize = QSize(20, 20);
    m_pBall = new MyLabel(this);
    m_pBall->setFixedSize(m_ballSize);
    m_pBall->setY(0);
    m_pBall->setX(0);
    QString ballStyleSheet = "background: red;"
                             "border-radius: %1px;";
    m_pBall->setStyleSheet(ballStyleSheet.arg(m_ballSize.width() / 2));
}

void AnimationDemo::initConnect()
{
    startAnimation();
}

void AnimationDemo::startAnimation()
{
    qDebug() << "start!!!";
    QPropertyAnimation *animation1 = new QPropertyAnimation(m_pBall, "pos_x", this);
    animation1->setDuration(5000);
    animation1->setStartValue(0);
    animation1->setEndValue(width() - m_ballSize.width());

    QPropertyAnimation *animation2 = new QPropertyAnimation(m_pBall, "pos_y", this);
    animation2->setDuration(5000);
    animation2->setStartValue(0);
    animation2->setEndValue(height() - m_ballSize.height());
    animation2->setEasingCurve(QEasingCurve::InCubic);

    QParallelAnimationGroup *animationGroup = new QParallelAnimationGroup(this);
    animationGroup->addAnimation(animation1);
    animationGroup->addAnimation(animation2);

    animationGroup->start();
}

void AnimationDemo::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(rect());
}
