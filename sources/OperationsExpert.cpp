#include "OperationsExpert.hpp"
using namespace  pandemic;
OperationsExpert::OperationsExpert(Board b , City c):Player(b, c){}
Player &OperationsExpert::discover_cure(Color c)
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
Player &OperationsExpert::build()
{
    if (board.researchStations[getCity()] != true)
    {
            board.researchStations[getCity()] = true;
            return *this;
    }
    return *this;
}
string OperationsExpert::role()
{
    return "OperationsExpert";
}
