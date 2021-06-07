#include "polygon.h"

polygon::polygon()//Конструктор
{

}

void polygon::setMas(int new_num) //Установка точек
{
    tochMas = new tochka*[new_num];
    for (int i = 0; i < new_num; i++)
    {
        tochMas[i] = new tochka;
    }
}

void polygon::delMas(int new_num) //Очищение памяти
{
    for (int i = 0; i < new_num; i++)
    {
        delete tochMas[i];
    }
    delete [] tochMas;
}

void polygon::drawnofill(QImage &im, int num){ //Отрисовка без заливки
    QPainter painter(&im);
    int r,g,b,a;
    pen.getRGBA(r,g,b,a);
    QPen pen1;
    pen1.setColor(QColor(r,g,b,a));
    pen1.setStyle(Qt::PenStyle(style));
    pen1.setWidth(width);
    painter.setPen(pen1);
    QPointF tochki[num];
    for (int i = 0; i < num; i++)
    {
        tochki[i].setX(tochMas[i]->GetX());
        tochki[i].setY(tochMas[i]->GetY());
    }
    painter.drawPolygon(tochki, num);
}

void polygon::drawfill(QImage &im, int num){ //Отрисовка с заливкой
    QPainter painter(&im);
    int r,g,b,a;
    pen.getRGBA(r,g,b,a);
    QPen pen1;
    pen1.setColor(QColor(r,g,b,a));
    pen1.setStyle(Qt::PenStyle(style));
    pen1.setWidth(width);
    painter.setPen(pen1);
    QPointF tochki[num];
    for (int i = 0; i < num; i++)
    {
        tochki[i].setX(tochMas[i]->GetX());
        tochki[i].setY(tochMas[i]->GetY());
    }
    QBrush brush1;
    brush.getRGBA(r,g,b,a);
    brush1.setColor(QColor(r,g,b,a));
    brush1.setStyle(Qt::BrushStyle(styleb));
    painter.setBrush(brush1);
    painter.drawPolygon(tochki, num);
}
