#include "order.h"

#include <iostream>
#include <time.h>

Seller *Order::seller;

int Order::lastOrderId = 0;
int Order::ordersAmount = 0;

Order::Order(){
    time_t rawtime;
    time (&rawtime);
    date = ctime(&rawtime);

    delivery[0] = new DPDCourier;
    delivery[1] = new InpostCourier;
}

Order::Order(int _id, string _date, string _status)
{
    id = _id;
    date = _date;
    status = _status;

    delivery[0] = new DPDCourier;
    delivery[1] = new InpostCourier;
}

Order::~Order(){
    delete delivery[0];
    delete delivery[1];
}

void Order::setLastOrderId(int _number)
{
    lastOrderId = _number;
}

void Order::setOrdersAmount(int _number)
{
    ordersAmount = _number;
}

void Order::deleteOne()
{
    ordersAmount--;
    lastOrderId--;
}

void Order::addOne()
{
    ordersAmount++;
    lastOrderId++;
}

void Order::set(int _id, string _date, string _status) {
    id = _id;
    date = _date;
    status = _status;
}

void Order::getOrderInfo() const {
    cout << "Order id: " << id << endl;
    cout << "Order status: " << status << endl;
    cout << "Order date: " << date << endl;
}

Order &Order::operator=(const Order &ord)
{
    id = ord.id+4;
    date = ord.date;
    status = ord.status+ " assigned";

    return *this;
}

string Order::getStatus() const {return status;}

string Order::getDate() const {return date;}

int Order::getId() const {return id;}

void Order::printSpecificData()
{
    //Specific data about new order:

   // Delivery
    delivery[0]->setTracking();
    delivery[1]->setTracking();

    //Invoice
    invoice.setNumber();
    cout << "InvoiceNumber: " << invoice.number << endl;
    cout << "Seller's login: " << seller->getLogin() << endl << endl;
}

//menaging static Seller of orders:

string Order::getSellersLogin()
{
    return seller->getLogin();
}

void Order::allocSeller()
{
    seller = new Seller(2, "oskar", "password");
}

void Order::delSeller()
{
    delete seller;
}
