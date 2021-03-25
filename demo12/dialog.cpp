#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
    , m_lTouchPoints(QList<QTouchEvent::TouchPoint>())
    , m_bSwipe(false)
    , m_bPinch(false)
    , m_bTap(false)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_AcceptTouchEvents);
}

Dialog::~Dialog()
{
    delete ui;
}

bool Dialog::event(QEvent* e)
{
    switch (e->type()) {
        case QEvent::TouchBegin:
        {
            QTouchEvent* event = static_cast<QTouchEvent*>(e);
            m_lTouchPoints = event->touchPoints();
            qDebug() << "start " << m_lTouchPoints[0].pressure();
        } break;
        case QEvent::TouchUpdate:
        {
            ui->swipeCB->setChecked(false);
            QTouchEvent* event = static_cast<QTouchEvent*>(e);
            m_lTouchPoints = event->touchPoints();
            for (int i = 0; i < m_lTouchPoints.count(); i++) {
                QTouchEvent::TouchPoint touchPoint = m_lTouchPoints[i];
                m_bSwipe = touchPoint.pos().x() > touchPoint.lastPos().x();
            }
            if (m_lTouchPoints.count() == 2) {
                qreal length1 = QLineF(m_lTouchPoints[0].pos(), m_lTouchPoints[1].pos()).length();
                qreal length2 = QLineF(m_lTouchPoints[0].startPos(), m_lTouchPoints[1].startPos()).length();
                m_bPinch = length1 < length2;
                qDebug() << length1;
                qDebug() << length2;
            }
            if (event->touchPointStates() & Qt::TouchPointStationary ||
                event->touchPointStates() & Qt::TouchPointReleased) {
                ui->swipeCB->setChecked(m_bSwipe);
                ui->pinchCB->setChecked(m_bPinch);
                ui->tapCB->setChecked(m_bTap);
            }
            qDebug() << "update " << m_lTouchPoints[0].pressure();
        } break;
        case QEvent::TouchEnd:
        {
            ui->swipeCB->setChecked(m_bSwipe);
            ui->pinchCB->setChecked(m_bPinch);
            ui->tapCB->setChecked(m_bTap);
            qDebug() << "end " << m_lTouchPoints[0].pressure();
        } break;
        default: break;
    }
    return QWidget::event(e);
}
