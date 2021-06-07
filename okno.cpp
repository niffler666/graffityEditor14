#include "okno.h"
#include "ui_okno.h"

okno::okno(QWidget *parent) ://Конструктор
    QMainWindow(parent),
    ui(new Ui::okno)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(ui->spinBox->value());
    for (int i=0; i<ui->spinBox->value(); i++)
    {
        if(ui->tableWidget->item(i,0)==nullptr)
        {
            QTableWidgetItem * new_item;
            new_item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,new_item);
        }
        if(ui->tableWidget->item(i,1)==nullptr)
        {
            QTableWidgetItem * new_item;
            new_item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,1,new_item);
        }
    }
}

okno::~okno() //Деструктор
{
    delete ui;
}

void okno::on_spinBox_valueChanged(int arg1) //Изменения размера
{
    ui->tableWidget->setRowCount(arg1);
    for (int i=0; i<arg1; i++)
    {
        if(ui->tableWidget->item(i,0)==nullptr)
        {
            QTableWidgetItem * new_item;
            new_item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,new_item);
        }
        if(ui->tableWidget->item(i,1)==nullptr)
        {
            QTableWidgetItem * new_item;
            new_item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,1,new_item);
        }
    }
}

void okno::on_pushButton_clicked() //Передача значений в mainwindow
{
    int rows = ui->spinBox->value();
    int size = rows * 2;
    int x,y;
    bool flx,fly,fl=true;
    int *mas = new int [size];
    for (int i=0; i<rows; i++)
    {
        x=ui->tableWidget->item(i,0)->text().toInt(&flx);
        y=ui->tableWidget->item(i,1)->text().toInt(&fly);
        if(flx&&fly){
            mas[i]=x;
            mas[i+rows]=y;
        } if (!flx){
            ui->tableWidget->item(i,0)->setBackgroundColor(Qt::red);
            fl=false;
        } if(!fly){
            ui->tableWidget->item(i,1)->setBackgroundColor(Qt::red);
            fl=false;
        }
    }
    if(fl){
        emit exportFlag(fl);
        emit exportMas(mas, size); 
        delete [] mas;
        this->close();
    } else{
        QMessageBox::warning(this, "Ошибка", "Ошибка в введенных данных");
    }
}

void okno::on_tableWidget_cellChanged(int row, int column)
{
    bool fl;
    ui->tableWidget->item(row,column)->text().toInt(&fl);
    if(fl){
        ui->tableWidget->item(row,column)->setBackgroundColor(Qt::white);
    }
    else{
        ui->tableWidget->item(row,column)->setBackgroundColor(Qt::red);
    }
}
