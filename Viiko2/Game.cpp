#include "Game.h"
#include<iostream>
#include<ctime>

using namespace std;

Game::Game() //Initialization?
{
    maxNumber = 50;
    playerGuess = 0;
    randomNumber = 0;
    numOfGuesses = 0;
    cout<<"Game constructor initialized"<<endl;
}

Game::~Game(){
    cout<<"Game Destoryed!!"<<endl;
} //Destructor.

void Game::play()
{
    srand(time(NULL));
    cout<<"Anna max numero ";
    cin>>maxNumber;
    randomNumber = rand() % maxNumber;
    while(playerGuess != randomNumber) //Game loop
    {
        cout<<"Arvaa luku 1 - "<<maxNumber<<endl;
        cin>>playerGuess;
        numOfGuesses++;

        if(playerGuess < randomNumber){
            cout<<"Liian pieni"<<endl;
        }else if(playerGuess > randomNumber){
            cout<<"Liian iso"<<endl;
        }else{
            printGameResult();
        }
    }
}

void Game::printGameResult() // Print the final results and end the game.
{
    cout<<"Arvasit oikein! Arvauksien määrä: "<<numOfGuesses<<endl;
}
