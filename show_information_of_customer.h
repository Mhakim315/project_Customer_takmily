#ifndef SHOW_INFORMATION_OF_CUSTOMER_H
#define SHOW_INFORMATION_OF_CUSTOMER_H

#include <QDialog>

namespace Ui {
class show_information_of_customer;
}

class show_information_of_customer : public QDialog
{
    Q_OBJECT

public:
    explicit show_information_of_customer(QWidget *parent = nullptr);
    ~show_information_of_customer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::show_information_of_customer *ui;
};

#endif // SHOW_INFORMATION_OF_CUSTOMER_H
