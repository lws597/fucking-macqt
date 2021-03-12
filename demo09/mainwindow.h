#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDrag>
#include <QDropEvent>
#include <QMouseEvent>
#include <QLineEdit>
#include <QResizeEvent>


#pragma pack(1)
struct ST_INFO
{
    bool b;
    int  i;
};
#pragma pack()

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QPointF         m_pntPress;
    bool            m_bMimeAdded;
    QLineEdit     * m_pText1;
    QLineEdit     * m_pText2;
    QLineEdit     * m_pText3;

protected:
    void    mousePressEvent(QMouseEvent *);
    void    mouseMoveEvent(QMouseEvent *);
    void    dropEvent(QDropEvent *);
    void    dragEnterEvent(QDragEnterEvent *);
    void    dragMoveEvent(QDragMoveEvent *);
    void    resizeEvent(QResizeEvent *);
};

#endif // MAINWINDOW_H
