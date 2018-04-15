#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "ambiente.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void on_pushButtonRun_clicked();

private:
    Ui::Dialog *ui;
    ambiente oceano;
protected:
    void paintEvent(QPaintEvent *e);

};

#endif // DIALOG_H
