#include "Player.hpp"
using namespace pandemic;
using namespace std;

Player::Player(Board &b, City c): board(b), currCity(c)
{
    setCity(c);
    for (auto &card : playerCityCards)
    {
        card.second = 0;
    }
}
Player &Player::take_card(City c)
{
    if (playerCityCards[c] < 1)
    {
        playerCityCards[c] = 1;
    }
    return *this;
}

Player &Player::drive(City c)
{
    if (getCity() != c)
    {
        setCity(c);
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
Player &Player::fly_direct(City c)
{
    if (playerCityCards[c] <= 0)
    {
        throw("There are no tickets to the destination");
    }
    else if (getCity() == c)
    {
        throw("Players are already in town");
    }
    else
    {
        playerCityCards[c] -= 1;
        setCity(c);
    }
    return *this;
}
Player &Player::fly_charter(City c)
{
    if (playerCityCards[c] > 0)
    {
        playerCityCards[c] -= 1;
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
Player &Player::fly_shuttle(City c)
{
    if (getCity() == c)
    {
        throw("Players are already in town");
    }
    else if (board.researchStations[c] != true || board.researchStations[getCity()] != true)
    {
        throw("There is no research station at the requested destination");
    }
    else
    {
        setCity(c);
    }
    return *this;
}
Player &Player::discover_cure(Color c)
{
    if (board.researchStations[getCity()] != true)
    {
        throw("There is no research station where you are");
    }

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

    if(cardcount1 == 4)
    {
        board.curesDiscovered[c] = true;
    }

    return *this;
}
Player &Player::build()
{
    if (board.researchStations[getCity()] != true)
    {
        if (playerCityCards[getCity()] > 0)
        {
            playerCityCards[getCity()] -= 1;
            board.researchStations[getCity()] = true;
            return *this;
        }
        else
        {
            throw("No player card");
        }
    }
    return *this;
}
Player &Player::treat(City c)
{
    if(board.curesDiscovered[board.cityColor[c]] == true)
    {
        board.diseaseOfCity[c] = 0;
    }
    else if(board.diseaseOfCity[c] == 0)
    {
        throw("There is no pollution in the city");
    }
    else
    {
        board.diseaseOfCity[c]--;
    }
    return *this;
}
string Player::role()
{
    return "Player";
}

Player &Player::remove_cards()
{
    for (auto &card : playerCityCards)
    {
        card.second = 0;
    }
    return *this;
}

ostream & operator<<(ostream &os, Player &b)
{
    return os;
}