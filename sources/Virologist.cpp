#include "Virologist.hpp"
using namespace pandemic;
Virologist::Virologist(Board b , City c): Player(b,c){}
Player &Virologist::discover_cure(Color c)
{
    if (board.researchStations[getCity()] == true)
    {
         board.curesDiscovered[c] = true;
    }
    else if(playerCityCards.size()<num)
    {
        throw("Less than 5 cards");
    }
    else
    {
        throw("There is no research station where you are");
    }
    return *this;
}
Player & Virologist::treat(City c)
{
    if(board.curesDiscovered[board.cityColor[c]] == true && getCity() == c)
    {
        board.diseaseOfCity[c] = 0;
    }
    else if(board.diseaseOfCity[c] == 0)
    {
        throw("There is no pollution in the city");
    }
    else
    {
        if(getCity()==c)
        {
            board.diseaseOfCity[c]--;
        }
    }
    return *this;
}
string Virologist::role()
{
    return "Virologist";
}