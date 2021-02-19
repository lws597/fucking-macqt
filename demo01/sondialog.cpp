#include "sondialog.h"
#include "ui_sondialog.h"

#include <QMessageBox>

SonDialog::SonDialog(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::SonDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
}

SonDialog::~SonDialog()
{
    delete ui;
}

void SonDialog::on_pushButton_clicked()
{
    QMessageBox::information(this, "", "hello world");
}
