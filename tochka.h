#ifndef TOCHKA_H
#define TOCHKA_H


class tochka
{
public:
    tochka();
    void SetX(int new_x);
    void SetY(int new_y);
    void SetXY(int new_x, int new_y);
    int GetX(void);
    int GetY(void);
    void GetXY(int &zn_x, int &zn_y);
    protected:
        int x,y;
};

#endif // TOCHKA_H
