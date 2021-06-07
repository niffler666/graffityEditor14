#ifndef MY_BRUSH_H
#define MY_BRUSH_H
#include "color.h"

class my_brush:public color
{
public:
    my_brush();
    void setSetyleb(int ns);
    int getStyleb();
protected:
    int styleb;
};

#endif // MY_BRUSH_H
