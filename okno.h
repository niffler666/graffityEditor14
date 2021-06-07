#ifndef OKNO_H
#define OKNO_H

#include <QMainWindow>
#include <QMessageBox>

namespace Ui {
class okno;
}

class okno : public QMainWindow
{
    Q_OBJECT

public:
    explicit okno(QWidget *parent = nullptr);
    ~okno();

private slots:

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_tableWidget_cellChanged(int row, int column);

private:
    Ui::okno *ui;
signals:
    void exportMas(int *mas, int size);
    void exportFlag(bool fl);
};

#endif // OKNO_H
