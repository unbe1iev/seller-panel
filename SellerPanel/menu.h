#ifndef MENU_H
#define MENU_H

#include <QMainWindow>

#include "seller.h"
#include "order.h"
#include "product.h"
#include "customer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class menu; }
QT_END_NAMESPACE

class menu : public QMainWindow
{
    Q_OBJECT

public:
    menu(QWidget *parent = nullptr);
    ~menu();

    void init();
    string genDate();

    void setSeller(int _id, string _login, string _password);
    void setSeller(string _login, string _password);
    void setSeller(int _id);

    // -------------------- Double Pointer methods --------------------
    void createOrders(vector<Order*> *&orders, const int amount);
    void registerOrders(vector<Order*> *&orders);
    void deregisterOrders(vector<Order*> *&orders);
    void displayOrders(vector<Order*> *&orders);
    void addOrder(vector<Order*> *&orders, Order *&order);
    void deleteOrder(vector<Order*> *&orders);

    void assignOrder(vector<Order*> *&orders, const int fromIndex, const int toIndex);

private slots:
    void on_displayOrders_clicked();

    void on_addOrder_clicked();

    void on_deleteOrder_clicked();

    void on_showProducts_clicked();

private:
    Ui::menu *ui;
    Seller seller;
    Product products[3];
    vector<Order*> *orders;
    int amount;
};
#endif // MENU_H
