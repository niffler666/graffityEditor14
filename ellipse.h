#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "tochka.h"
#include "line.h"
#include "my_brush.h"
#include "my_pen.h"
#include "color.h"

class ellipse : public my_pen, public my_brush
{
public:
    ellipse();
    void drawfill(QImage &im);
    void drawnofill(QImage &im);
    void setRx(int r);
    void setRy(int r);
    tochka centr;
    my_pen pen;
    my_brush brush;
private:
    int rx,ry;
};

#endif // ELLIPSE_H
