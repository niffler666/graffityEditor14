#ifndef WIDGET_OLD_H
#define WIDGET_OLD_H

#include <QWidget>

class widget_old : public QWidget
{
    Q_OBJECT
public:
    explicit widget_old(QWidget *parent = nullptr);
    QImage im;
    void create_image(int size_x, int size_y);
private:
    bool im_created;

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *);
};

#endif // WIDGET_OLD_H
