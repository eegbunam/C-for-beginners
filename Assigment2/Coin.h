#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;

class Coin

{

    public:
        Coin();
        string sideUp;
        void toss();
        string getSideUp();
        void display();
    private:
        int tossImplemetation();
        int getRandomNumber(); // GETS RANDOM NUMBER BETWEEN 1 AND 2
        unordered_map<int, string> coinSide = { {1, "Heads"}, {2, "Tails"} }; // has track of tyep of coin flipped
};




