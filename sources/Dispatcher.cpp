#include "Dispatcher.hpp"
using namespace pandemic;
// Dispatcher::Dispatcher(Board b, City c) : Player(b, c){};

Player &Dispatcher::discover_cure(Color c)
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

Player &Dispatcher::fly_charter(City c)
{
    if (playerCityCards[c] > 0)
    {
        setCity(c);
        return *this;
    }
    else if (getCity() == c)
    {
        throw("Players are already in town");
    }
    else
    {
        throw("No player card");
    }
    return *this;
}

string Dispatcher::role()
{
    return "Dispatcher";
}