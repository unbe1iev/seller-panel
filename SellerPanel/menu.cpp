#include "menu.h"
#include "ui_menu.h"

#include <QProcess>
#include <QDebug>

menu::menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    setWindowTitle("Seller Panel");
}

menu::~menu()
{
    delete ui;
    deregisterOrders(orders);
    Order::delSeller(); //static - seller - deleting data
}

void menu::init()
{
    seller.set(1, "admin", "password");
    int a[] = { 1, 2, 3, 4, 5 };

    seller.setPrd(a, 5);
    seller[2] = 6; // Overloading []  ... Changing product id of seller's list

    products[0].set(1, "Obraz XMD 12", 12.50, 3);
    products[1].set(2, "Myszka Zowie FK 1", 199.90, 9);
    products[2].set(3, "Wazon Milte 12M", 45.00, 7);

    Customer customer1;
    Customer customer2(2);
    Customer customer3(3, "Jan", "Bielecki");

    cout << " - Seller's data -" << endl;
    cout << seller; // Overloading <<

    cout << "Seller's list of products id: ";
    seller.printPrd(); // printing the list products ids

    cout << endl << " - Customer1's data -" << endl;
    customer1.getInfo();
    customer1.changeId();   //mutable adnot.
    cout << "Changed id to: " << customer1.getId() << endl << endl;

    cout << " - Copied Customer2's data -" << endl;
    customer2.getInfo();

    cout << " - Delegating Customer3's data -" << endl;
    customer3.getInfo();

    // ------------------------------- Overloading customer4:
    Customer customer4;
    customer4(4, "Jan", "Bielecki");
    cout << " - Customer4's data overloaded #1-" << endl; // ()
    customer4.getInfo();

    // static -seller:
    Order::allocSeller();
    cout << "static seller: " << Order::getSellersLogin() << endl;

    amount = 5;

    createOrders(orders, amount);
    registerOrders(orders);

    /*//Overloading
    cout << "Overloading..." << endl << endl;
    assignOrder(orders, 0, amount-1);
    displayOrders(orders);*/
    cout << "Init was initialized..." << endl << "========================================" << endl;

}

void menu::createOrders(vector<Order*> *&orders, const int amount)
{
    orders = new vector<Order*>(amount);
}

void menu::registerOrders(vector<Order*> *&orders)
{
    time_t rawtime;
    time (&rawtime);
    string date = ctime(&rawtime);

    int amount = orders->size();
    for (int i=0; i<amount; i++)
        orders->at(i) = new Order(i , date, "new");
}

void menu::deregisterOrders(vector<Order *> *&orders)
{
    delete orders;
    cout << "~ Orders deleted: " << endl;
}

void menu::displayOrders(vector<Order *> *&orders)
{
    int amount = orders->size();
    for (int i=0; i<amount; i++){
        orders->at(i)->getOrderInfo();
        orders->at(i)->printSpecificData();
    }
}

void menu::addOrder(vector<Order *> *&orders, Order *&order)
{
    orders->push_back(order);
}

void menu::deleteOrder(vector<Order *> *&orders)
{
    orders->pop_back();
}

void menu::assignOrder(vector<Order *> *&orders, const int fromIndex, const int toIndex)
{
    orders->at(toIndex)->operator =(*(orders->at(fromIndex))); //overloading= operator
}

string menu::genDate() {
    time_t rawtime;
    time (&rawtime);
    string date = ctime(&rawtime);

    return date;
}

void menu::setSeller(int _id, string _login, string _password) {
    seller.set(_id, _login, _password);
}

void menu::setSeller(string _login, string _password) {
    seller.set(_login, _password);
}

void menu::setSeller(int _id) {
    seller.set(_id);
}

void menu::on_displayOrders_clicked()
{
    //QProcess::execute("clear");
    cout << "-> Orders: " << endl << endl;
    displayOrders(orders);
}

void menu::on_addOrder_clicked()
{
    Order *order = new Order(0, genDate(), "new");
    addOrder(orders, order);
    cout << endl << "~ Order has been added." << endl << endl;
}

void menu::on_deleteOrder_clicked()
{
    deleteOrder(orders);
    cout << endl << "~ Order has been deleted." << endl << endl;
}

void menu::on_showProducts_clicked()
{
    cout << " - Products data -" << endl;
    for(int i=0; i<3; i++){
        cout << "Product id: " << products[i].getId() << endl;
        cout << "Product name: " << products[i].getName() << endl;
    }
    cout << "--------------" << endl;
}
