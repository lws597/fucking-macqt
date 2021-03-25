#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_lTouchPoints(QList<QTouchEvent::TouchPoint>())
    , m_bSwipe(false)
    , m_bPinch(false)
    , m_bTap(false)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::event(QEvent* e)
{
    switch(e->type())
        {
        case QEvent::TouchBegin:
        {
            QTouchEvent* event = static_cast<QTouchEvent*>(e);
            m_lTouchPoints = event->points();
        }
        case QEvent::TouchUpdate:
        {
            QTouchEvent* event = static_cast<QTouchEvent*>(e);
            m_lTouchPoints = event->touchPoints();
            for (int i = 0; i < m_lTouchPoints.count(); i++) {
                QTouchEvent::TouchPoint touchPoint = m_lTouchPoints[i];
                m_bSwipe = touchPoint.normalizedPos().x() > touchPoint.startNormalizedPos().x();
            }
            if (m_lTouchPoints.count() == 2) {
                qreal testValue =
                    QLineF(m_lTouchPoints[0].normalizedPos(), m_lTouchPoints[1].normalizedPos()).length() /
                    QLineF(m_lTouchPoints[0].startNormalizedPos(), m_lTouchPoints[1].startNormalizedPos()).length();
                m_bPinch = testValue < 1;
            }
        }
        case QEvent::TouchEnd:
        {
            QTouchEvent* event = static_cast<QTouchEvent*>(e);
            if (event->touchPointStates() & Qt::TouchPointReleased) {
                ui->swipeCB->setChecked(m_bSwipe);
                ui->pinchCB->setChecked(m_bPinch);
                ui->tapCB->setChecked(m_bTap);
            }
        }
        default: break;
    }
    return QWidget::event(e);
}
