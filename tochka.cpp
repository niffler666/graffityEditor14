#include "tochka.h"

tochka::tochka()//Конструктор
{
    x=0;
    y=0;
}

void tochka::SetX(int new_x){ //Задание Х
    x=new_x;
}

void tochka::SetY(int new_y){ //Задание Y
    y=new_y;
}

void tochka::SetXY(int new_x, int new_y){ //Хадание обоих координат
    x=new_x;
    y=new_y;
}
int tochka::GetX(void){ //Получение X
    return(x);
}

int tochka::GetY(void){ //Получение Y
    return (y);
}

void tochka::GetXY(int &zn_x, int &zn_y){ //Получение обоих координат
    zn_x=x;
    zn_y=y;
}
