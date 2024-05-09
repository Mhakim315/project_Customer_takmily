#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "add_information_product.h"
#include "product_and_customer_class.h"
#include "add_information_of_customer.h"
#include "show_product_by_click.h"
#include "show_information_of_customer.h"
#include "increase_inventory_of_product.h"
#include "delete_information_of_product.h"
#include "delete_information_customer.h"
#include "show_turnover.h"
#include "QFile"
#include "QLabel"
#include "QPushButton"
#include "QWidget"
#include "QVBoxLayout"
#include "QTextStream"
#include "QHBoxLayout"
#include "vector"
#include "QVector"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_2_clicked()
{
    add_information_product *window_record = new add_information_product();
    window_record->show();
}


void MainWindow::on_pushButton_3_clicked()
{
    QFile file_information_product("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    if(!file_information_product.open(QFile::ReadOnly | QFile::Text))
    {
        QWidget *window_error = new QWidget();
        window_error->setWindowTitle("Status of show information product");
        QLabel *error = new QLabel("Error openning file for show information of products");
        QVBoxLayout *layout = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout->addWidget(error);
        layout->addWidget(button_ok);
        window_error->setLayout(layout);
        return;
    }

    QString name_product_in_file;
    QString inventory_product_in_file;
    QString price_product_in_file;

    QWidget *window_of_show_product = new QWidget();
    window_of_show_product->setWindowTitle("information of products");
    QTextStream read_in_file_information_product(& file_information_product);
    QVBoxLayout *layout2 = new QVBoxLayout();

    while(!read_in_file_information_product.atEnd())
    {
        name_product_in_file = read_in_file_information_product.readLine();
        if(read_in_file_information_product.atEnd())
            break;
        inventory_product_in_file = read_in_file_information_product.readLine();
        price_product_in_file = read_in_file_information_product.readLine();

        QLabel *name_product = new QLabel("product name : " + name_product_in_file);
        QLabel *inventory_product = new QLabel("inventory of product : " + inventory_product_in_file);
        QLabel *price_product = new QLabel("price product : " + price_product_in_file);
        QLabel *fasele = new QLabel ("**********************************");

        layout2->addWidget(name_product);
        layout2->addWidget(inventory_product);
        layout2->addWidget(price_product);
        layout2->addWidget(fasele);

    }
    file_information_product.close();
    window_of_show_product->setLayout(layout2);
    window_of_show_product->show();
    return;
}


void MainWindow::on_pushButton_4_clicked()
{
    add_information_of_customer *window_record_information_customers = new add_information_of_customer();
    window_record_information_customers->show();
}


void MainWindow::on_pushButton_5_clicked()
{
    QWidget *window_information_Customer = new QWidget();
    window_information_Customer->setWindowTitle("information of Customers");
    QVBoxLayout *layout3 = new QVBoxLayout();

    QFile read_in_file_information_customer("C:/Users/ModernSystem/Desktop/Qtcreator2.txt");
    if(!read_in_file_information_customer.open(QFile::ReadOnly | QFile::Text ))
    {
        QLabel *error = new QLabel("<b>error openning file for read information of customers</b>");
        QVBoxLayout *layout2 = new QVBoxLayout();
        QPushButton *button_ok = new QPushButton("ok");
        layout2->addWidget(error);
        layout2->addWidget(button_ok);
        button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_information_Customer, SLOT(close()));
        window_information_Customer->setLayout(layout2);
        window_information_Customer->show();

        return;
    }
    QString Customer_name_in_file;
    QString Customer_lastname_in_file;
    QString Customer_phone_number_in_file;
    QString year_in_file, month_in_file, day_in_file;
    QString product_name_in_file;
    QString number_product_in_file;
    QString final_price_in_file;

    QTextStream file_information(& read_in_file_information_customer);
    while(!file_information.atEnd())
    {
        Customer_name_in_file = file_information.readLine();
        if(file_information.atEnd())
            break;
        Customer_lastname_in_file = file_information.readLine();
        Customer_phone_number_in_file = file_information.readLine();
        year_in_file = file_information.readLine();
        month_in_file = file_information.readLine();
        day_in_file = file_information.readLine();
        product_name_in_file = file_information.readLine();
        number_product_in_file = file_information.readLine();
        final_price_in_file = file_information.readLine();

        QLabel *Customer_name = new QLabel("Customer name : " + Customer_name_in_file);
        QLabel *Customer_lastname = new QLabel("Customer last name : " + Customer_lastname_in_file);
        QLabel *Customer_phone_number = new QLabel("Customer phone number : " + Customer_phone_number_in_file);
        QLabel *Customer_Date_order = new QLabel ("Customer Date order : " + year_in_file + "/" + month_in_file + "/" + day_in_file);
        QLabel *product_name = new QLabel("product name TO order : " + product_name_in_file);
        QLabel *number_product = new QLabel("number product order : " + number_product_in_file);
        QLabel *final_price = new QLabel("final price of product : " + final_price_in_file);
        QLabel *fasele = new QLabel("************************************");

        layout3->addWidget(Customer_name);
        layout3->addWidget(Customer_lastname);
        layout3->addWidget(Customer_phone_number);
        layout3->addWidget(Customer_Date_order);
        layout3->addWidget(product_name);
        layout3->addWidget(number_product);
        layout3->addWidget(final_price);
        layout3->addWidget(fasele);
    }
    QPushButton *button_ok = new QPushButton("ok");
    layout3->addWidget(button_ok);
    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_information_Customer, SLOT(close()));
    window_information_Customer->setLayout(layout3);
    window_information_Customer->show();
    return;

}
void products::show_product_by_click_in_name(QString name, QString inventory, QString price)
{
    //product_name = name;
    //inventory_product = inventory;
    //price_product = price;
    QWidget *show = new QWidget();
    show->setWindowTitle("information of product");
    QVBoxLayout *layout = new QVBoxLayout();
    QLabel *name_lbl = new QLabel(name);
    QLabel *inventory_lbl = new QLabel(inventory);
    QLabel *price_lbl = new QLabel(price);
    layout->addWidget(name_lbl);
    layout->addWidget(inventory_lbl);
    layout->addWidget(price_lbl);
    show->setLayout(layout);
    show->show();
}


