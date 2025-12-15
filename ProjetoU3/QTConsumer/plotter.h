#ifndef PLOTTER_H
#define PLOTTER_H

#include <QWidget>
#include <vector>

class Plotter : public QWidget
{
    Q_OBJECT
private:
    int x0, x1, y0, y1;
    std::vector<int> coordenadas_y;
    std::vector<qint64> tempos;
    std::vector<qint64> tempos_aux;
    std::vector<QString> dados;
    std::vector<QString> dados_aux;

    QString valor;
    qint64 tempo;
    qint64 referencia;
    qint64 referencia_aux;
public:
    explicit Plotter(QWidget *parent = nullptr);
    ~Plotter();

    void paintEvent(QPaintEvent *event);
public slots:
    void receberDados(qint64 thetime, QString str);
signals:
};

#endif // PLOTTER_H
