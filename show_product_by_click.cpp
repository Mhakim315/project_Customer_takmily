#include "show_product_by_click.h"
#include "ui_show_product_by_click.h"
#include "product_and_customer_class.h"
#include "QFile"
#include "QWidget"
#include "QLabel"
#include "QVBoxLayout"
#include "QTextStream"

show_product_by_click::show_product_by_click(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::show_product_by_click)
{
    ui->setupUi(this);
}

show_product_by_click::~show_product_by_click()
{
    delete ui;
}

void show_product_by_click::on_pushButton_clicked()
{
    QFile read_in_file("C:/Users/ModernSystem/Desktop/Qtcreator.txt");
    if(!read_in_file.open(QFile::ReadOnly | QFile::Text))
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
    QTextStream file_read_name (& read_in_file);
    QString name_with_lint_edit = ui->lineEdit->text();
    QString name_in_file, inventory, price;
    while(!file_read_name.atEnd())
    {
        name_in_file = file_read_name.readLine();
        if(file_read_name.atEnd())
            break;
        if(name_in_file == name_with_lint_edit)
        {
            inventory = file_read_name.readLine();
            price = file_read_name.readLine();
            QWidget * window_information = new QWidget();
            window_information->setWindowTitle("information product ");
            //QLabel *name = new QLabel(name_in_file);
            QLabel *name_lbl = new QLabel("product name : " + name_in_file);
            //QLabel *inventory_ = new QLabel(inventory);
            QLabel *inventory_lbl = new QLabel("inventory product : " + inventory);
            //QLabel *price_ = new QLabel(price);
            QLabel *price_lbl = new QLabel("price product : " + price);
            QLabel *fasele = new QLabel("******************************");
            QVBoxLayout *layout = new QVBoxLayout();
            layout->addWidget(name_lbl);
            //layout->addWidget(name);
            layout->addWidget(inventory_lbl);
            //layout->addWidget(inventory_);
            layout->addWidget(price_lbl);
            //layout->addWidget(price_);
            layout->addWidget(fasele);
            window_information->setLayout(layout);
            window_information->show();
            return;
        }
    }
    read_in_file.close();

    QWidget * window_show_not_found = new QWidget();
    window_show_not_found->setWindowTitle("Status of record information");
    QLabel *check = new QLabel("<b>product with name not found in the warehouse</b>");
    QVBoxLayout *layout = new QVBoxLayout();
    QPushButton *button_ok = new QPushButton("ok");
    layout->addWidget(check);
    layout->addWidget(button_ok);
    button_ok->connect(button_ok, SIGNAL(clicked(bool)), window_show_not_found, SLOT(close()));
    window_show_not_found->setLayout(layout);
    window_show_not_found->show();
    return;
}

