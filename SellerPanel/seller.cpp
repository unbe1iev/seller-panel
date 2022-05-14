#include "seller.h"
#include "product.h"

using namespace std;

Seller::Seller(){
     prd = NULL;
     prdAmount=0;
}

Seller::Seller(int _id, string _login, string _password)
{
    id = _id;
    login = _login;
    password = _password;

    prd = NULL;
    prdAmount=0;
}

Seller::~Seller(){
    delete prd;
}

int &Seller::operator[](int index)
{
    if (index >= prdAmount) {
        cout << "Array index out of bound, exiting";
        exit(0);
    }
    return prd[index];
}

void Seller::printPrd() const
{
    for (int i = 0; i < prdAmount; i++)
        cout << prd[i] << " ";
    cout << endl;
}

void Seller::set(int _id, string _login, string _password)
{
    id = _id;
    login = _login;
    password = _password;
}

void Seller::set(string _login, string _password)
{
    login = _login;
    password = _password;
}

void Seller::set(int _id)
{
    id = _id;
}

void Seller::set(Seller _seller)
{
    id = _seller.id;
    login = _seller.login;
    password = _seller.password;
}

void Seller::setPrd(int *_prd, int prdA)
{
    prdAmount = prdA;
    if (prdA != 0) {
        prd = new int[prdA];
        for (int i = 0; i < prdA; i++)
            prd[i] = _prd[i];
    }
}

string Seller::getLogin(){
    return login;
}

string Seller::getPassword(){
    return password;
}

int Seller::getId()
{
    return id;
}

