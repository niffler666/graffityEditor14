#include "my_pen.h"

my_pen::my_pen()//Конструктор
{
    style=1;
    width=5;
}
void my_pen::setWidth(int nw){ //Задание толщины
    width=nw;
}
void my_pen::setSetyle(int ns){ //Задание стиля
    style=ns;
}
int my_pen::getSetyle(){ //Получение стиля
    return style;
}
int my_pen::getWidthh(){ //Получение толщины
    return width;
}
