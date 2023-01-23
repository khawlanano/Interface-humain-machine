#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "seriallink.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void updateGUI(QByteArray data);


    void on_p_ledOn_clicked();

    void on_p_ledOff_clicked();

private slots:
    void on_position_0_clicked();

    void on_position_90_clicked();

    void on_position_180_clicked();

    void on_servo_valueChanged(int value);

    void on_stepper_valueChanged(int value);

    void on_pushButton_toggled(bool checked);

    void on_stepper_2_valueChanged(int value);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    seriallink *arduino;
};
#endif // MAINWINDOW_H
