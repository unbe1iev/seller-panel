#include "product.h"
#include <QDebug>
#include <iostream>

void Product::set(int _id, string _name, float _price, int _amount)
{
    id = _id;
    name = _name;
    price = _price;
    amount = _amount;
}

void Product::set(string _name, float _price, int _amount)
{
    name = _name;
    price = _price;
    amount = _amount;
}

void Product::getInfo()
{
    cout << "Product id: " << id;
    cout << "Product name: " << name;
    cout << "Product price: " << price;
    cout << "Product amount: " << amount;
}

int Product::getId()
{
    return id;
}

string Product::getName()
{
    return name;
}
