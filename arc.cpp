#include "arc.h"

arc::arc()//Конструктор
{

}
void arc::setRx(int r){ //Установка rx
    rx=r;
}

void arc::setRy(int r){ //Установка ry
    ry=r;
}

void arc::setStartangle(int sa){ //Установка начального угла
    startagnle=sa*16;
}

void arc::setSpanangle(int sp){ //Установка конечного угла
    spanangle=sp*16;
}

void arc::draw(QImage &im){ //Отрисовка
    QPainter painter(&im);
    QColor color;
    int r,g,b,a;
    pen.getRGBA(r,g,b,a);
    color.setRgb(r,g,b,a);
    QPen pen1;
    pen1.setColor(QColor(r,g,b,a));
    pen1.setWidth(width);
    pen1.setStyle(Qt::PenStyle(style));
    painter.setPen(pen1);
    painter.drawArc(centr.GetX()-rx,centr.GetY()-ry, rx*2,ry*2, startagnle,spanangle );
}
