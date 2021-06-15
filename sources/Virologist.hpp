#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;
class Virologist : public Player
{
    const int num = 5;
    public:
    Virologist(Board b , City c);
    virtual Player &treat(City c) override;
    virtual Player &discover_cure(Color c) override;
    virtual string role() override;
};
