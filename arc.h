#ifndef ARC_H
#define ARC_H

#include "tochka.h"
#include "line.h"
#include "my_brush.h"
#include "my_pen.h"
#include "color.h"

class arc: public my_pen
{
public:
    arc();
    void draw(QImage &im);
    void setRx(int r);
    void setRy(int r);
    void setStartangle(int sa);
    void setSpanangle(int sp);
    tochka centr;
    my_pen pen;
    my_brush brush;

private:
    int rx,ry,startagnle,spanangle;

};

#endif // ARC_H
