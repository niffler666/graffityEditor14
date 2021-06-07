#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pixel.h"
#include "rect.h"

MainWindow::MainWindow(QWidget *parent) : //Конструктор
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->create_image(ui->widget->width(), ui->widget->height());
    ui->comboBox->setCurrentIndex(0);
    pencolor.setRGBA(r1,g1,b1,a1);
    brushcolor.setRGBA(r2,g2,b2,a2);
    ui->lineEdit_x2->setVisible(false);
    ui->lineEdit_y2->setVisible(false);
    ui->lineEdit_startangle->setVisible(false);
    ui->lineEdit_spanangle->setVisible(false);
    ui->label_fill->setVisible(false);
    ui->comboBox_style->setVisible(false);
    ui->label_style->setVisible(false);
    ui->checkBox_fill->setVisible(false);
    ui->comboBox_styleb->setVisible(false);
    ui->label_styleb->setVisible(false);
    ui->comboBox_style->setCurrentIndex(1);
    ui->comboBox_styleb->setCurrentIndex(0);
    ui->label_x->setText("X");
    ui->label_y->setText("Y");
    ui->label_x2->setText("");
    ui->label_y2->setText("");
    ui->label_sa->setText("");
    ui->label_spa->setText("");
}

MainWindow::~MainWindow() //Деструктор
{
    delete ui;
}

void MainWindow::on_pushButton_clear_clicked() //Очистка
{
    ui->widget->im.fill(0);
    update();
}

void MainWindow::importFlag(bool fl){ //Получения флага закрытия окна
     check=fl;
}

void MainWindow::importMas(int *mas, int size){ //Получение координат и размера, отрисовка ломанной линии и многоугольника
    int colt=size/2;
    int n=ui->spinBox->value();
    bool fl;
    if(isbline){
        if(check){
            polyline pl;
            pl.setMas(colt);
            for (int i = 0; i < colt; i++)
            {
                pl.tochMas[i]->SetX(mas[i]);
                pl.tochMas[i]->SetY(mas[i+colt]);
            }
            fl=change_colour();
            if(fl)
            {
                pencolor.getRGBA(r1,g1,b1,a1);
                pl.pen.setRGBA(r1,g1,b1,a1);
                pl.setWidth(n);
                pl.setSetyle(ui->comboBox_style->currentIndex());
                pl.draw(ui->widget->im,colt);
                update();
                isbline=false;
                check=false;
                pl.delMas(colt);
            }
        }
    } else if(ispolygon){
        polygon pg;
        pg.setMas(colt);
        for (int i = 0; i < colt; i++)
        {
            pg.tochMas[i]->SetX(mas[i]);
            pg.tochMas[i]->SetY(mas[i+colt]);
        }
        fl=change_colour();
        if(fl)
        {
            pencolor.getRGBA(r1,g1,b1,a1);
            pg.pen.setRGBA(r1,g1,b1,a1);
            pg.setWidth(n);
            pg.setSetyle(ui->comboBox_style->currentIndex());
            if(ui->checkBox_fill->isChecked()){
                brushcolor.getRGBA(r2,g2,b2,a2);
                pg.brush.setRGBA(r2,g2,b2,a2);
                pg.setSetyleb(ui->comboBox_styleb->currentIndex()+1);
                pg.drawfill(ui->widget->im,colt);
            } else{
                pg.drawnofill(ui->widget->im,colt);
            }

            update();
        }
        pg.setMas(colt);
    }
}

