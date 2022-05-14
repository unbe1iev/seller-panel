#ifndef DELIVERY_H
#define DELIVERY_H

#include <QString>
#include <string>
#include <iostream>
#include <QRandomGenerator64>

using namespace std;

///////------------------------------------------------------------------------------------------------------------------
class Tracking{
public:
   string number;
   void setNumber(){
       //Generate tracking number to the order from generator library:
       uniform_int_distribution<long long int> distribution(111111111111, 999999999999);

       long long int numberGen = distribution(*QRandomGenerator::global());

       QString s = QString::number(numberGen);
       number = s.toStdString();
   }
   Tracking(){}
};

class DPDTracking : public Tracking{
public:
   DPDTracking(){}
};

class InpostTracking : public Tracking{
public:
   InpostTracking(){}
};

//------------------------------------------------------------

class Delivery{
public:
   friend class Order;
   virtual void setTracking() = 0;
   Delivery(){}
   virtual ~Delivery(){}
};

class DPDCourier : public Delivery{
    DPDTracking *tracking;
public :
    DPDCourier() : Delivery(){}
    ~DPDCourier(){}
    virtual void setTracking(){
       tracking = new DPDTracking;
       tracking->setNumber();
       cout << "DPD (packages up to 48h)/";
       cout << "New TrackingNumber: " << tracking->number << endl;
   }
};

class InpostCourier : public DPDCourier{
InpostTracking *tracking;
public :
   InpostCourier() : DPDCourier(){}
   ~InpostCourier(){}
   virtual void setTracking(){
       tracking = new InpostTracking;
       tracking->setNumber();
       cout << "Inpost (packages up to 24h)/";
       cout << "New TrackingNumber: " << tracking->number << endl;
   }
};

///////------------------------------------------------------------------------------------------------------------------

#endif // DELIVERY_H
