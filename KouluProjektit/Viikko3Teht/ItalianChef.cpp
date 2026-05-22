#include "ItalianChef.h"
#include<iostream>
#include<string>
using namespace std;

string name;

ItalianChef::ItalianChef(string name)
    : Chef(name)
{
    flour = 0;
    water = 0;
    ChefName = name;
}

ItalianChef::~ItalianChef(){
    cout<<"Destructor!!!"<<endl;
}

bool ItalianChef::askSecret(string pass, int flour, int water)
{
    cout<<"Give the password to make pizza: "<<endl;
    cin>>pass;

    if(pass == password){
        //Pass right
        cout<<"Password is right!"<<endl;
        /*cout<<"Input how much flour you have: "<<endl;
        cin>>flour;
        cout<<"Input how much water you have: "<<endl;
        cin>>water;*/
        name = getName();
        makePizza(flour, water);
        return true;
    }else{
        //Pass wrong
        cout<<"Password is wrong!"<<endl;
        return false;
    }
}

int ItalianChef::makePizza(int flour, int water)
{
    string answer;
    cout<<"Give the amount of flour: ";
    cin>>flour;
    cout<<"And water: ";
    cin>>water;
    cout<<endl;

    int pizzaAmount = flour / 5;
    int pizzaAmount2 = water / 5;
    if(pizzaAmount < pizzaAmount2){
        cout<<"ItalianChef "<<name<<" can make "<<pizzaAmount<<" pizzas with your ingredients."<<endl;
        cout<<"Would you want to make "<<pizzaAmount<<" pizzas? | yes or no"<<endl;
        cin>>answer;
        if(answer == "yes")
        {
            pizza = pizzaAmount;
            cout<<"Made "<<pizzaAmount<<" pizzas"<<endl;
        }else{
            cout<<"Too bad, womp womp"<<endl;
        }
    }else{
        cout<<"ItalianChef "<<name<<" can make "<<pizzaAmount2<<" pizzas with your ingredients."<<endl;
        cout<<"Would you want to make "<<pizzaAmount2<<" pizzas? | yes or no"<<endl;
        cin>>answer;
        if(answer == "yes")
        {
            pizza = pizzaAmount2;
            cout<<"Made "<<pizzaAmount2<<" pizzas"<<endl;
        }else{
            cout<<"Too bad, womp womp"<<endl;
        }
    }
    return pizza;
}
