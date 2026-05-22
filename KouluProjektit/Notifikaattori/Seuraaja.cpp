#include <iostream>
#include "Seuraaja.h"
using namespace std;

Seuraaja::Seuraaja(string s)
{
    nimi = s;
    cout<<"Seuraaja Constructor"<<endl;
}

string Seuraaja::getNimi()
{
    return nimi;
}

void Seuraaja::paivitys(string s)
{
    cout<<s<<endl;
}
