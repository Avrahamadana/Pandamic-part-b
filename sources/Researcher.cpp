#include "Researcher.hpp"
using namespace pandemic;
// Researcher::Researcher(Board b, City c) : Player(b, c){};

Player &Researcher::discover_cure(Color c)
{
    int cardcount0 = 0;
    int cardcount1 = 5;
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

    if (cardcount1 == 4)
    {
        board.curesDiscovered[c] = true;
    }

    return *this;
}
string Researcher::role()
{
    return "Researcher";
}