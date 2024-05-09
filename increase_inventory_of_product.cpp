#include "increase_inventory_of_product.h"
#include "ui_increase_inventory_of_product.h"
#include "QLabel"
#include "QPushButton"
#include "QWidget"
#include "QVBoxLayout"
#include "QTextStream"
#include "QFile"


increase_inventory_of_product::increase_inventory_of_product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::increase_inventory_of_product)
{
    ui->setupUi(this);
}

increase_inventory_of_product::~increase_inventory_of_product()
{
    delete ui;
}

void increase_inventory_of_product::on_pushButton_clicked()
{
    QString product_name_of_increase_inventory = ui->lineEdit->text();
    QString inventory_of_increase = ui->lineEdit_2->text();
    QString name_product_in_file;
    QString inventory_in_file;
    QString price_in_file;

    QFile temporary_file("C:/Users/ModernSystem/Desktop/Temporary2.txt");
    temporary_file.open(QFile::WriteOnly | QFile::Truncate);
    temporary_file.close();

    temporary_file.open(QFile::WriteOnly | QFile::Text);
    QFile increase_of_inventory_product("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    if(!increase_of_inventory_product.open(QFile::ReadOnly | QFile::Text))
    {
        QWidget * window = new QWidget();
        window->setWindowTitle("Status of record information");
        QLabel *check = new QLabel("information was not recorded");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(check);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window , SLOT(close()));
        window->setLayout(layout);
        window->show();
        return;
    }
    QTextStream read_file(& increase_of_inventory_product);
    QTextStream write_file(& temporary_file);

    long inventory_new = 0;
    while(!read_file.atEnd())
    {
        name_product_in_file = read_file.readLine();
        inventory_in_file = read_file.readLine();
        inventory_new = inventory_in_file.toLong();
        price_in_file = read_file.readLine();
        if(name_product_in_file == product_name_of_increase_inventory)
        {
            inventory_new += inventory_of_increase.toLong();
            write_file << name_product_in_file <<"\n"<<QString::number(inventory_new) <<"\n" <<price_in_file<<"\n";
        }
        else
        {
            write_file << name_product_in_file <<"\n"<< inventory_in_file <<"\n" <<price_in_file<<"\n";
        }

    }

    increase_of_inventory_product.close();
    temporary_file.close();

    increase_of_inventory_product.open(QFile::WriteOnly | QFile::Truncate);
    increase_of_inventory_product.close();

    increase_of_inventory_product.open(QFile::WriteOnly | QFile::Text);
    temporary_file.open(QFile::ReadOnly | QFile::Text);

    QTextStream read_file_in_temporary(& temporary_file);
    QTextStream write_file_on_increase(& increase_of_inventory_product);

    while(!read_file_in_temporary.atEnd())
    {
        name_product_in_file = read_file_in_temporary.readLine();
        inventory_in_file = read_file_in_temporary.readLine();
        price_in_file = read_file_in_temporary.readLine();
        write_file_on_increase << name_product_in_file <<"\n"<<inventory_in_file<<"\n"<<price_in_file<<"\n";
    }
    temporary_file.close();
    increase_of_inventory_product.close();
    return;
}

