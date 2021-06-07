#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QColorDialog>
#include "line.h"
#include "okno.h"
#include "color.h"
#include "dialog_m.h"
#include "ellipse.h"
#include "arc.h"
#include "polyline.h"
#include "polygon.h"
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clear_clicked();

    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_checkBox_fill_stateChanged(int arg1);

    void on_comboBox_style_currentIndexChanged(int index);

   bool change_colour();

    void importMas(int *mas, int size);

    void importFlag(bool fl);

private:
    Ui::MainWindow *ui;
    int r1=0,g1=0,b1=0,a1=255,a2=255, r2=0, g2=0, b2=0;
    color pencolor,brushcolor;
    bool isbline=false,ispolygon=false,check;
    bool otmena=false;

};

#endif // MAINWINDOW_H
