#include "plotter.h"
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QDebug>

Plotter::Plotter(QWidget *parent)
    : QWidget{parent}
{
    dados.push_back("0");
    tempos.push_back(0);
}

Plotter::~Plotter()
{

}

void Plotter::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    QBrush brush;
    QPen pen;

    painter.setRenderHint(QPainter::Antialiasing);

    // Parte do widget
    brush.setColor(Qt::white);
    brush.setStyle(Qt::SolidPattern);
    pen.setColor(QColor(200, 200, 200));
    pen.setWidth(6);
    painter.setBrush(brush);
    painter.setPen(pen);
    painter.drawRect(0, 0, width(), height());

    // Parte do gráfico
    pen.setColor(QColor(100, 0, 255));
    pen.setWidth(2);
    painter.setPen(pen);

    x0 = 4;
    y0 = height() - 3;

    if (dados_aux.size() == 21)
    {
        for (size_t i = 0; i < dados_aux.size(); i++)
        {
            if (i != 0)
            {
                y1 = height() - ((dados_aux[i].toInt() * height()) / 99);

                x1 = (tempos_aux[i] - referencia_aux + 1000) / 40;

                painter.drawLine(x0, y0, x1, y1);

                y0 = y1;
                x0 = x1;
            }
        }
    }
}

void Plotter::receberDados(qint64 thetime, QString str)
{
    tempo = thetime;
    valor = str;

    tempos.push_back(tempo);
    if (tempos.size() == 2)
        referencia = tempo;
    dados.push_back(valor);

    if (dados.size() == 21)
    {
        referencia_aux = referencia;
        dados_aux = dados;
        dados.clear();
        tempos_aux = tempos;
        tempos.clear();
    }

    repaint();
}
