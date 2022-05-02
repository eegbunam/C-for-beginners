#include "Coin.h"
#include <iostream>
#include <string>


int main(){

    int numberOfHeads = 0 , numberOfTails = 0 ;
    Coin coin;
    coin.toss();
    for(int i = 0; i < 50; i++){
        coin.toss();
        coin.display();
        if(coin.getSideUp() == "Heads"){
            numberOfHeads++;
        }
        else{
            numberOfTails++;
        }

    }

    cout << "Number of heads: " << numberOfHeads << endl;
    cout << "Number of tails: " << numberOfTails << endl;   
    
    return 0;
}