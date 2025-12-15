#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QListWidgetItem>
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  explicit MainWindow(QWidget *parent = 0);
  ~MainWindow();
  
  void tcpConnect();

  void timerEvent(QTimerEvent *event);
public slots:
  void getData();
  void mudaTimer();

private slots:
    void on_input_ip_editingFinished();

    void on_pushButton_connect_clicked();

    void on_pushButton_disconnect_clicked();

    void on_lista_ip_itemClicked(QListWidgetItem *item);

    void on_pushButton_update_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_stop_clicked();

signals:
    void enviarDados(qint64 thetime, QString str);

private:
  Ui::MainWindow *ui;
  QTcpSocket *socket;

  QString ip_servidor;

  int get_data_timer;
  int intervalo_timer;
};

#endif // MAINWINDOW_H
