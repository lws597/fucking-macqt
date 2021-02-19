#ifndef FATHERDIALOG_H
#define FATHERDIALOG_H

#include <QDialog>
#include <QMainWindow>

namespace Ui
{
    class FatherDialog;
}

class FatherDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FatherDialog(QWidget *parent = 0);
    ~FatherDialog();

private slots:
    void on_clicked();

private:
    Ui::FatherDialog *ui;
};

#endif // FATHERDIALOG_H
