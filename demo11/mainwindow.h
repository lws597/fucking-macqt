#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTouchEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool event(QEvent* e);

private:
    Ui::MainWindow *ui;
    QList<QTouchEvent::TouchPoint> m_lTouchPoints;
    bool                           m_bSwipe;
    bool                           m_bPinch;
    bool                           m_bTap;
};
#endif // MAINWINDOW_H
