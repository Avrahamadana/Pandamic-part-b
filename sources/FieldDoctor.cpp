#include "FieldDoctor.hpp"
using namespace pandemic;
FieldDoctor::FieldDoctor(Board b, City c) : Player(b,c){}

Player &FieldDoctor::discover_cure(Color c)
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

Player& FieldDoctor::treat(City city)
{
    bool flag = false;
    vector<City> neighborsOfCity = board.cityNi[getCity()];
    for (unsigned long i = 0; i < neighborsOfCity.size(); i++)
    {
        if (neighborsOfCity[i] == city)
        {
            flag = true;
        } 
    }
    if(board.curesDiscovered[board.cityColor[city]] == true && flag == true)
    {
        board.diseaseOfCity[city] = 0;
    }
    else if(board.diseaseOfCity[city] == 0)
    {
        throw("There is no pollution in the city");
    }
    return *this;
}
string FieldDoctor:: role()
{
    return "FieldDoctor";
}