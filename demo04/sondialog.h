#ifndef SONDIALOG_H
#define SONDIALOG_H

#include <QDialog>

namespace Ui
{
    class SonDialog;
}

class SonDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SonDialog(QWidget *parent = 0);
    ~SonDialog();

private:
    Ui::SonDialog *ui;
};

#endif // SONDIALOG_H
