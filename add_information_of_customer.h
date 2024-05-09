#ifndef ADD_INFORMATION_OF_CUSTOMER_H
#define ADD_INFORMATION_OF_CUSTOMER_H

#include <QDialog>

namespace Ui {
class add_information_of_customer;
}

class add_information_of_customer : public QDialog
{
    Q_OBJECT

public:
    explicit add_information_of_customer(QWidget *parent = nullptr);
    ~add_information_of_customer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::add_information_of_customer *ui;
};

#endif // ADD_INFORMATION_OF_CUSTOMER_H
