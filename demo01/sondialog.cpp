#include "sondialog.h"
#include "ui_sondialog.h"

#include <QMessageBox>

SonDialog::SonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SonDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

SonDialog::~SonDialog()
{
    delete ui;
}

void SonDialog::on_clicked()
{
    QMessageBox::information(this, "", "hello world");
}
