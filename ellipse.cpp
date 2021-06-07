#include "ellipse.h"

ellipse::ellipse()//Конструктор
{

}

void ellipse::setRx(int r){//Установка rx
    rx=r;
}

void ellipse::setRy(int r){//Установка ry
    ry=r;
}

void ellipse::drawfill(QImage &im){ //Отрисовка с заливкой
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
    QBrush brush1;
    brush.getRGBA(r,g,b,a);
    color.setRgb(r,g,b,a);
    brush1.setColor(QColor(r,g,b,a));
    brush1.setStyle(Qt::BrushStyle(styleb));
    painter.setBrush(brush1);
    painter.drawEllipse(centr.GetX()-rx,centr.GetY()-ry,rx*2,ry*2);
}

void ellipse::drawnofill(QImage &im){ //Отрисовка без заливки
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
    painter.drawEllipse(centr.GetX()-rx,centr.GetY()-ry,rx*2,ry*2);
}
