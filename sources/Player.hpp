#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Board.hpp"
#include <iostream>
#include <map>
using namespace std;
using namespace pandemic;

    class Player
    {
    protected:
        City currCity;
        Board &board;
        map<City, int> playerCityCards;
        
    public:

        City getCity()
        {
            return currCity;
        }
        void setCity(City c)
        {
            currCity = c;
        }
        Board getBoard()
        {
            return board;
        }
        Player(Board &board, City city);
        Player &take_card(City c);
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        virtual Player &build();
        virtual string role();
        Player& remove_cards();
        friend ostream &operator<<(ostream &os, Player &b);
    };

