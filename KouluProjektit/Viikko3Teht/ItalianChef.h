#ifndef ITALIANCHEF_H
#define ITALIANCHEF_H
#include<iostream>
#include<string>
#include "Chef.h"
using namespace std;

class ItalianChef : public Chef
{
    public:
        ItalianChef(string name);
        ~ItalianChef();
        bool askSecret(string pass, int flour, int water);

    private:
        string password = "pizza";
        int flour;
        int water;
        int makePizza(int flour, int water);

};

#endif // ITALIANCHEF_H
