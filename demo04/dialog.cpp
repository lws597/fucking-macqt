#include "dialog.h"
#include "ui_dialog.h"
#include "sondialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_clicked()
{
    SonDialog sDialog(this);
    sDialog.exec();
}
