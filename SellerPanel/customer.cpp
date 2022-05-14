//#define UNUSED(_id) (void)(_id)
#include "customer.h"
#include <QDebug>
#include <iostream>
#include <QString>


Customer::Customer() : Customer(0 , "noname", "nosurname"){}

Customer::Customer(int _id) : Customer(_id, "noname", "nosurname"){}

Customer::Customer(int _id, string _name, string _surname) : id{_id}, name{_name}, surname{_surname} {}   //constructor initialization list

Customer::Customer(const Customer & _customer, int _nextId) {  //copy constructor
    id = _nextId;
    name = _customer.name;
    surname = _customer.surname;
}

Customer &Customer::operator()(int _id, string _name, string _surname) {
    id += _id;
    name = _name;
    surname = _surname;
    return *this;
}

void Customer::getInfo()
{
    cout << "Customer id: " << id << endl;
    cout << "Customer name: " << name << endl;
    cout << "Customer surname: " << surname << endl << endl;
}

int Customer::getId()
{
    return id;
}

void Customer::changeId() const //We can change in const function/method the value ex.: id of a customer
{
    id = 1;
}

string Customer::getName()
{
    return name;
}

string Customer::getSurname()
{
    return surname;
}
