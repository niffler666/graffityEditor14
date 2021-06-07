#include "dialog_m.h"
#include "ui_dialog_m.h"

Dialog_m::Dialog_m(QWidget *parent) ://Конструктор
    QDialog(parent),
    ui(new Ui::Dialog_m)
{
    ui->setupUi(this);

    ui->widgetn->create_image(ui->widgetn->width(), ui->widgetn->height());
    ui->widgeto->create_image(ui->widgeto->width(), ui->widgeto->height());
    ui->widgeto->im.fill(0);
    ui->widgetn->im.fill(0);
    drawoldcolor();
}

Dialog_m::~Dialog_m() //Деструктор
{
    delete ui;
}

void Dialog_m::getOldColor(int red, int green, int blue, int alpha){ //Передача цвета из mainwindow
    r=red;
    g=green;
    b=blue;
    a=alpha;
    colorold.setRGBA(r,g,b,a);
    ui->widgeto->im.fill(QColor(r,g,b,a));
    ui->widgetn->im.fill(QColor(r,g,b,a));
    update();
    ui->horizontalSlider_red->setValue(r);
    ui->horizontalSlider_green->setValue(g);
    ui->horizontalSlider_blue->setValue(b);
    ui->horizontalSlider_alpha->setValue(a);
}

void Dialog_m::drawoldcolor(){ //Отрисовка старого цвета

    ui->widgeto->im.fill(0);
    ui->widgeto->im.fill(QColor(r,g,b,a));
    update();
}

void Dialog_m::drawnewcolor() //Отрисовка нового цвета
{
    ui->widgetn->im.fill(0);
    ui->widgetn->im.fill(QColor(r,g,b,a));
    update();
}

void Dialog_m::on_horizontalSlider_red_valueChanged(int value) //Изменения красного
{
    r=value;
    ui->spinBox_red->setValue(value);
    drawnewcolor();
}

void Dialog_m::on_horizontalSlider_green_valueChanged(int value) //Изменения зеленого
{
    g=value;
    ui->spinBox_green->setValue(value);
    drawnewcolor();
}

void Dialog_m::on_horizontalSlider_blue_valueChanged(int value) //Изменение синего
{
    b=value;
    ui->spinBox_blue->setValue(value);
    drawnewcolor();
}

void Dialog_m::on_horizontalSlider_alpha_valueChanged(int value) //Изменение прозрачности
{
    a=value;
    ui->spinBox_alpha->setValue(value);
    drawnewcolor();
}

void Dialog_m::on_spinBox_red_valueChanged(int arg1)//Изменения красного
{
    ui->horizontalSlider_red->setValue(arg1);
}

void Dialog_m::on_spinBox_green_valueChanged(int arg1)//Изменения зеленого
{
    ui->horizontalSlider_green->setValue(arg1);
}

void Dialog_m::on_spinBox_blue_valueChanged(int arg1)//Изменение синего
{
    ui->horizontalSlider_blue->setValue(arg1);
}

void Dialog_m::on_spinBox_alpha_valueChanged(int arg1)//Изменение прозрачности
{
    ui->horizontalSlider_alpha->setValue(arg1);
}

void Dialog_m::setNewColor (int &red, int &green, int &blue, int &alpha){ //передача нового цвета в mainwindow
    red=r;
    green=g;
    blue=b;
    alpha=a;
}

void Dialog_m::on_pushButton_clicked() //Кнопка принятия
{
    close();
}

void Dialog_m::on_pushButton_2_clicked() //Кнопка отмена
{
    colorold.getRGBA(r,g,b,a);
    close();
}