void MainWindow::on_pushButton_6_clicked()
{
    show_product_by_click *window_show = new show_product_by_click();
    window_show->show();
    // QFile read_in_file("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    // if(!read_in_file.open(QFile::ReadOnly | QFile::Text))
    // {
    //     QWidget *window_information_products = new QWidget();
    //     window_information_products->setWindowTitle("Status file information products");
    //     QLabel *error = new QLabel("error openning file for read information of customers");
    //     QVBoxLayout *layout2 = new QVBoxLayout();
    //     layout2->addWidget(error);
    //     window_information_products->setLayout(layout2);
    //     window_information_products->show();
    //     return;
    // }
    // show_product_by_click *window_of_name_products = new show_product_by_click();
    // window_of_name_products->setWindowTitle("Menu of name product for see information by click");
    // QHBoxLayout *layout2 = new QHBoxLayout();
    // QString name_product_in_file, inventory_product_in_file, price_product_in_file;
    // QTextStream write_name_with_file(& read_in_file);
    // products p;
    // int conter = 1;
    // while(!write_name_with_file.atEnd())
    // {
    //     name_product_in_file = write_name_with_file.readLine();
    //     inventory_product_in_file = write_name_with_file.readLine();
    //     price_product_in_file = write_name_with_file.readLine();
    //     if(write_name_with_file.atEnd())
    //         break;
    //     QString lbl = "product " + QString::number(conter) + " : ";
    //     QLabel *name_lbl = new QLabel(lbl);
    //     QLabel *name = new QLabel(name_product_in_file);
    //     layout2->addWidget(name_lbl);
    //     layout2->addWidget(name);
    //     conter++;
    // }
    // window_of_name_products->setLayout(layout2);
    // window_of_name_products->show();
    // return;
}


void MainWindow::on_pushButton_7_clicked()
{
    show_information_of_customer *window_show = new show_information_of_customer();
    window_show->show();
}


void MainWindow::on_pushButton_8_clicked()
{
    show_turnover *window_show_turnover = new show_turnover();
    window_show_turnover->show();
}


void MainWindow::on_pushButton_9_clicked()
{
    increase_inventory_of_product * window_of_show = new increase_inventory_of_product();
    window_of_show->show();
}


