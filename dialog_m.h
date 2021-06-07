#ifndef DIALOG_M_H
#define DIALOG_M_H

#include <QDialog>
#include <color.h>
namespace Ui {
class Dialog_m;
}

class Dialog_m : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_m(QWidget *parent = nullptr);
    ~Dialog_m();


private slots:


    void on_horizontalSlider_red_valueChanged(int value);

    void on_horizontalSlider_green_valueChanged(int value);

    void on_horizontalSlider_blue_valueChanged(int value);

    void on_horizontalSlider_alpha_valueChanged(int value);

    void on_spinBox_red_valueChanged(int arg1);

    void on_spinBox_green_valueChanged(int arg1);

    void on_spinBox_blue_valueChanged(int arg1);

    void on_spinBox_alpha_valueChanged(int arg1);

    void drawnewcolor();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void drawoldcolor();

public slots:
    void getOldColor(int red, int green, int blue, int alpha);

    void setNewColor (int &red, int &green, int &blue, int &alpha);



private:
    Ui::Dialog_m *ui;
    int r=0,g=0,b=0,a=255;
    color colorold,colornew;

};

#endif // DIALOG_M_H
