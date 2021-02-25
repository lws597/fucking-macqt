#include "sondialog.h"
#include "ui_sondialog.h"

SonDialog::SonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SonDialog)
{
    ui->setupUi(this);
}

SonDialog::~SonDialog()
{
    delete ui;
}
