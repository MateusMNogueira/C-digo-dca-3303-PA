#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QTimerEvent>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();

  void timerEvent(QTimerEvent *event) override;
  
  void tcpConnect();
public slots:
    void putData();
    void mudaMax();
    void mudaMin();
    void mudaTimer();
private slots:
    void on_input_ip_editingFinished();

    void on_pushButton_stop_clicked();

    void on_botao_connect_clicked();

    void on_pushButton_start_clicked();

    void on_botao_disconect_clicked();

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;
  int timerId; // Identificador do timer
  int intervaloTimer; // Intervalo do timer em segundos
  int min, max;
  QString ip_servidor;
};

#endif // MAINWINDOW_H
