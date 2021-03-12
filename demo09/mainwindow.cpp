#include "mainwindow.h"
#include <QApplication>
#include <QMimeData>
#include <QDebug>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setAcceptDrops(true);
    m_pText1 = new QLineEdit(this);
    m_pText2 = new QLineEdit(this);
    m_pText3 = new QLineEdit(this);
}

MainWindow::~MainWindow()
{
    delete m_pText1;
    delete m_pText2;
    delete m_pText3;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event ->buttons() & Qt::RightButton)
    {
    if ((QLineF(event->globalPosition(), m_pntPress).length() < QApplication::startDragDistance()) ||
        m_bMimeAdded)
    {
        return;
    }

    m_bMimeAdded = true;
    QDrag *drag = new QDrag(this);
    QMimeData *mime = new QMimeData;
    drag->setMimeData(mime);

    QImage image("/Users/lws/Desktop/截屏2021-03-08\ 14.19.10.png");

    drag->setPixmap(QPixmap::fromImage(image).scaled(30, 40));
    drag->setHotSpot(QPoint(15, 30));

    QByteArray qba;

    QString qstrTemp1 = m_pText1->text();
    QString qstrTemp2 = m_pText2->text();
    bool bTemp;
    if(qstrTemp1.contains("true"))
    {
        bTemp = true;
    }
    else
    {
        bTemp = false;
    }
    ST_INFO stTemp = {bTemp, qstrTemp2.toInt()};
    qba.resize(sizeof(stTemp));
    memcpy(qba.data(), &stTemp, sizeof(stTemp));
    mime->setData(tr("INFO"), qba);

    drag->exec();
    }
}

void MainWindow::mousePressEvent(QMouseEvent *e)
{
    if (e->buttons() & Qt::RightButton)
    {
    m_pntPress = e->globalPosition();
    m_bMimeAdded = false;
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    MainWindow *source = qobject_cast<MainWindow *>(event->source());
    if(source != this)
    {
        if (event->mimeData()->hasFormat("INFO"))
        {
            QByteArray pieceData = event->mimeData()->data("INFO");

            ST_INFO stTemp;

            memcpy(&stTemp, pieceData.data(), sizeof(stTemp));

            QString qstrTemp;
            QTextStream stream(&qstrTemp, QIODevice::WriteOnly);
            stream << "b = " << stTemp.b << " i = " <<stTemp.i;
            m_pText3->setText(qstrTemp);
            event->setDropAction(Qt::MoveAction);
            event->accept();
        }
        else
        {
            event->ignore();
        }
    }
    else
    {
        event->ignore();
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("INFO"))
        event->accept();
    else
        event->ignore();
}

void MainWindow::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("INFO")) {
        event->setDropAction(Qt::MoveAction);
        event->accept();
    } else {
        event->ignore();
    }
}

void MainWindow::resizeEvent(QResizeEvent *e)
{
    m_pText1->setGeometry(0, 0, width() / 2, height() / 4);
    m_pText2->setGeometry(0, height() / 3, width() / 2, height() / 4);
    m_pText3->setGeometry(width() / 2, height() * 2 / 3, width() / 2, height() / 4);
}
