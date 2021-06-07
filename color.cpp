#include "color.h"

color::color()//Конструктор
{
    red=0;
    green=0;
    blue=0;
    alpha=0;

}
void color::setRGBA(int r, int g, int b, int a){ //Задание цвета
    red=r;
    green=g;
    blue=b;
    alpha=a;
}
void color::getRGBA(int &r, int &g, int &b, int &a){ //получение цвета
    r=red;
    g=green;
    b=blue;
    a=alpha;
}
