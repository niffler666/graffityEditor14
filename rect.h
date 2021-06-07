#ifndef RECT_H
#define RECT_H
#include <QImage>
#include<QPainter>
#include "tochka.h"
#include "line.h"
#include "my_brush.h"
#include "my_pen.h"
#include "color.h"
class rectn : public my_pen, public my_brush
{
public:
    rectn();
    void drawfill(QImage &im);
    void drawnofill(QImage &im);
    tochka leftup;
    tochka rightdown;
    my_pen pen;
    my_brush brush;
};

#endif // RECT_H
