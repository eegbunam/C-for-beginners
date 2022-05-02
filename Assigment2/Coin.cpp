#include <time.h>
#include "Coin.h"

Coin::Coin()
{
    srand(time(NULL));
    this->sideUp = "Heads";
}



string Coin::getSideUp()
{
    return this->sideUp;
    
}

void Coin::toss()
{
    int number = getRandomNumber();
    this->sideUp = this->coinSide[number];
}


int Coin::getRandomNumber()
{
    int number;
    number = rand() % 2+1 ;
    return number;
}

void Coin::display()
{
    cout << "The coin is " << this->sideUp << endl;
}

