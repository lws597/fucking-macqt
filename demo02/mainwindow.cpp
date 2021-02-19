#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_clicked()
{
    QDialog dialog(this);
    dialog.exec();
}
