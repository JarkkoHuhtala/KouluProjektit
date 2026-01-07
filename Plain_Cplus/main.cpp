#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int randNum = 0;
int userInput = 0;
int guesses = 0;
bool randFlag = false;
bool startFlag = true;

int game(int maxNum)
{
    if(randFlag != true)
    {
        srand (time(NULL));
        randNum = rand() % maxNum;
        randFlag = true;
    }

    cout<<"Guess the number\n";
    cin>>userInput;

    if(userInput > randNum)
    {
        cout<<"Guess was too high\n";
        guesses++;
        return guesses;
    }else if(userInput < randNum)
    {
        cout<<"Guess was too low\n";
        guesses++;
        return guesses;
    }else if(userInput == randNum)
    {
        cout<<"You got it, the number was ";
        guesses++;
        startFlag = false;
        return guesses;
    }

}

int main()
{
    while(startFlag != false)
    {
        int guesses2 = 0;
        guesses2 = game(100);
        cout<<"Guesses "<<guesses2<<"\n";
    }
}
