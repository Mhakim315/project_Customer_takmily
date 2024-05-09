#include "add_information_of_customer.h"
#include "ui_add_information_of_customer.h"
#include "product_and_customer_class.h"
#include "QFile"
#include "QLabel"
#include "QWidget"
#include "QPushButton"
#include "QVBoxLayout"
#include "QTextStream"
#include "iomanip"
#include "QDebug"

add_information_of_customer::add_information_of_customer(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::add_information_of_customer)
{
    ui->setupUi(this);
}

add_information_of_customer::~add_information_of_customer()
{
    delete ui;
}
void Customer::Rewriting_the_product_file_after_the_product_stock_is_reduced(QString name,long inventory_new)
{
    QFile read_file_information_products("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    QFile write_in_temporary_file("C:/Users/ModernSystem/Desktop/Temporary.txt");
    if(!read_file_information_products.open(QFile::ReadOnly | QFile::Text))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("Error openning file for record information customer");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;
    }
    if(!write_in_temporary_file.open(QFile::WriteOnly | QFile::Truncate))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("Error openning file for record information customer");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_error, SLOT(close()));
        window_error->setLayout(layout);
        window_error->show();
        return;
    }

    write_in_temporary_file.close();
    write_in_temporary_file.open(QFile::WriteOnly | QFile::Text);
    QTextStream read_information_product_TO_temporary_file(& read_file_information_products);
    QTextStream write_information_product_in_temporary_file(& write_in_temporary_file);
    QString temporary_variable;
    while(!read_information_product_TO_temporary_file.atEnd())
    {
        temporary_variable = read_information_product_TO_temporary_file.readLine();
        write_information_product_in_temporary_file << temporary_variable <<"\n";
    }

    read_file_information_products.close();
    write_in_temporary_file.close();

    read_file_information_products.open(QFile::WriteOnly | QFile::Truncate);
    read_file_information_products.close();

    read_file_information_products.open(QFile::WriteOnly | QFile::Text);
    write_in_temporary_file.open(QFile::ReadOnly | QFile::Text);

    QTextStream read_in_file(& write_in_temporary_file);
    QTextStream write_in_file(& read_file_information_products);

    QString name_product_in_file;
    QString inventory_product_in_file;
    QString price_product_in_file;

    while(!read_in_file.atEnd())
    {
        name_product_in_file = read_in_file.readLine();
        inventory_product_in_file = read_in_file.readLine();
        price_product_in_file = read_in_file.readLine();
        if(name_product_in_file == name)
        {
            write_in_file << name_product_in_file << "\n" << inventory_new << "\n" << price_product_in_file<<"\n";
        }
        else
        {
            write_in_file << name_product_in_file << "\n" << inventory_product_in_file << "\n" << price_product_in_file<<"\n";
        }

    }
    read_file_information_products.close();
    write_in_temporary_file.close();
    return;


}
void Customer::add_information_of_Customer(QString name, QString family, QString phone, QString product, long number, int y, int m, int d, long final)
{
    //conter of product baraye in ast ke dar khorojjy shomare mahssool ham moshakhas bashad
    conter_of_customer++;
    Customer_name = name;
    Customer_lastname = family;
    Customer_phone_number = phone;
    product_name_of_order = product;
    year_order = y;
    month_order = m;
    day_order = d;
    number_product_of_order = number;
    final_price_of_record = final;

    QFile write_information("C:/Users/ModernSystem/Desktop/Qtcreator2.txt");
    if(!write_information.open(QFile::WriteOnly | QFile::Text | QFile::Append))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status record information customer");
        QLabel *error = new QLabel("Error openning file for record information customer");
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(error);
        window_error->setLayout(layout);
        window_error->show();
        return;
    }
    QTextStream file_write_information(& write_information);

    file_write_information << Customer_name << "\n"<< Customer_lastname << "\n"<< Customer_phone_number <<"\n";
    file_write_information << year_order << "\n" << month_order <<"\n" << day_order <<"\n";
    file_write_information << product_name_of_order << "\n" << number_product_of_order <<"\n";
    file_write_information << final_price_of_record <<"\n";

    write_information.close();
}
long Customer::check_of_product_record_customer(QString name_product_of_check, long number)
{
    QFile read_in_file_information("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    if(!read_in_file_information.open(QFile::ReadOnly | QFile::Text))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status file information customers");
        QLabel *error = new QLabel("Error openning file information Customers");
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(error);
        window_error->setLayout(layout);
        window_error->show();
        return 1;
    }
    Customer p;//dar dakhel halghe baead tabe=tagheerat mooojody ra farakhany konim
    bool check_exit_product_in_file = false;
    QString name_search, inventory_search, price_search;
    QTextStream check_name_product_in_file(& read_in_file_information);
    while(!check_name_product_in_file.atEnd())
    {
        name_search = check_name_product_in_file.readLine();
        if(name_search == name_product_of_check)
        {
            inventory_search = check_name_product_in_file.readLine();
            long inventory_search_long = inventory_search.toLong();
            price_search = check_name_product_in_file.readLine();
            check_exit_product_in_file =true;
            if(number <= inventory_search_long)
            {
                long final_price_for_order = number * inventory_search_long;
                inventory_search_long = inventory_search_long - number;
                p.Rewriting_the_product_file_after_the_product_stock_is_reduced(name_search,inventory_search_long);
                read_in_file_information.close();
                return final_price_for_order;
            }
            else
            {
                QWidget *window_error_not_enogh_product = new QWidget();
                window_error_not_enogh_product->setWindowTitle("Status inventory of product");
                QLabel *error = new QLabel("not enogh inventory of product in warehouse");
                QVBoxLayout *layout = new QVBoxLayout();
                layout->addWidget(error);
                window_error_not_enogh_product->setLayout(layout);
                window_error_not_enogh_product->show();
                read_in_file_information.close();
                return 1;
            }
        }
        else
        {
            inventory_search = check_name_product_in_file.readLine();
            price_search = check_name_product_in_file.readLine();

        }


    }
    read_in_file_information.close();
    if(check_exit_product_in_file == false)
    {
        QWidget *window_error_no_found_product = new QWidget();
        window_error_no_found_product->setWindowTitle("Status found of product");
        QLabel *error2 = new QLabel("product with name not found in file");
        QVBoxLayout *layout2 = new QVBoxLayout();
        layout2->addWidget(error2);
        window_error_no_found_product->setLayout(layout2);
        window_error_no_found_product->show();
        return 1;
    }

}

void add_information_of_customer::on_pushButton_clicked()
{
    QString name = ui ->lineEdit->text();
    QString family = ui->lineEdit_2->text();
    QString phone = ui->lineEdit_3->text();
    QString product_record = ui->lineEdit_4->text();
    QString number_product = ui->lineEdit_5->text();
    long number_product_long = number_product.toLong();
    int year_order = ui->dateEdit->YearSection;
    int month_order = ui->dateEdit->MonthSection;
    int day_order = ui->dateEdit->DaySection;
    Customer c;
    long final_price_check_in_fanction = c.check_of_product_record_customer(product_record, number_product_long);
    if(final_price_check_in_fanction != 1)
    {
        c.add_information_of_Customer(name, family, phone, product_record, number_product_long, year_order, month_order, day_order, final_price_check_in_fanction);
    }
}



