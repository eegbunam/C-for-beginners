#include <iostream>
#include "Util.h"

enum Rank {
    TWO = 2 , THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE
};

enum SUITS {
    CLUBS = 3 , DIAMONDS, HEARTS, SPADES
};


class Player{

    public:
        Player(char *name , EbukaVector<Card*> *h)
        {
            this->name = name;
            this->hand = h;
        }
        void printHand()
        {
            std::cout << name << ": ";
            for(int i = 0; i < hand->getSize(); i++)
            {
                std::cout << hand->get(i)->getRank() << " ";
            }
            std::cout << std::endl;
        }


    private:
        char *name;
        EbukaVector<Card*> *hand;

};


class Game{
    
};



class AI{

};

class Card{
    public:
        Card(Rank r, SUITS s)
        {
            rank = r;
            suit = s;
        }
        Rank getRank()
        {
            return rank;
        }
        SUITS getSuit()
        {
            return suit;
        }
        void print()
        {
            if(rank <= TEN)
                std::cout << rank;
            else if(rank == JACK)
                std::cout << "J";
            else if(rank == QUEEN)
                std::cout << "Q";
            else if(rank == KING)
                std::cout << "K";
            else 
                std::cout << "A";
            
            if(suit == CLUBS)
                std::cout << "C";
            else if(suit == DIAMONDS)
                std::cout << "D";
            else if(suit == HEARTS)
                std::cout << "H";
            else
                std::cout << "S";
            

            
        }
    private:
        Rank rank;
        SUITS suit;
};



class Deck{

    public:
        Deck()
        {
            // for(int i = 0; i < 4; i++)
            // {
            //     for(int j = 0; j < 13; j++)
            //     {
            //         cards.push_back(Card(static_cast<Rank>(j), static_cast<SUITS>(i)));
            //     }
            // }
        }
        void shuffle()
        {
            cards.randomize();
        }
        Card deal()
        {
          
            return cards.pop();
        }
        void print()
        {
            for(int i = 0; i < cards.getSize(); i++)
            {
                cards.get(i).print();
            }
        }
        ~Deck()
        {
            // for(int i = 0; i < cards.getSize(); i++)
            // {
            // //   delete cards[i];
            // }
        }   
    private:
       // std::vector<Card> cards;
       EbukaVector<Card> cards;
};



