#include "GeneSplicer.hpp"
using namespace pandemic;
Player &GeneSplicer::discover_cure(Color c)
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

string GeneSplicer::role()
{
    return "GeneSplicer";
}