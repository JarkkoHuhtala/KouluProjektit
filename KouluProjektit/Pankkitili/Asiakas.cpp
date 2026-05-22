#include "Asiakas.h"
#include "Pankkitili.h"
#include <iostream>

Asiakas::Asiakas(string name, double value)
{
    nimi = name;
    käyttötili = new Pankkitili(nimi);
    LuottoTili = new Luottotili(nimi, value);
    cout<<"Made a customer named: "<<nimi<<", with a Luottoraja of: "<<value<<endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    //Show both accounts balance
    cout<<nimi<<", Kayttotili Saldo = "<<käyttötili->getBalance()<<endl;
    cout<<nimi<<", Luottotilin Saldo = "<<LuottoTili->getBalance()<<endl;
    cout<<endl;
}

bool Asiakas::talletus(double value)
{
    return käyttötili -> deposit(value);
}

bool Asiakas::nosto(double value)
{
    return käyttötili -> withdraw(value);
}

bool Asiakas::luotonMaksu(double value)
{
    return LuottoTili -> deposit(value);
}

bool Asiakas::luotonNosto(double value)
{
    return LuottoTili -> withdraw(value);
}

bool Asiakas::tiliSiirto(double value, Asiakas* ptr)
{
    nosto(value);
    ptr->talletus(value);

    return 0;
}
