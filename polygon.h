#ifndef POLYGON_H
#define POLYGON_H

#include <QImage>
#include <QPainter>
#include "tochka.h"
#include "my_pen.h"
#include "my_brush.h"

class polygon:public my_pen, public my_brush
{
public:
    polygon();
    void setMas(int new_num);
    void drawfill(QImage &im, int num);
    void drawnofill(QImage &im, int num);
    void delMas(int new_num);
    tochka **tochMas;
    my_pen pen;
    my_brush brush;
};

#endif // POLYGON_H
