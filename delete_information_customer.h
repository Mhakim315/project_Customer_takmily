#ifndef DELETE_INFORMATION_CUSTOMER_H
#define DELETE_INFORMATION_CUSTOMER_H

#include <QDialog>

namespace Ui {
class delete_information_Customer;
}

class delete_information_Customer : public QDialog
{
    Q_OBJECT

public:
    explicit delete_information_Customer(QWidget *parent = nullptr);
    ~delete_information_Customer();

private slots:
    void on_pushButton_clicked();

private:
    Ui::delete_information_Customer *ui;
};

#endif // DELETE_INFORMATION_CUSTOMER_H
