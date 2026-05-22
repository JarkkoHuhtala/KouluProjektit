#include "Chef.h"
#include<iostream>
#include<string>
using namespace std;


Chef::Chef(string name)
{
    //Constructor
    salad = 0;
    soup = 0;
    pizza = 0;
    ChefName = name;
}

Chef::~Chef(){
    //Destructor
    cout<<"Chef Destructor!!"<<endl;
}

string Chef::getName()
{
    string s = ChefName;
    return s;
}

int Chef::makeSalad(int ingredient)
{
    cout<<"Give the amount of salad ingredients: ";
    cin>>ingredient;
    cout<<endl;

    int saladAmount = ingredient / 5;
    string answer;
    if(saladAmount < 1)
    {
        cout<<"Not enough ingredients to make salad."<<endl;
    }else{
        cout<<"Chef "<<ChefName<<" can make "<<saladAmount<<" salads. Would you like to make them? | yes or no"<<endl;
        cin>>answer;
        if(answer == "yes")
        {
            salad = saladAmount;
            cout<<"Made "<<saladAmount<<" salads."<<endl;
        }else{
            cout<<"Too bad, womp womp"<<endl;
        }
    }
    return salad;
}

int Chef::makeSoup(int ingredient)
{
    cout<<"Give the amount of soup ingredients: ";
    cin>>ingredient;
    cout<<endl;

    int soupAmount = ingredient / 3;
    string answer;
    if(soupAmount < 1)
    {
        cout<<"Not enough ingredients to make soup."<<endl;
    }else{
        cout<<"Chef "<<ChefName<<" can make "<<soupAmount<<" soups. Would you like to make them? | yes or no"<<endl;
        cin>>answer;
        if(answer == "yes")
        {
            soup = soupAmount;
            cout<<"Made "<<soupAmount<<" soups."<<endl;
        }else{
            cout<<"Too bad, womp womp"<<endl;
        }
    }
    return soup;
}





