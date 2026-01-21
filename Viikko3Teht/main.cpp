#include <iostream>
#include "ItalianChef.h"
#include "Chef.h"
#include<string>
using namespace std;

int main()
{
    int userInput;
    ItalianChef Chef("Mario");
    cout<<"What would you like to make?"<<endl<<"1. Salad"<<endl<<"2. Soup"<<endl<<"3. Pizza (Password protected)"<<endl;
    cin>>userInput;

    switch(userInput)
    {
    case 1:
        Chef.makeSalad(15);
        return 0;
    case 2:
        Chef.makeSoup(25);
        return 0;
    case 3:
        Chef.askSecret("SecretPassword", 35, 35);
        return 0;
    default:
        return 0;
    }
}
