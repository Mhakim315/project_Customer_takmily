#include "delete_information_customer.h"
#include "ui_delete_information_customer.h"
#include "QFile"
#include "QLabel"
#include "QPushButton"
#include "QWidget"
#include "QVBoxLayout"
#include "QTextStream"


delete_information_Customer::delete_information_Customer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::delete_information_Customer)
{
    ui->setupUi(this);
}

delete_information_Customer::~delete_information_Customer()
{
    delete ui;
}

void delete_information_Customer::on_pushButton_clicked()
{
    QString Customer_name_of_delete = ui->lineEdit->text();
    QString Customer_lastname_of_delete = ui->lineEdit_2->text();
    QString Customer_name;
    QString Customer_lastname;
    QString Customer_phone_number;
    QString year_in_file, month_in_file, day_in_file;
    QString product_name_in_file;
    QString number_product_in_file;
    QString final_price_in_file;

    bool check_exit_Customer_with_name_and_family = false;

    QFile file_information_product("C:/Users/ModernSystem/Desktop/Qtcreator2.txt");
    QFile file_temporary("C:/Users/ModernSystem/Desktop/Temporary2.txt");
    if(!file_information_product.open(QFile::ReadOnly | QFile::Text) | !file_temporary.open(QFile::WriteOnly | QFile::Truncate))
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
    file_temporary.close();
    file_temporary.open(QFile::WriteOnly | QFile::Text);

    QTextStream information_product_read(& file_information_product);
    QTextStream Temporary_information_product(& file_temporary);

    while(!information_product_read.atEnd())
    {
        Customer_name = information_product_read.readLine();
        Customer_lastname = information_product_read.readLine();
        Customer_phone_number = information_product_read.readLine();
        year_in_file = information_product_read.readLine();
        month_in_file = information_product_read.readLine();
        day_in_file = information_product_read.readLine();
        product_name_in_file = information_product_read.readLine();
        number_product_in_file = information_product_read.readLine();
        final_price_in_file = information_product_read.readLine();

        if(Customer_name == Customer_name_of_delete && Customer_lastname == Customer_lastname_of_delete)
        {
            check_exit_Customer_with_name_and_family = true;
            continue;
        }
        else
        {
            Temporary_information_product << Customer_name << "\n" << Customer_lastname <<"\n"<<Customer_phone_number<<"\n";
            Temporary_information_product << year_in_file <<"\n" <<month_in_file <<"\n" <<day_in_file<<"\n";
            Temporary_information_product << product_name_in_file << "\n" <<number_product_in_file <<"\n"<<final_price_in_file<<"\n";

        }
    }

    file_information_product.close();
    file_temporary.close();

    file_information_product.open(QFile::WriteOnly | QFile::Truncate);
    file_information_product.close();

    file_information_product.open(QFile::WriteOnly | QFile::Text);
    file_temporary.open(QFile::ReadOnly | QFile::Text);

    QTextStream read_in_file(& file_temporary);
    QTextStream write_in_file(& file_information_product);

    while(!read_in_file.atEnd())
    {
        Customer_name = read_in_file.readLine();
        Customer_lastname =read_in_file.readLine();
        Customer_phone_number = read_in_file.readLine();
        year_in_file = read_in_file.readLine();
        month_in_file = read_in_file.readLine();
        day_in_file = read_in_file.readLine();
        product_name_in_file = read_in_file.readLine();
        number_product_in_file = read_in_file.readLine();
        final_price_in_file = read_in_file.readLine();

        write_in_file << Customer_name << "\n" << Customer_lastname <<"\n"<<Customer_phone_number<<"\n";
        write_in_file << year_in_file <<"\n" <<month_in_file <<"\n" <<day_in_file<<"\n";
        write_in_file << product_name_in_file << "\n" <<number_product_in_file <<"\n"<<final_price_in_file<<"\n";
    }

    file_information_product.close();
    file_temporary.close();
    return;
}




