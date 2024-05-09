#include "delete_information_of_product.h"
#include "ui_delete_information_of_product.h"
#include "QFile"
#include "QLabel"
#include "QTextStream"
#include "QPushButton"
#include "QVBoxLayout"
#include "QWidget"

delete_information_of_product::delete_information_of_product(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delete_information_of_product)
{
    ui->setupUi(this);
}

delete_information_of_product::~delete_information_of_product()
{
    delete ui;
}

void delete_information_of_product::on_pushButton_clicked()
{
    QString name_product_To_delete = ui->lineEdit->text();
    QString name_in_file;
    QString inventory_in_file;
    QString price_in_file;

    bool check_exit_product_in_file = false;

    QFile file_information_products("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    QFile file_temporary("C:/Users/ModernSystem/Desktop/Temporary.txt");
    if(!file_information_products.open(QFile::ReadOnly | QFile::Text ))
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
    file_temporary.open(QFile::WriteOnly | QFile::Truncate);
    file_temporary.close();

    file_temporary.open(QFile::WriteOnly | QFile::Text);

    QTextStream read_in_file(& file_information_products);
    QTextStream write_in_file(& file_temporary);

    while(!read_in_file.atEnd())
    {
        name_in_file = read_in_file.readLine();
        inventory_in_file = read_in_file.readLine();
        price_in_file = read_in_file.readLine();


        if(name_in_file == name_product_To_delete)
        {
            check_exit_product_in_file = true;
            continue;
        }
        else
        {
            write_in_file << name_in_file <<"\n" << inventory_in_file <<"\n" <<price_in_file <<"\n";
        }
    }
    if(check_exit_product_in_file == false)
    {
        QWidget * window = new QWidget();
        window->setWindowTitle("Status of record information");
        QLabel *check = new QLabel("<b>product with name not found in warehouse</b>");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");

        layout->addWidget(check);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window, SLOT(close()));
        window->setLayout(layout);
        window->show();
        return;
    }

    file_information_products.close();
    file_temporary.close();

    file_information_products.open(QFile::WriteOnly | QFile::Truncate);
    file_information_products.close();

    file_information_products.open(QFile::WriteOnly | QFile::Text);
    file_temporary.open(QFile::ReadOnly | QFile::Text);

    QTextStream write_in_file_new(& file_information_products);
    QTextStream read_in_file_new(& file_temporary);

    while(!read_in_file_new.atEnd())
    {
        name_in_file = read_in_file_new.readLine();
        inventory_in_file = read_in_file_new.readLine();
        price_in_file = read_in_file_new.readLine();

        write_in_file_new << name_in_file <<"\n" <<inventory_in_file <<"\n" << price_in_file<<"\n";
    }

    file_information_products.close();
    file_temporary.close();
    return;

}




