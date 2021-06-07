#include "rect.h"

rectn::rectn()//Конструктор
{

}

void rectn::drawfill(QImage &im){ //Отрисовка с заливкой
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
    QPoint rect[4];
    rect[0].setX(leftup.GetX());
    rect[0].setY(leftup.GetY());
    rect[1].setX(rightdown.GetX());
    rect[1].setY(leftup.GetY());
    rect[2].setX(rightdown.GetX());
    rect[2].setY(rightdown.GetY());
    rect[3].setX(leftup.GetX());
    rect[3].setY(rightdown.GetY());
    QBrush brush1;
    brush.getRGBA(r,g,b,a);
    color.setRgb(r,g,b,a);
    brush1.setColor(QColor(r,g,b,a));
    brush1.setStyle(Qt::BrushStyle(styleb));
    painter.setBrush(brush1);
    painter.drawPolygon(rect,4,Qt::OddEvenFill);
}

void rectn::drawnofill(QImage &im){ //Отрисовка без заливки
    QPainter painter(&im);
    QColor color;
    int r,g,b,a;
    pen.getRGBA(r,g,b,a);
    color.setRgb(r,g,b,a);
    QPen pen1;
    pen1.setColor(color);
    pen1.setWidth(width);
    pen1.setStyle(Qt::PenStyle(style));
    painter.setPen(pen1);
    painter.drawRect(leftup.GetX(),leftup.GetY(),(rightdown.GetX()-leftup.GetX()),(rightdown.GetX()-leftup.GetX()));
}
