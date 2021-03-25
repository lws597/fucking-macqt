#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QTouchEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    bool event(QEvent* e);

private:
    Ui::Dialog *ui;
    QList<QTouchEvent::TouchPoint> m_lTouchPoints;
    bool                           m_bSwipe;
    bool                           m_bPinch;
    bool                           m_bTap;
};
#endif // DIALOG_H
