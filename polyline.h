#ifndef POLYLINE_H
#define POLYLINE_H

#include "tochka.h"
#include <QImage>
#include <QPainter>
#include "my_pen.h"

class polyline : public my_pen
{
public:
    polyline();
    void draw(QImage &im, int num);
    void setMas(int new_num);
    void delMas(int new_num);
    tochka **tochMas;
    my_pen pen;
};

#endif // POLYLINE_H
