#include "add_information_product.h"
#include "ui_add_information_product.h"
#include "product_and_customer_class.h"
#include "QFile"
#include "QLabel"
#include "QWidget"
#include "QPushButton"
#include "QTextStream"
#include "QVBoxLayout"
#include "iostream"

using namespace std;


add_information_product::add_information_product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_information_product)
{
    ui->setupUi(this);
}

add_information_product::~add_information_product()
{
    delete ui;
}
void products::add_information_of_product(QString name, long inventory, long price)
{
    product_name = name;
    inventory_product = inventory;
    price_product= price;
    QFile file_information_product("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    if(!file_information_product.open( QFile::WriteOnly | QFile::Text | QFile::Append))
    {
        QWidget * window = new QWidget();
        window->setWindowTitle("Status of record information");
        QLabel *check = new QLabel("information was not recorded");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(check);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window, SLOT(close()));
        window->setLayout(layout);
        window->show();
        return;

    }
    QTextStream file_write(& file_information_product);
    file_write << product_name << "\n" << inventory_product <<"\n" << price_product<<"\n";
    //file_information_product << product_name << "\n" << inventory_product <<"\n" << price_product<<"\n";
    file_information_product.flush();
    file_information_product.close();
    return;
}

void add_information_product::on_pushButton_2_clicked()
{

}


void add_information_product::on_pushButton_clicked()
{
    QString product_name = ui->lineEdit_2->text();
    QString inventory_product = ui->lineEdit_3->text();
    QString price_product = ui->lineEdit_4->text();
    long inventory_product_long = inventory_product.toLong();
    long price_product_long = price_product.toLong();
    products p;
    p.add_information_of_product(product_name, inventory_product_long, price_product_long);

}

