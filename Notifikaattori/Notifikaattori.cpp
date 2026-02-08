#include <iostream>
#include "Seuraaja.h"
#include "Notifikaattori.h"
using namespace std;

Notifikaattori::Notifikaattori()
{
    cout<<"Notifikaattori Constructor"<<endl;
}

void Notifikaattori::lisaa(Seuraaja * s)
{
    if(seuraajat == nullptr)
    {
        seuraajat = s;
    }else
    {
        Seuraaja * current = seuraajat;
        while(current -> next != nullptr)
        {
            current = current -> next;
        }
        current -> next = s;
    }
}

void Notifikaattori::poista(Seuraaja * s)
{
    Seuraaja * current = seuraajat;
    if(seuraajat == s)
    {
        seuraajat = seuraajat -> next;
        return;
    }
    while(current -> next != nullptr)
    {
        if(current -> next == s)
        {
            current -> next = current ->next->next;
            return;
        }
        current = current -> next;
    }
}

void Notifikaattori::tulosta()
{
    Seuraaja * current = seuraajat;
    while(current != nullptr)
    {
        //current -> next -> getNimi();
        cout<<"Seuraajan nimi: "<<current -> getNimi()<<endl;
        current = current -> next;
    }
}

void Notifikaattori::postita(string s)
{
    Seuraaja * current = seuraajat;
    while(current != nullptr)
    {
        cout<<current -> getNimi()<<" Sai viestin: ";
        current -> paivitys(s);
        current = current -> next;
    }
}
