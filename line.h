#ifndef LINE_H
#define LINE_H
#include "my_pen.h"
#include "tochka.h"
#include <QImage>
#include <QPainter>



class line : public my_pen
{
public:
    line();
    void draw (QImage &im);
    tochka st;
    tochka end;
};

#endif // LINE_H
