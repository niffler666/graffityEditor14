#include "line.h"

line::line()//Конструктор
{

}

void line::draw(QImage &im){ //Отрисовка линии
    QPainter painter(&im);
    QColor color;
    color.setRgb(red,green,blue,alpha);

    QPen pen;
    pen.setColor(color);
    pen.setWidth(width);
    pen.setStyle(Qt::PenStyle(style));
    painter.setPen(pen);
    int x1,x2,y1,y2;
    x1=st.GetX();
    x2=end.GetX();
    y1=st.GetY();
    y2=end.GetY();
    painter.drawLine(x1,y1,x2,y2);

}
