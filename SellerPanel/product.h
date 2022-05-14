#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

using namespace std;

class Product
{
    int id;
    string name;
    float price;
    int amount;
public:
    Product() = default; //default constructor

    void set(int _id, string _name, float _price, int _amount);
    void set(string _name, float _price, int _amount);
    void getInfo();
    int getId();
    string getName();
};

#endif // PRODUCT_H
