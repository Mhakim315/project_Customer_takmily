#include "chart_inventory_product.h"
#include "ui_chart_inventory_product.h"

chart_inventory_product::chart_inventory_product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::chart_inventory_product)
{
    ui->setupUi(this);
}

chart_inventory_product::~chart_inventory_product()
{
    delete ui;
}
