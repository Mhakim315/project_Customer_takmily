#ifndef CHART_INVENTORY_PRODUCT_H
#define CHART_INVENTORY_PRODUCT_H

#include <QDialog>

namespace Ui {
class chart_inventory_product;
}

class chart_inventory_product : public QDialog
{
    Q_OBJECT

public:
    explicit chart_inventory_product(QWidget *parent = nullptr);
    ~chart_inventory_product();

private:
    Ui::chart_inventory_product *ui;
};

#endif // CHART_INVENTORY_PRODUCT_H