void MainWindow::on_pushButton_clicked() //Отрисовка
{
    switch(ui->comboBox->currentIndex()){
    case 0: {//Выбран пиксель
        ui->lineEdit_x2->setVisible(false);
        ui->lineEdit_y2->setVisible(false);
        int x,y,n;
        bool fl;
        QString str;
        pixel m_p;
        n=ui->spinBox->value();
        str.clear();
        str.append(ui->lineEdit_x->text());
        x=str.toInt(&fl);
        if(fl){
            str.clear();
            str.append(ui->lineEdit_y->text());
            y=str.toInt(&fl);
            if(fl){
                fl=change_colour();
                if(fl)
                {
                    pencolor.getRGBA(r1,g1,b1,a1);
                    m_p.setRGBA(r1,g1,b1,a1);
                    m_p.t.SetXY(x,y);
                    m_p.draw(ui->widget->im,n);
                    update();
                }
            }
            else{
                QMessageBox::warning(this, "Ошибка", "Ошибка в координате y");
            }
        }
        else{
            QMessageBox::warning(this, "Ошибка", "Ошибка в координате x");
        }
        break;
    }
    case 1:{ //Выбрана линия
        int x,y,x2,y2,n;
        bool fl;
        QString str;
        line line;
        n=ui->spinBox->value();
        str.clear();
        str.append(ui->lineEdit_x->text());
        x=str.toInt(&fl);
        if(fl){
            str.clear();
            str.append(ui->lineEdit_y->text());
            y=str.toInt(&fl);
            if(fl){
                str.clear();
                str.append(ui->lineEdit_x2->text());
                x2=str.toInt(&fl);
                if(fl){
                    str.clear();
                    str.append(ui->lineEdit_y2->text());
                    y2=str.toInt(&fl);
                    if(fl){
                        fl=change_colour();
                        if(fl)
                        {
                            pencolor.getRGBA(r1,g1,b1,a1);
                            line.setSetyle(ui->comboBox_style->currentIndex());
                            line.setWidth(n);
                            line.setRGBA(r1,g1,b1,a1);
                            line.st.SetXY(x,y);
                            line.end.SetXY(x2,y2);
                            line.draw(ui->widget->im);
                            update();
                        }

                    } else{
                        QMessageBox::warning(this, "Ошибка", "Ошибка в координате y2");
                    }
                }
                else{
                    QMessageBox::warning(this, "Ошибка", "Ошибка в координате x2");
                }
            }
            else{
                QMessageBox::warning(this, "Ошибка", "Ошибка в координате y");
            }
        } else{
            QMessageBox::warning(this, "Ошибка", "Ошибка в координате x");
        }
        break;
    }
    case 2:{ //Выбран прямоугольник
        int x,y,x2,y2,n;
        bool fl;
        QString str;
        rectn rect;
        n=ui->spinBox->value();
        str.clear();
        str.append(ui->lineEdit_x->text());
        x=str.toInt(&fl);
        if(fl){
            str.clear();
            str.append(ui->lineEdit_y->text());
            y=str.toInt(&fl);
            if(fl){
                str.clear();
                str.append(ui->lineEdit_x2->text());
                x2=str.toInt(&fl);
                if(fl){
                    str.clear();
                    str.append(ui->lineEdit_y2->text());
                    y2=str.toInt(&fl);
                    if(fl){
                        fl=change_colour();
                        if(fl)
                        {
                            pencolor.getRGBA(r1,g1,b1,a1);
                            rect.pen.setRGBA(r1,g1,b1,a1);
                            rect.setWidth(n);
                            rect.setSetyle(ui->comboBox_style->currentIndex());
                            rect.leftup.SetXY(x,y);
                            rect.rightdown.SetXY(x2,y2);
                            if(ui->checkBox_fill->isChecked()){
                                brushcolor.getRGBA(r2,g2,b2,a2);
                                rect.brush.setRGBA(r2,g2,b2,a2);
                                rect.setSetyleb(ui->comboBox_styleb->currentIndex()+1);
                                rect.drawfill(ui->widget->im);
                            } else{
                                rect.drawnofill(ui->widget->im);
                            }
                            update();
                        }

                    } else{
                        QMessageBox::warning(this, "Ошибка", "Ошибка в координате y2");
                    }
                }
                else{
                    QMessageBox::warning(this, "Ошибка", "Ошибка в координате x2");
                }
            } else {
                QMessageBox::warning(this, "Ошибка", "Ошибка в координате y");
            }

        } else {
            QMessageBox::warning(this, "Ошибка", "Ошибка в координате x");
        }
        break;
    }
    case 3: { //Выбрана окружность
        int x,y,r,n;
        bool fl;
        QString str;
        ellipse krug;
        n=ui->spinBox->value();
        str.clear();
        str.append(ui->lineEdit_x->text());
        x=str.toInt(&fl);
        if(fl){
            str.clear();
            str.append(ui->lineEdit_y->text());
            y=str.toInt(&fl);
            if(fl){
                str.clear();
                str.append(ui->lineEdit_x2->text());
                r=str.toInt(&fl);
                if(fl&&r>0){
                   fl=change_colour();
                   if (fl)
                   {
                       pencolor.getRGBA(r1,g1,b1,a1);
                       krug.pen.setRGBA(r1,g1,b1,a1);
                       krug.setWidth(n);
                       krug.setSetyle(ui->comboBox_style->currentIndex());
                       krug.centr.SetXY(x,y);
                       krug.setRx(r);
                       krug.setRy(r);
                       if(ui->checkBox_fill->isChecked()){
                           brushcolor.getRGBA(r2,g2,b2,a2);
                           krug.brush.setRGBA(r2,g2,b2,a2);
                           krug.setSetyleb(ui->comboBox_styleb->currentIndex()+1);
                           krug.drawfill(ui->widget->im);
                       } else{
                           krug.drawnofill(ui->widget->im);
                       }
                       update();
                   }

                } else{
                    QMessageBox::warning(this, "Ошибка", "Ошибка в радиусе");
                }
            } else{
                QMessageBox::warning(this, "Ошибка", "Ошибка в координате y");
            }
        } else{
            QMessageBox::warning(this, "Ошибка", "Ошибка в координате x");
        }
        break;
    }
    case 4:{ //Выбран эллипс
        int x,y,rx,ry,n;
        bool fl;
        QString str;
        ellipse el;
        n=ui->spinBox->value();
        str.clear();
        str.append(ui->lineEdit_x->text());
        x=str.toInt(&fl);
        if(fl){
            str.clear();
            str.append(ui->lineEdit_y->text());
            y=str.toInt(&fl);
            if(fl){
                str.clear();
                str.append(ui->lineEdit_x2->text());
                rx=str.toInt(&fl);
                if (fl&&rx>0){
                    str.clear();
                    str.append(ui->lineEdit_y2->text());
                    ry=str.toInt(&fl);
                    if(fl&&ry>0){
                        fl=change_colour();
                        if(fl)
                        {
                            pencolor.getRGBA(r1,g1,b1,a1);
                            el.pen.setRGBA(r1,g1,b1,a1);
                            el.setWidth(n);
                            el.setSetyle(ui->comboBox_style->currentIndex());
                            el.centr.SetXY(x,y);
                            el.setRx(rx);
                            el.setRy(ry);
                            if(ui->checkBox_fill->isChecked()){
                                brushcolor.getRGBA(r2,g2,b2,a2);
                                el.brush.setRGBA(r2,g2,b2,a2);
                                el.setSetyleb(ui->comboBox_styleb->currentIndex()+1);
                                el.drawfill(ui->widget->im);
                            } else{
                                el.drawnofill(ui->widget->im);
                            }
                            update();
                        }

                    }
                    else{
                        QMessageBox::warning(this, "Ошибка", "Ошибка в вертикальном радиусе");
                    }
                }
                else{
                    QMessageBox::warning(this, "Ошибка", "Ошибка в горизонтальном радиусе");
                }
            }
            else{
                QMessageBox::warning(this, "Ошибка", "Ошибка в координате y");
            }
        } else {
            QMessageBox::warning(this, "Ошибка", "Ошибка в координате x");
        }
        break;
    }
    case 5:{ //Выбрана дуга
        int x,y,rx,ry,startangle,spanangle,n;
        bool fl;
        QString str;
        arc ar;
        n=ui->spinBox->value();
        str.clear();
        str.append(ui->lineEdit_x->text());
        x=str.toInt(&fl);
        if(fl){
            str.clear();
            str.append(ui->lineEdit_y->text());
            y=str.toInt(&fl);
            if(fl){
                str.clear();
                str.append(ui->lineEdit_x2->text());
                rx=str.toInt(&fl);
                if (fl&&rx>0){
                    str.clear();
                    str.append(ui->lineEdit_y2->text());
                    ry=str.toInt(&fl);
                    if(fl&&ry>0){
                        str.clear();
                        str.append(ui->lineEdit_startangle->text());
                        startangle=str.toInt(&fl);
                        if(fl){
                            str.clear();
                            str.append(ui->lineEdit_spanangle ->text());
                            spanangle=str.toInt(&fl);
                            if(fl){
                                fl=change_colour();
                                if(fl)
                                {
                                    pencolor.getRGBA(r1,g1,b1,a1);
                                    ar.pen.setRGBA(r1,g1,b1,a1);
                                    ar.setWidth(n);
                                    ar.setSetyle(ui->comboBox_style->currentIndex());
                                    ar.centr.SetXY(x,y);
                                    ar.setRx(rx);
                                    ar.setRy(ry);
                                    ar.setStartangle(startangle);
                                    ar.setSpanangle(spanangle);
                                    ar.draw(ui->widget->im);
                                    update();
                                }

                            }
                            else {
                                QMessageBox::warning(this, "Ошибка", "Ошибка в конечном угле");
                            }
                        }
                        else {
                            QMessageBox::warning(this, "Ошибка", "Ошибка в начальном угле");
                        }
                    }
                    else {
                        QMessageBox::warning(this, "Ошибка", "Ошибка в вертикальном радиусе");
                    }
                }
                else {
                    QMessageBox::warning(this, "Ошибка", "Ошибка в горизонтальном радиусе");
                }
            }
            else {
                QMessageBox::warning(this, "Ошибка", "Ошибка в координате y");
            }
        }
        else {
            QMessageBox::warning(this, "Ошибка", "Ошибка в координате x");
        }
        break;
    }
    case 6: {//Выбрана ломанная линия
        okno *my_w = new okno(this);
        my_w->setWindowModality(Qt::WindowModal);
        connect(my_w, SIGNAL(exportFlag(bool)), this, SLOT(importFlag(bool)));
        connect(my_w, SIGNAL(exportMas(int *, int)), this, SLOT(importMas(int *, int)));
        isbline = true;
        my_w->show();
        break;
    }
    case 7: { //Выбран многоугольник
        okno *my_w = new okno(this);
        my_w->setWindowModality(Qt::WindowModal);
        connect(my_w, SIGNAL(exportFlag(bool)), this, SLOT(importFlag(bool)));
        connect(my_w, SIGNAL(exportMas(int *, int)), this, SLOT(importMas(int *, int)));
        my_w->show();
        ispolygon = true;
        break;
    }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index) //Выбор элемента отрисовки
{
    switch (index) {
    case 0:{ //Пиксель
        ui->lineEdit_x->setVisible(true);
        ui->lineEdit_y->setVisible(true);
        ui->label_x->setText("X");
        ui->label_y->setText("Y");
        ui->label_x2->setText("");
        ui->label_y2->setText("");
        ui->label_sa->setText("");
        ui->label_spa->setText("");
        ui->lineEdit_x2->setVisible(false);
        ui->lineEdit_y2->setVisible(false);
        ui->lineEdit_startangle->setVisible(false);
        ui->lineEdit_spanangle->setVisible(false);
        ui->label_fill->setVisible(false);
        ui->comboBox_style->setVisible(false);
        ui->label_width->setVisible(true);
        ui->spinBox->setVisible(true);
        ui->label_style->setVisible(false);
        ui->checkBox_fill->setVisible(false);
        ui->checkBox_fill->setChecked(false);
        ui->comboBox_styleb->setVisible(false);
        ui->label_styleb->setVisible(false);
        ui->checkBox_fill->setChecked(false);
        break;
    }
    case 1:{ //Линия
        ui->lineEdit_x->setVisible(true);
        ui->lineEdit_y->setVisible(true);
        ui->lineEdit_x2->setVisible(true);
        ui->lineEdit_y2->setVisible(true);
        ui->label_x->setText("X");
        ui->label_y->setText("Y");
        ui->label_x2->setText("X2");
        ui->label_y2->setText("Y2");
        ui->label_sa->setText("");
        ui->label_spa->setText("");
        ui->lineEdit_startangle->setVisible(false);
        ui->checkBox_fill->setChecked(false);
        ui->lineEdit_spanangle->setVisible(false);
        ui->label_fill->setVisible(false);
        ui->comboBox_style->setVisible(true);
        ui->label_style->setVisible(true);
        ui->checkBox_fill->setVisible(false);
        ui->comboBox_styleb->setVisible(false);
        ui->checkBox_fill->setChecked(false);
        ui->label_styleb->setVisible(false);
        if(ui->comboBox_style->currentIndex()==0)
        {
            ui->label_width->setVisible(false);
            ui->spinBox->setVisible(false);
        }
        break;
    }
    case 2:{ //Прямоугольник
        ui->lineEdit_x->setVisible(true);
        ui->lineEdit_y->setVisible(true);
        ui->lineEdit_x2->setVisible(true);
        ui->lineEdit_y2->setVisible(true);
        ui->label_x->setText("X");
        ui->label_y->setText("Y");
        ui->label_x2->setText("X2");
        ui->label_y2->setText("Y2");
        ui->label_sa->setText("");
        ui->label_spa->setText("");
        ui->lineEdit_startangle->setVisible(false);
        ui->lineEdit_spanangle->setVisible(false);
        ui->label_fill->setVisible(true);
        ui->comboBox_style->setVisible(true);
        ui->label_style->setVisible(true);
        ui->checkBox_fill->setVisible(true);
        if(ui->comboBox_style->currentIndex()==0)
        {
            ui->label_width->setVisible(false);
            ui->spinBox->setVisible(false);
        }
        break;
    }
    case 3:{ //Окружность
        ui->lineEdit_x->setVisible(true);
        ui->lineEdit_y->setVisible(true);
        ui->lineEdit_x2->setVisible(true);
        ui->lineEdit_y2->setVisible(false);
        ui->label_x->setText("X центра");
        ui->label_y->setText("Y центра");
        ui->label_x2->setText("Радиус");
        ui->label_y2->setText("");
        ui->label_sa->setText("");
        ui->label_spa->setText("");
        ui->lineEdit_startangle->setVisible(false);
        ui->lineEdit_spanangle->setVisible(false);
        ui->label_fill->setVisible(true);
        ui->comboBox_style->setVisible(true);
        ui->label_style->setVisible(true);
        ui->checkBox_fill->setVisible(true);
        if(ui->comboBox_style->currentIndex()==0)
        {
            ui->label_width->setVisible(false);
            ui->spinBox->setVisible(false);
        }
        break;
    }
    case 4:{ //Эллипс
        ui->lineEdit_x->setVisible(true);
        ui->lineEdit_y->setVisible(true);
        ui->lineEdit_x2->setVisible(true);
        ui->lineEdit_y2->setVisible(true);
        ui->label_x->setText("X центра");
        ui->label_y->setText("Y центра");
        ui->label_x2->setText("Гор. радиус");
        ui->label_y2->setText("Верт. радиус");
        ui->label_sa->setText("");
        ui->label_spa->setText("");
        ui->lineEdit_startangle->setVisible(false);
        ui->lineEdit_spanangle->setVisible(false);
        ui->label_fill->setVisible(true);
        ui->comboBox_style->setVisible(true);
        ui->label_style->setVisible(true);
        ui->checkBox_fill->setVisible(true);
        if(ui->comboBox_style->currentIndex()==0)
        {
            ui->label_width->setVisible(false);
            ui->spinBox->setVisible(false);
        }
        break;
    }
    case 5:{ //Дуга
        ui->lineEdit_x->setVisible(true);
        ui->lineEdit_y->setVisible(true);
        ui->lineEdit_x2->setVisible(true);
        ui->lineEdit_y2->setVisible(true);
        ui->label_x->setText("X центра");
        ui->label_y->setText("Y центра");
        ui->label_x2->setText("Гор. радиус");
        ui->label_y2->setText("Верт. радиус");
        ui->label_sa->setText("Нач. угол (в°)");
        ui->label_spa->setText("Угловая длина (в°)");
        ui->lineEdit_startangle->setVisible(true);
        ui->lineEdit_spanangle->setVisible(true);
        ui->label_fill->setVisible(false);
        ui->comboBox_style->setVisible(true);
        ui->checkBox_fill->setChecked(false);
        if(ui->comboBox_style->currentIndex()==0)
        {
            ui->label_width->setVisible(false);
            ui->spinBox->setVisible(false);
        }
        ui->label_style->setVisible(true);
        ui->checkBox_fill->setVisible(false);
        break;
    }
    case 6:{ //Ломанная линия
        ui->lineEdit_x->setVisible(false);
        ui->lineEdit_y->setVisible(false);
        ui->lineEdit_x2->setVisible(false);
        ui->lineEdit_y2->setVisible(false);
        if(ui->comboBox_style->currentIndex()==0)
        {
            ui->label_width->setVisible(false);
            ui->spinBox->setVisible(false);
        }
        ui->label_x->setText("");
        ui->label_y->setText("");
        ui->label_x2->setText("");
        ui->label_y2->setText("");
        ui->label_sa->setText("");
        ui->label_spa->setText("");
        ui->lineEdit_startangle->setVisible(false);
        ui->lineEdit_spanangle->setVisible(false);
        ui->label_fill->setVisible(false);
        ui->comboBox_style->setVisible(true);
        ui->checkBox_fill->setChecked(false);
        ui->label_style->setVisible(true);
        ui->checkBox_fill->setVisible(false);
        ui->comboBox_styleb->setVisible(false);
        ui->checkBox_fill->setChecked(false);
        ui->label_styleb->setVisible(false);
        break;
    }
    case 7:{ //Многоугольник
        ui->lineEdit_x->setVisible(false);
        ui->lineEdit_y->setVisible(false);
        ui->lineEdit_x2->setVisible(false);
        ui->lineEdit_y2->setVisible(false);
        ui->label_x->setText("");
        ui->label_y->setText("");
        ui->label_x2->setText("");
        ui->label_y2->setText("");
        ui->label_sa->setText("");
        ui->label_spa->setText("");
        ui->lineEdit_startangle->setVisible(false);
        ui->lineEdit_spanangle->setVisible(false);
        ui->label_fill->setVisible(true);
        ui->comboBox_style->setVisible(true);
        ui->label_style->setVisible(true);
        ui->checkBox_fill->setVisible(true);
        if(ui->comboBox_style->currentIndex()==0)
        {
            ui->label_width->setVisible(false);
            ui->spinBox->setVisible(false);
        }
        break;
    }
    }
}

void MainWindow::on_checkBox_fill_stateChanged(int arg1) //Изменен выбор заливки
{
    if(arg1==0){
        ui->comboBox_styleb->setVisible(false);
        ui->label_styleb->setVisible(false);
    }
    else
    {
        ui->comboBox_styleb->setVisible(true);
        ui->label_styleb->setVisible(true);
    }
}

void MainWindow::on_comboBox_style_currentIndexChanged(int index) //Изменение стиля pen
{
    if (index == 0){ //Стиль NoPen
        ui->label_width->setVisible(false);
        ui->spinBox->setVisible(false);
    }
    else{
        ui->label_width->setVisible(true);
        ui->spinBox->setVisible(true);
    }
}

bool MainWindow::change_colour()
{
    QColor color;
    if(ui->comboBox_style->currentIndex()!=0){
    color = QColorDialog::getColor(Qt::white, this, tr("Цвет "), QColorDialog::ShowAlphaChannel); //через диалоговое окно получаем цвет
    color.getRgb(&r1, &g1, &b1, &a1);
    pencolor.setRGBA(r1,g1,b1,a1);
    }
    if(ui->checkBox_fill->isChecked()){
        color = QColorDialog::getColor(Qt::white, this, tr("Цвет заливки"), QColorDialog::ShowAlphaChannel); //через диалоговое окно получаем цвет
        color.getRgb(&r2, &g2, &b2, &a2);
       brushcolor.setRGBA(r2,g2,b2,a2);
    }
    return color.isValid();
}
