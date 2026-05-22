#include "Pankkitili.h"

Pankkitili::Pankkitili(string nimi)
{
    omistaja = nimi;
    cout<<"Pankkitili Constructor"<<endl;
}

double Pankkitili::getBalance()
{
    int s = saldo;
    return s;
}

bool Pankkitili::deposit(double amount)
{
    //Talletus tilille
    if(amount < 0)
    {
        cout<<"Deposit amount cannot be negative"<<endl;
        return false;
    }else
    {
        saldo = saldo + amount;
        cout<<omistaja<<" Deposited "<<amount<<" into the account"<<endl;
        return true;
    }
}

bool Pankkitili::withdraw(double amount)
{
    //Nosto tililtä
    if(amount < 0)
    {
        //Dont accept
        cout<<"Withdraw amount cannot be negative"<<endl;
        return false;
    }else
    {
        if((saldo - amount) <= 0){
            cout<<"You dont have the balance for that"<<endl;
            return false;
        }else{
            saldo = saldo - amount;
            cout<<omistaja<<" Withdrew "<<amount<<" from the account"<<endl;
        }
        return true;
    }
}

Luottotili::Luottotili(string omistaja, double value)
    : Pankkitili(omistaja)
{
    luottoRaja = value;
    saldo = luottoRaja;
    cout<<"Luottotili Constructor"<<endl;
}

bool Luottotili::deposit(double amount)
{
    if(amount < 0)
    {
        cout<<"Deposit amount cannot be negative"<<endl;
        return false;
    }else
    {
        if((saldo + amount) > luottoRaja)
        {
            cout<<"You are depositing too much money."<<endl;
            return false;
        }else{
            saldo = saldo + amount;
            cout<<omistaja<<" Deposited "<<amount<<" of money into Luottotili, here is your current Luottotili saldo: "<<saldo<<endl;
            return true;
        }
    }
}

bool Luottotili::withdraw(double amount)
{
    if(amount < 0)
    {
        cout<<"Withdraw amount cannot be negative"<<endl;
        return false;
    }else
    {
        if((luottoRaja - amount) <= 0){
            cout<<"You dont have the luottoraja for that"<<endl;
            return false;
        }else{
            saldo = saldo - amount;
            cout<<omistaja<<" Withdrew "<<amount<<", here is your current Luottotili saldo: "<<saldo<<endl;
            return true;
        }
    }
}
