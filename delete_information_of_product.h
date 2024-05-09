#ifndef DELETE_INFORMATION_OF_PRODUCT_H
#define DELETE_INFORMATION_OF_PRODUCT_H

#include <QDialog>

namespace Ui {
class delete_information_of_product;
}

class delete_information_of_product : public QDialog
{
    Q_OBJECT

public:
    explicit delete_information_of_product(QWidget *parent = nullptr);
    ~delete_information_of_product();

private slots:
    void on_pushButton_clicked();

private:
    Ui::delete_information_of_product *ui;
};

#endif // DELETE_INFORMATION_OF_PRODUCT_H
