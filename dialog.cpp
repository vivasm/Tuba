#include "dialog.h"
#include "ui_dialog.h"
#include <QPainter>
#include "pos.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButtonRun_clicked()
{
    this->oceano.roda();
    this->repaint();
}

void Dialog::paintEvent(QPaintEvent *e)
{
    QPainter estojo;
    estojo.begin(this);
    int tamJx=this->geometry().width();
    int tamJy=this->geometry().height();
    double fx=(double)tamJx/this->oceano.getTamM();
    double fy=(double)tamJy/this->oceano.getTamM();
    this->ui->spinBoxPopSa->setValue(this->oceano.getNAg());

    posicao pm;
    estojo.setPen(QColor(0,0,0,0));
    for(int i=0;i<this->oceano.getNAg();i++)
    {
        estojo.save();
        pm=this->oceano.getPosAg(i);
        estojo.translate(pm.x*fx,pm.y*fy);
        estojo.rotate(this->oceano.getDir(i));

        if(this->oceano.getEhSardinha(i))
        {
            estojo.setBrush(QColor(255,134,32));
            estojo.drawRect(-6,-6,10,10);
            estojo.setBrush(QColor(255,0,0));
            estojo.drawEllipse(QPoint(6,0),3,3);
            estojo.setBrush(QColor(0,0,255,10));
            double rv=this->oceano.getRaiViz(i);
            estojo.drawEllipse(QPoint(0,0),rv*fx,rv*fy);
        }
        else
        {
            estojo.setBrush(QColor(123,100,45));
            estojo.drawRect(-10,-5,20,10);
            estojo.setBrush(QColor(255,0,0));
            estojo.drawEllipse(QPoint(13,0),3,3);
            estojo.setBrush(QColor(0,0,255,10));
            double rv=this->oceano.getRaiViz(i);
            estojo.drawEllipse(QPoint(0,0),rv*fx,rv*fy);
        }

        estojo.restore();
    }

    estojo.end();
}
