#include <iostream>
#include "Asiakas.h"

using namespace std;

int main()
{
    Asiakas customer("cust1", 1000);
    Asiakas customer2("cust2", 2000);
    customer.luotonNosto(500);
    customer.luotonMaksu(50);
    customer.talletus(500);
    customer.nosto(50);
    customer.showSaldo();

    customer2.luotonNosto(500);
    customer2.luotonMaksu(50);
    customer2.talletus(500);
    customer2.nosto(100);
    customer.tiliSiirto(50, &customer2);
    customer2.showSaldo();
    customer2.tiliSiirto(150, &customer);
    customer.showSaldo();
    return 0;
}
