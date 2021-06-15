#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;
class Medic : public Player
{
public:
    Medic(Board b, City c);
    virtual Player &treat(City c) override;
    virtual string role() override;
    virtual Player &drive(City city) override;
    virtual Player &fly_direct(City city) override;
    virtual Player &fly_charter(City city) override;
    virtual Player &fly_shuttle(City city) override;
    virtual Player &discover_cure(Color c) override;
};