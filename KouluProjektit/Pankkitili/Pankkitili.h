#ifndef PANKKITILI_H
#define PANKKITILI_H
#include <string>
#include <iostream>
using namespace std;

class Pankkitili
{
public:
    Pankkitili(string);
    double getBalance();
    virtual bool deposit(double);
    virtual bool withdraw(double);
protected:
    string omistaja;
    double saldo = 0;
};

class Luottotili : public Pankkitili
{
public:
    Luottotili(string, double);
    bool deposit(double) override;
    bool withdraw(double) override;
protected:
    double luottoRaja = 0;
};

#endif // PANKKITILI_H
