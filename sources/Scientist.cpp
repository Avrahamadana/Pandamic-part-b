#include "Scientist.hpp"
using namespace pandemic;
Scientist::Scientist(Board b, City c, int a) : Player(b, c){}
Player &Scientist::discover_cure(Color c)
{
    if (board.researchStations[getCity()] != true)
    {
        throw("There is no research station where you are");
    }
    else if(playerCityCards.size()<5)
    {
        throw("Less than 5 cards");
    }
    else
    {
        board.curesDiscovered[c] = true;
    }
    return *this;
}
Player & Scientist::discover_cure(Color c ,int n)
{
    if (board.researchStations[getCity()] != true)
    {
        throw("There is no research station where you are");
    }

    int cardcount0 = 0;
    int cardcount1 = n;
    for (auto card : playerCityCards)
    {
        if (board.cityColor[card.first] == c)
        {
            cardcount0++;
        }
    }

    if (cardcount0 < 5)
    {
        throw("can not do it");
    }

    for (auto card : playerCityCards)
    {
        if (board.cityColor[card.first] == c && cardcount1 > 0)
        {
            playerCityCards.erase(card.first);
            cardcount1--;
        }
    }

    if(cardcount1 == n)
    {
        board.curesDiscovered[c] = true;
    }

    return *this;
}
string Scientist::role()
{
    return "Scientist";
}