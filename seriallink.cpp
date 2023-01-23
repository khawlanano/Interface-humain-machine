#include "seriallink.h"

#include <QDebug>
seriallink::seriallink(QObject *parent)
    : QObject{parent}
{
  _serial.setPortName("COM6");
  _serial.setBaudRate(QSerialPort::Baud9600);
  _serial.setDataBits(QSerialPort::Data8);
  _serial.setParity(QSerialPort::NoParity);
  _serial.setStopBits(QSerialPort::OneStop);
  _serial.setFlowControl(QSerialPort::NoFlowControl);
  connect(&_serial, &QSerialPort::readyRead, this, &seriallink::newData);
  _serial1.setPortName("COM8");
  _serial1.setBaudRate(QSerialPort::Baud9600);
  _serial1.setDataBits(QSerialPort::Data8);
  _serial1.setParity(QSerialPort::NoParity);
  _serial1.setStopBits(QSerialPort::OneStop);
  _serial1.setFlowControl(QSerialPort::NoFlowControl);
  connect(&_serial1, &QSerialPort::readyRead, this, &seriallink::newData);
}

seriallink::~seriallink(){
    closeConnection();
}
void seriallink::openConnection(){
    if(!_serial.open(QIODevice::ReadWrite))
        qDebug() <<"connection impossible";
    else qDebug() <<"connection ok";
    if(!_serial1.open(QIODevice::ReadWrite))
        qDebug() <<"connection impossible1";
    else qDebug() <<"connection ok1";
}

void seriallink::write(const char* messageTowrite){
    _serial.write(messageTowrite);
    _serial1.write(messageTowrite);
}
void seriallink::closeConnection(){
    _serial.close();
    _serial1.close();
}
bool seriallink::isOpen(){
    return _serial.isOpen();
    return _serial1.isOpen();
}
bool seriallink::isWritable(){
    return _serial.isWritable();
    return _serial1.isWritable();
}
void seriallink::newData(){
    emit gotNewData(_serial.readAll()) ;
    emit gotNewData(_serial1.readAll()) ;
}
