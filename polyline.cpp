#include "polyline.h"

polyline::polyline()//Конструктор
{

}
void polyline::setMas(int new_num) //Установка точек
{
    tochMas = new tochka*[new_num];
    for (int i = 0; i < new_num; i++)
    {
        tochMas[i] = new tochka;
    }
}

void polyline::delMas(int new_num) //Очищение памяти
{
    for (int i = 0; i < new_num; i++)
    {
        delete tochMas[i];
    }
    delete [] tochMas;
}

void polyline::draw(QImage &im, int num) //Отрисовка
{
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
    painter.drawPolyline(tochki, num);
}
