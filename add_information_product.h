#ifndef ADD_INFORMATION_PRODUCT_H
#define ADD_INFORMATION_PRODUCT_H

#include <QDialog>

namespace Ui {
class add_information_product;
}

class add_information_product : public QDialog
{
    Q_OBJECT

public:
    explicit add_information_product(QWidget *parent = nullptr);
    ~add_information_product();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::add_information_product *ui;
};

#endif // ADD_INFORMATION_PRODUCT_H
