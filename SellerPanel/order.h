#ifndef ORDER_H
#define ORDER_H

#include <ctime>
#include <iostream>
#include <cstdlib>
#include <QString>
#include <QDebug>
#include <QRandomGenerator64>

#include "customer.h"
#include "product.h"
#include "delivery.h"
#include "seller.h"

using namespace std;

class Seller;

class Order{
    int id;
    string date;
    string status;
    static int lastOrderId;
    static int ordersAmount;
    static Seller *seller;

    Delivery *delivery[2];

    class Invoice{
        string number;
    public:
        void setNumber(){
            //Generate number of invoice to the order
            uniform_int_distribution<long long int> distribution(111111, 999999);

            long long int numberGen = distribution(*QRandomGenerator::global());

            QString s = QString::number(numberGen);
            number = "FV/"+s.toStdString();
        }

        friend class Order; //friendly class

        Invoice(){}
    };

    Invoice invoice;

public:
    Order();
    Order(int _id, string date, string status);
    ~Order();

    void static setLastOrderId(int _number);
    void static setOrdersAmount(int _number);
    void static deleteOne();
    void static addOne();

    void set(int _id, string _date, string _status);

    void getOrderInfo() const;

    Order &operator=(const Order &ord);

    string getStatus() const;
    string getDate() const;
    int getId() const;
    int getProductsAmount();
    void printSpecificData();

    static string getSellersLogin();
    static void allocSeller();
    static void delSeller();
};

#endif // ORDER_H
