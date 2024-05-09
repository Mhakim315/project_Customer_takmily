#ifndef SHOW_TURNOVER_H
#define SHOW_TURNOVER_H

#include <QDialog>

namespace Ui {
class show_turnover;
}

class show_turnover : public QDialog
{
    Q_OBJECT

public:
    explicit show_turnover(QWidget *parent = nullptr);
    ~show_turnover();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::show_turnover *ui;
};

#endif // SHOW_TURNOVER_H
