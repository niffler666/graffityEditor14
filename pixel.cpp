#include "pixel.h"

pixel::pixel()//Конструктор
{

}
void pixel::draw(QImage &im, int n){ //Отрисовка пикселя
    QPainter painter(&im);
    QColor color;
    color.setRgb(red,green,blue,alpha);
    QPen pen;
    pen.setColor(color);
    pen.setWidth(n);
    painter.setPen(pen);
    painter.drawPoint(t.GetX(),t.GetY());
}
