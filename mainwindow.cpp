#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPort>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->box->addItem("a");
    ui->box->addItem("b");
    ui->box->addItem("c");

    arduino = new seriallink;

    arduino->openConnection();

    connect(arduino, &seriallink::gotNewData, this, &MainWindow::updateGUI);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateGUI(QByteArray data){
   printf("");
}

void MainWindow::on_p_ledOn_clicked()
{
   if (arduino->isWritable())

       arduino->write("o");
   else
       qDebug() << "Couldn't write to serial!:";
}


void MainWindow::on_p_ledOff_clicked()
{
    if (arduino->isWritable())
        arduino->write("n");
    else
        qDebug() << "Couldn't write to serial!:";
}


void MainWindow::on_position_0_clicked()
{
    if (arduino->isWritable()){
        if (ui->box->currentText()=="a")
            arduino->write("sa01f");
        if (ui->box->currentText()=="b")
            arduino->write("sb01f");
    }else
        qDebug() << "Couldn't write to serial!:";

}

void MainWindow::on_position_90_clicked()
{

    if (arduino->isWritable()){
        if (ui->box->currentText()=="a")
            arduino->write("sa90f");
        if (ui->box->currentText()=="b")
            arduino->write("sb90f");

    }else
        qDebug() << "Couldn't write to serial!:";
}

void MainWindow::on_position_180_clicked()
{
    if (arduino->isWritable()){
        if (ui->box->currentText()=="a")
            arduino->write("sa180f");
        else if (ui->box->currentText()=="b")
            arduino->write("sb180f");
    }else
        qDebug() << "Couldn't write to serial!:";
}

void MainWindow::on_servo_valueChanged(int value)
{
    if(arduino->isWritable()){
        arduino->write(QString("sa%1f").arg(value).toStdString().c_str());
    }else{
        qDebug() << "Coundn't write to serial!:";
    }
    qDebug() << QString("sa%1f").arg(value).toStdString().c_str();
}


void MainWindow::on_stepper_valueChanged(int value)
{
    if(arduino->isWritable()){
        if (ui->p->isChecked()){
            arduino->write(QString("m+%1f").arg(value).toStdString().c_str());
            qDebug() << QString("m+%1f").arg(value).toStdString().c_str();
        }if (ui->n->isChecked()){
            arduino->write(QString("m-%1f").arg(value).toStdString().c_str());
            qDebug() << QString("m-%1f").arg(value).toStdString().c_str();
        }
    }else{
        qDebug() << "Coundn't write to serial!:";
    }

}


void MainWindow::on_pushButton_toggled(bool checked)
{
    if(arduino->isWritable()){
        if(checked==true){
            if(ui->p->isChecked()){
                arduino->write("o+");
                qDebug() << "o+";
            }else if(ui->n->isChecked()){
                arduino->write("o-");
                qDebug() << "o-";
            }

        }else{
            arduino->write("n");
            qDebug() << "n";
        }
    }else{
        qDebug() << "Coundn't write to serial!:";
    }

}


void MainWindow::on_stepper_2_valueChanged(int value)
{
    if(arduino->isWritable()){
        arduino->write(QString("e%1f").arg(value).toStdString().c_str());
        qDebug() << QString("e%1f").arg(value).toStdString().c_str();
    }else{
        qDebug() << "Coundn't write to serial!:";
    }
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    if(arduino->isWritable()){
        if (ui->p->isChecked()){
            arduino->write(QString("m+%1f").arg(arg1).toStdString().c_str());
            qDebug() << QString("m+%1f").arg(arg1).toStdString().c_str();
        }if (ui->n->isChecked()){
            arduino->write(QString("m-%1f").arg(arg1).toStdString().c_str());
            qDebug() << QString("m-%1f").arg(arg1).toStdString().c_str();
        }
    }else{
        qDebug() << "Coundn't write to serial!:";
    }
}

