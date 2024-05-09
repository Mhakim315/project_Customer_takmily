#ifndef SHOW_PRODUCT_BY_CLICK_H
#define SHOW_PRODUCT_BY_CLICK_H

#include <QDialog>

namespace Ui {
class show_product_by_click;
}

class show_product_by_click : public QDialog
{
    Q_OBJECT

public:
    explicit show_product_by_click(QWidget *parent = nullptr);
    ~show_product_by_click();

private slots:
    void on_pushButton_clicked();

private:
    Ui::show_product_by_click *ui;
};

#endif // SHOW_PRODUCT_BY_CLICK_H
