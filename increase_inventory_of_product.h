#ifndef INCREASE_INVENTORY_OF_PRODUCT_H
#define INCREASE_INVENTORY_OF_PRODUCT_H

#include <QDialog>

namespace Ui {
class increase_inventory_of_product;
}

class increase_inventory_of_product : public QDialog
{
    Q_OBJECT

public:
    explicit increase_inventory_of_product(QWidget *parent = nullptr);
    ~increase_inventory_of_product();

private slots:
    void on_pushButton_clicked();

private:
    Ui::increase_inventory_of_product *ui;
};

#endif // INCREASE_INVENTORY_OF_PRODUCT_H
