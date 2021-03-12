#ifndef ROTATEDEMO_H
#define ROTATEDEMO_H

#include <QWidget>
#include <QPainter>
#include <QPaintEvent>
#include <QPixmap>
#include <QTimer>

class RotateDemo : public QWidget
{
    Q_OBJECT
public:
    RotateDemo(QWidget *parent = nullptr);

private:
    void initUI();
    void initConnect();
    void loadPaintBuffer();

protected:
    void showEvent(QShowEvent *);
    void hideEvent(QHideEvent *);
    void paintEvent(QPaintEvent *);

private slots:
    void onRotateTimer();

private:
    QPixmap paintBuffer;
    QTimer *m_rotateTimer;

    qreal m_rotateAlpha;
};

#endif // ROTATEDEMO_H
