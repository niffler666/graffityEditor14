#ifndef MY_PEN_H
#define MY_PEN_H
#include "color.h"

class my_pen : public color
{
public:
    my_pen();
    void setWidth(int nw);
    void setSetyle(int ns);
    int getSetyle();
    int getWidthh();
    int width;
    int style;
};

#endif // MY_PEN_H
