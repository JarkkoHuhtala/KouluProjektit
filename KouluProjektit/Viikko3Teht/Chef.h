#ifndef CHEF_H
#define CHEF_H
#import <iostream>
#include<string>
using namespace std;

class Chef
{
    public:
        Chef(string name);
        ~Chef();

        int salad;
        int soup;
        int pizza;

        string getName();
        int makeSalad(int ingredient);
        int makeSoup(int ingredient);
    protected:
        string ChefName;
};

#endif // CHEF_H
