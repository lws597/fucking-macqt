#include <QApplication>
#include <QtCore>
#include <QtGui>

#include "rotatedemo.h"
#include "animationdemo.h"

void drawToScreen()
{

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    RotateDemo w;
    w.show();

    return a.exec();
}
