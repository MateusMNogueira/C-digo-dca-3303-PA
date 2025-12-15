#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);

    // Enviar thetime e str para a classe Plotter
    connect(this, SIGNAL(enviarDados(qint64, QString)), ui->widget, SLOT(receberDados(qint64, QString)));

    intervalo_timer = 1000;
    connect(ui->horizontalSlider_timing, SIGNAL(valueChanged(int)), this, SLOT(mudaTimer()));
}

void MainWindow::tcpConnect(){
    int porta = 1234;
    socket->connectToHost(ip_servidor, porta); // 127.0.0.1
    if(socket->waitForConnected(3000)){
        qDebug() << "Connected";
    }
    else{
        qDebug() << "Disconnected";
    }
}

void MainWindow::getData(){
    QString str;
    QStringList list;
    qint64 thetime;
    qDebug() << "to get data...";
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            qDebug() << "reading...";
            socket->write("get 127.0.0.1 1\r\n");
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();
            while(socket->bytesAvailable()){
                str = socket->readLine().replace("\n","").replace("\r","");
                list = str.split(" ");
                if(list.size() == 2){
                    bool ok;
                    str = list.at(0);
                    thetime = str.toLongLong(&ok);
                    str = list.at(1);
                    qDebug() << thetime << ": " << str;
                    // Emite os dados para o Widget Plotter
                    emit enviarDados(thetime, str);
                }
            }
        }
    }
}


MainWindow::~MainWindow(){
    delete socket;
    delete ui;
}

void MainWindow::on_input_ip_editingFinished(){
    ip_servidor = ui->input_ip->text();
}


void MainWindow::on_pushButton_connect_clicked(){
    tcpConnect();
}


void MainWindow::on_pushButton_disconnect_clicked(){
    socket->disconnectFromHost();
}


// Gerenciamento dos items da lista de servidores
void MainWindow::on_lista_ip_itemClicked(QListWidgetItem *item){
    Q_UNUSED(item);
    ui->input_ip->setText(ui->lista_ip->currentItem()->text());

    ip_servidor = ui->lista_ip->currentItem()->text();
}


// Botão Update
void MainWindow::on_pushButton_update_clicked(){
    if(socket->state() == QAbstractSocket::ConnectedState){
        if(socket->isOpen()){
            socket->write("list");
            socket->waitForBytesWritten();
            socket->waitForReadyRead();
            qDebug() << socket->bytesAvailable();

            while(socket->bytesAvailable()){
                QString ip = socket->readLine().replace("\n","").replace("\r","");
                ui->lista_ip->addItem(ip);
            }

        }
    }
}


void MainWindow::on_pushButton_start_clicked(){
    get_data_timer = startTimer(intervalo_timer);
}

void MainWindow::timerEvent(QTimerEvent *event){
    Q_UNUSED(event);
    getData();
    ui->label_lendo_dados->setText("Aguarde a leitura de 20 valores...");
}

void MainWindow::on_pushButton_stop_clicked(){
    killTimer(get_data_timer);
    ui->label_lendo_dados->setText("");
}

void MainWindow::mudaTimer(){
    intervalo_timer = ui->horizontalSlider_timing->value() * 1000;
}
