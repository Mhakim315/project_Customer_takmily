#ifndef PRODUCT_AND_CUSTOMER_CLASS_H
#define PRODUCT_AND_CUSTOMER_CLASS_H
#include "QString"

#endif // PRODUCT_AND_CUSTOMER_CLASS_H
class products
{
protected:
    QString product_name;
    int conter_of_product = 0;
    long inventory_product;
    long price_product;
public:
    void add_information_of_product(QString, long, long);
    void show_list_products_in_warehouse();
    void show_product_by_click_in_name(QString, QString, QString);
};

class Customer : public products
{
private:
    QString Customer_name;
    QString Customer_lastname;
    QString Customer_phone_number;
    QString product_name_of_order;
    int conter_of_customer = 0;
    int year_order, month_order, day_order;
    long number_product_of_order;
    long final_price_of_record;
public:
    void add_information_of_Customer(QString, QString, QString, QString, long, int, int, int, long);
    void show_list_information_of_customer();
    long check_of_product_record_customer(QString, long);
    void Rewriting_the_product_file_after_the_product_stock_is_reduced(QString,long);

};
