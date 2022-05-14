#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <QString>
#include <QDebug>

using namespace std;

class Customer
{
    mutable int id;
    string name;
    string surname;
public:
    Customer();
    Customer(int _id);
    Customer(int _id, string _name, string _surname); //constructor initialization list
    Customer(const Customer & _customer, int _nextId); //copy constructor

    Customer &operator()(int _id, string _name, string _surname);

    void getInfo();
    int getId();
    void changeId() const; //We can change in const function/method the value ex.: id of a customer
    string getName();
    string getSurname();
};

#endif // CUSTOMER_H
