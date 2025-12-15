#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    max = 35;
    min = 0;
    intervaloTimer = 1000;

    connect(ui->horizontalSlider_max, SIGNAL(valueChanged(int)), this, SLOT(mudaMax()));
    connect(ui->horizontalSlider_min, SIGNAL(valueChanged(int)), this, SLOT(mudaMin()));
    connect(ui->horizontalSlider_timer, SIGNAL(valueChanged(int)), this, SLOT(mudaTimer()));
}

void MainWindow::tcpConnect(){
    socket->connectToHost(ip_servidor,1234);
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
        ui->label_status->setText("connected");
    }
    else{
        qDebug() << "Disconnected";
    }
}

void MainWindow::putData(){
    QString str;
    qint64 msecdate;

    if(socket->state()== QAbstractSocket::ConnectedState){

        msecdate = QDateTime::currentDateTime().toMSecsSinceEpoch();
        str = "set "+ QString::number(msecdate) + " " +
              QString::number(rand() % (max - min + 1) + min)+"\r\n"; // rand() % (max - min + 1) + min

        qDebug() << str;
        qDebug() << socket->write(str.toStdString().c_str())
                 << " bytes written";
        if(socket->waitForBytesWritten(3000)){
            qDebug() << "wrote";
        }
        ui->textEdit->insertPlainText(str);
    }
}

MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event){
    if (event->timerId() == timerId) {
        putData();
    }
}

void MainWindow::mudaMax(){
    max = ui->horizontalSlider_max->value();
}

void MainWindow::mudaMin(){
    min = ui->horizontalSlider_min->value();
}

void MainWindow::mudaTimer(){
    intervaloTimer = ui->horizontalSlider_timer->value() * 1000;
}



void MainWindow::on_input_ip_editingFinished(){
    ip_servidor = ui->input_ip->text();
}


void MainWindow::on_pushButton_stop_clicked(){
    killTimer(timerId);
}


void MainWindow::on_botao_connect_clicked(){
    tcpConnect();
}


void MainWindow::on_pushButton_start_clicked(){
    // Iniciar o timer (intervalo em milissegundos)
    timerId = startTimer(intervaloTimer); // Timer de 1 segundo
}


void MainWindow::on_botao_disconect_clicked(){
    socket->disconnectFromHost();
    ui->label_status->setText("disconnected");
}