void MainWindow::on_pushButton_10_clicked()
{
    delete_information_of_product *window_of_show = new delete_information_of_product();
    window_of_show->show();
}


void MainWindow::on_pushButton_11_clicked()
{
    delete_information_Customer *window_of_information_customer = new delete_information_Customer();
    window_of_information_customer->show();
}


void MainWindow::on_pushButton_12_clicked()
{
    QString product_name_in_file;
    QString inventory_product_in_file;
    QString price_product_in_file;

    QFile information_product("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    if(!information_product.open(QFile::ReadOnly | QFile::Text))
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
    int conter_star ;
    long inventory_temporary;
    QString star_of_chart_inventory;
    QTextStream read_in_file_information_product(& information_product);

    QWidget *window_of_chart_product = new QWidget();
    window_of_chart_product->setWindowTitle("chart inventory of product");
    QVBoxLayout *layout_chart = new QVBoxLayout();
    QLabel *tozeeh = new QLabel("<b>In this chart one star is printed for evry 100000 items in stock of the product</b>");
    layout_chart->addWidget(tozeeh);
    QLabel *fasele = new QLabel(" ");
    layout_chart->addWidget(fasele);

    while(!read_in_file_information_product.atEnd())
    {
        product_name_in_file = read_in_file_information_product.readLine();
        inventory_product_in_file = read_in_file_information_product.readLine();
        price_product_in_file = read_in_file_information_product.readLine();

        inventory_temporary = inventory_product_in_file.toLong();

        while(inventory_temporary>0)
        {
            inventory_temporary -= 100000;
            star_of_chart_inventory += "*";
        }

        QLabel *name_product_To_chart = new QLabel("product name : " + product_name_in_file+"   "+ star_of_chart_inventory);
        layout_chart->addWidget(name_product_To_chart);
    }
    information_product.close();

    QPushButton *button_ok = new QPushButton("ok");
    layout_chart->addWidget(button_ok);
    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_of_chart_product, SLOT(close()));

    window_of_chart_product->setLayout(layout_chart);
    window_of_chart_product->show();

}





