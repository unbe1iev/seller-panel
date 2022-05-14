#ifndef SELLER_H
#define SELLER_H

#include "order.h"
#include "product.h"

#include <string>

using namespace std;

class Seller{
    int id;
    string login;
    string password;
    int* prd;
    int prdAmount;
public:

    Seller();
    Seller(int _id, string _login, string _password);
    ~Seller();

    int& operator[](int index);

    friend ostream& operator<<(std::ostream& out, const Seller& sel){
        out << "Id: " << sel.id << endl
            << "Login: " << sel.login << endl;
        return out;
    }

    void printPrd() const;

    void set(int _id, string _login, string _password);
    void set(string _login, string _password);
    void set(int _id);
    void set(Seller _seller);
    void setPrd(int *prd, int prdA);
    void setOrdersAmount(int _ordersAmount);
    void setOrders();

    int getId();
    string getLogin();
    string getPassword();
    int getOrdersAmount();
};

#endif // SELLER_H
