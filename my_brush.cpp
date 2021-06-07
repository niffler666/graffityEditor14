#include "my_brush.h"

my_brush::my_brush() //Конструктор
{
    styleb=1;
}
void my_brush::setSetyleb(int ns){ //Задание стиля кисти
    styleb=ns;
}
int my_brush::getStyleb(){ //Получение стиля кисти
    return styleb;
}
