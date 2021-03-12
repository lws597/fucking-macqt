#include "rotatedemo.h"

#include <QtCore/qmath.h>
#include <QDebug>

RotateDemo::RotateDemo(QWidget *parent):
    QWidget(parent)
{
    initUI();
    initConnect();
}

void RotateDemo::initUI()
{
    loadPaintBuffer();

    setFixedSize(QSize(800, 800));
    qDebug() << paintBuffer.size();

    m_rotateAlpha = 0;
    m_rotateTimer = nullptr;
    m_rotateTimer = new QTimer(this);
}

void RotateDemo::initConnect()
{
    connect(m_rotateTimer, &QTimer::timeout, this, &RotateDemo::onRotateTimer);
}

void RotateDemo::loadPaintBuffer()
{
    QPixmap tmp(":/res/rotate-image.png");
    int width = qSqrt(tmp.width() * tmp.width() + tmp.height() * tmp.height());
    QPixmap result(width, width);
    result.fill(Qt::black);

    QPainter painter(&result);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.drawPixmap(QRect(width / 2 - tmp.width() / 2,
                             width / 2 - tmp.height() / 2,
                             tmp.width(),
                             tmp.height()), tmp, QRect());

    paintBuffer = result;
}

void RotateDemo::showEvent(QShowEvent *)
{
    if(m_rotateTimer && !m_rotateTimer->isActive())
        m_rotateTimer->start(20);
}

void RotateDemo::hideEvent(QHideEvent *)
{
    if(m_rotateTimer && m_rotateTimer->isActive())
        m_rotateTimer->stop();
}

void RotateDemo::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
    painter.setPen(Qt::black);
    painter.setBrush(Qt::black);
    painter.drawRect(rect());

    painter.translate(width() / 2, height() / 2);
    painter.rotate(m_rotateAlpha);
    painter.drawPixmap(QRect(-width() / 2,
                             -height() / 2,
                             width(),
                             height()), paintBuffer, QRect());

    QString show_text = "θ = %1°";
    painter.resetTransform();
    painter.setPen(Qt::red);
    painter.setBrush(Qt::red);
    painter.setFont(QFont("宋体", 15, QFont::Bold, true));
    painter.drawText(QPoint(0, 100), show_text.arg(m_rotateAlpha));
}

void RotateDemo::onRotateTimer()
{
    m_rotateAlpha += 3.0;
    update();
    if(m_rotateAlpha >= 360) m_rotateAlpha = 0;
}
