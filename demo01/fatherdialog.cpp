#include "fatherdialog.h"
#include "ui_fatherdialog.h"
#include "sondialog.h"

FatherDialog::FatherDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::FatherDialog)
{
    ui->setupUi(this);
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(on_clicked()));
}

FatherDialog::~FatherDialog()
{
    delete ui;
}

void FatherDialog::on_clicked()
{
    SonDialog sDialog(this);
    sDialog.exec();
}
