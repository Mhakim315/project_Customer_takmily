QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_information_of_customer.cpp \
    add_information_product.cpp \
    delete_information_customer.cpp \
    delete_information_of_product.cpp \
    increase_inventory_of_product.cpp \
    main.cpp \
    mainwindow.cpp \
    show_information_of_customer.cpp \
    show_product_by_click.cpp \
    show_turnover.cpp

HEADERS += \
    add_information_of_customer.h \
    add_information_product.h \
    delete_information_customer.h \
    delete_information_of_product.h \
    increase_inventory_of_product.h \
    mainwindow.h \
    product_and_customer_class.h \
    show_information_of_customer.h \
    show_product_by_click.h \
    show_turnover.h

FORMS += \
    add_information_of_customer.ui \
    add_information_product.ui \
    delete_information_customer.ui \
    delete_information_of_product.ui \
    increase_inventory_of_product.ui \
    mainwindow.ui \
    show_information_of_customer.ui \
    show_product_by_click.ui \
    show_turnover.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
