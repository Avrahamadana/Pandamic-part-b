#include "Medic.hpp"
using namespace pandemic;
Medic::Medic(Board b, City c) : Player(b, c) {}
Player &Medic::discover_cure(Color c)
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
Player &Medic::treat(City c)
{
    if (board.curesDiscovered[board.cityColor[c]] == true) //need to check !!!
    {
        board.diseaseOfCity[c] = 0;
    }
    else if (board.diseaseOfCity[c] == 0)
    {
        throw("There is no pollution in the city");
    }
    else
    {
        board.diseaseOfCity[c] = 0;
    }
    return *this;
}

Player &Medic::drive(City city)
{
    if (getCity() != city)
    {
        setCity(city);
        board.diseaseOfCity[city]--;
    }
    else if (board.cityNi[getCity()].empty())
    {
        throw("There is no route to the city");
    }
    else
    {
        throw("Players are already in town");
    }
    return *this;
}
Player &Medic::fly_direct(City city)
{
    if (playerCityCards[city] <= 0)
    {
        throw("There are no tickets to the destination");
    }
    else if (getCity() == city)
    {
        throw("Players are already in town");
    }
    else
    {
        playerCityCards[city] -= 1;
        setCity(city);
        board.diseaseOfCity[city]--;
    }
    return *this;
}
Player & Medic::fly_charter(City city)
{
    if (playerCityCards[city] > 0)
    {
        playerCityCards[city] -= 1;
        setCity(city);
        board.diseaseOfCity[city]--;
        return *this;
    }
    else if (getCity() == city)
    {
        throw("Players are already in town");
    }
    else
    {
        throw("No player card");
    }
    return *this;
}
Player& Medic::fly_shuttle(City city)
{
    if (getCity() == city)
    {
        throw("Players are already in town");
    }
    else if (board.researchStations[city] != true || board.researchStations[getCity()] != true)
    {
        throw("There is no research station at the requested destination");
    }
    else
    {
        setCity(city);
        board.diseaseOfCity[city]--;
    }
    return *this;
}

string Medic::role()
{
    return "Medic";
}