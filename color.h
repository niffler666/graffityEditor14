#ifndef COLOR_H
#define COLOR_H


class color
{
public:
    color();
    void setRGBA(int r, int g, int b, int a );
    void getRGBA(int &r, int &g, int &b, int &a );

protected:
    int red;
    int green;
    int blue;
    int alpha;

};

#endif // COLOR_H