void MainWindow::on_pushButton_13_clicked()
{
    QString Customer_name;
    QString Customer_lastname;
    QString Customer_phone_number;
    QString year_in_file, month_in_file, day_in_file;
    QString product_name_in_file;
    QString number_product_in_file;
    QString final_price_in_file;


    QFile information_customer("C:/Users/ModernSystem/Desktop/Qtcreator2.txt");
    QFile year_file("C:/Users/ModernSystem/Desktop/Allyear.txt");
    if(!information_customer.open(QFile::ReadOnly | QFile::Text) | !year_file.open(QFile::WriteOnly | QFile::Truncate))
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
    year_file.close();

    int conter_number_of_customer_in_file = 0;
    QTextStream read_year_in_file(& information_customer);
    while(!read_year_in_file.atEnd())
    {
        Customer_name = read_year_in_file.readLine();
        Customer_lastname = read_year_in_file.readLine();
        Customer_phone_number = read_year_in_file.readLine();
        year_in_file = read_year_in_file.readLine();
        month_in_file = read_year_in_file.readLine();
        day_in_file = read_year_in_file.readLine();
        product_name_in_file = read_year_in_file.readLine();
        number_product_in_file = read_year_in_file.readLine();
        final_price_in_file = read_year_in_file.readLine();
        conter_number_of_customer_in_file++;

    }
    information_customer.close();
    year_file.close();

    int arayye_of_year_in_file[conter_number_of_customer_in_file] = {0};

    information_customer.open(QFile::ReadOnly | QFile::Text);
    int i = 0;
    QTextStream read_year_in_file_2(& information_customer);
    while(!read_year_in_file_2.atEnd())
    {
        Customer_name = read_year_in_file_2.readLine();
        Customer_lastname = read_year_in_file_2.readLine();
        Customer_phone_number = read_year_in_file_2.readLine();
        year_in_file = read_year_in_file_2.readLine();
        month_in_file = read_year_in_file_2.readLine();
        day_in_file = read_year_in_file_2.readLine();
        product_name_in_file = read_year_in_file_2.readLine();
        number_product_in_file = read_year_in_file_2.readLine();
        final_price_in_file = read_year_in_file_2.readLine();
        arayye_of_year_in_file[i] = year_in_file.toInt();
        i++;
    }
    information_customer.close();

    year_file.open(QFile::WriteOnly | QFile::Text);
    QTextStream write_in_temporary_file(& year_file);
    bool check_write_in_temporary_file ;

    //moratam sazee sal ha bar asas tarteeb bozorgy va kochaky

    for(int i=0; i<conter_number_of_customer_in_file; i++)
    {
        for(int j=0; j<conter_number_of_customer_in_file-i-1; j++)
        {
            if(arayye_of_year_in_file[j] > arayye_of_year_in_file[j+1])
            {
                int swap = arayye_of_year_in_file[j];
                arayye_of_year_in_file[j] = arayye_of_year_in_file[j+1];
                arayye_of_year_in_file[j+1] = swap;
            }
        }
    }

    for(int conter=0; conter<conter_number_of_customer_in_file; conter++)
    {
        check_write_in_temporary_file = true;
        for(int conter2 = conter+1; conter2<conter_number_of_customer_in_file-1; conter2++)
        {
            if(arayye_of_year_in_file[conter] == arayye_of_year_in_file[conter2])
            {
                check_write_in_temporary_file = false;

            }
        }
        if(check_write_in_temporary_file == true && arayye_of_year_in_file[conter] != 0)
        {
            write_in_temporary_file << arayye_of_year_in_file[conter]<<"\n";
        }
    }
    year_file.close();

   //ta inja sal haee ke dar onn ha khared anjam shode ast ra dar file allyear harar dadim
    year_file.open(QFile::ReadOnly | QFile::Text);

    QTextStream read_year_in_temporary_file(& year_file);

    QWidget *window_show_information_of_Customer_with_chart = new QWidget();
    window_show_information_of_Customer_with_chart->setWindowTitle("turnover information Custoemrs");
    QVBoxLayout *layout_chart_Customer = new QVBoxLayout();
    QLabel *tozeeh = new QLabel("<b> In this chart, one star is printed for evry 10000000 Tomans</b>");
    layout_chart_Customer->addWidget(tozeeh);

    QString year_in_temporary_file_of_show_information_then;

    long final_price_in_one_year;
    int conter_star;
    while(!read_year_in_temporary_file.atEnd())
    {
        final_price_in_one_year = 0;
        conter_star = 0;
        QString number_star;
        year_in_temporary_file_of_show_information_then = read_year_in_temporary_file.readLine();
        information_customer.open(QFile::ReadOnly | QFile::Text);
        QTextStream read_information_customer_in_file_with_year_then(& information_customer);
        while(!read_information_customer_in_file_with_year_then.atEnd())
        {
            Customer_name = read_information_customer_in_file_with_year_then.readLine();
            Customer_lastname =  read_information_customer_in_file_with_year_then.readLine();
            Customer_phone_number =  read_information_customer_in_file_with_year_then.readLine();
            year_in_file =  read_information_customer_in_file_with_year_then.readLine();
            month_in_file =  read_information_customer_in_file_with_year_then.readLine();
            day_in_file =  read_information_customer_in_file_with_year_then.readLine();
            product_name_in_file =  read_information_customer_in_file_with_year_then.readLine();
            number_product_in_file =  read_information_customer_in_file_with_year_then.readLine();
            final_price_in_file =  read_information_customer_in_file_with_year_then.readLine();

            if(year_in_file == year_in_temporary_file_of_show_information_then)
            {
                final_price_in_one_year += final_price_in_file.toLong();
            }
        }
        information_customer.close();
        while(final_price_in_one_year > 0)
        {
            final_price_in_one_year -= 10000000;
            number_star += "*";
        }
        QLabel *chart_turnover_in_one_year = new QLabel("year "+ year_in_temporary_file_of_show_information_then + " :  "+ number_star);
        layout_chart_Customer->addWidget(chart_turnover_in_one_year);
    }
    year_file.close();

    QPushButton *button_ok = new QPushButton("ok");
    layout_chart_Customer->addWidget(button_ok);
    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_show_information_of_Customer_with_chart, SLOT(close()));
    window_show_information_of_Customer_with_chart->setLayout(layout_chart_Customer);
    window_show_information_of_Customer_with_chart->show();


}






