#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;
class Dispatcher : public Player
{
    public:
    Dispatcher(Board b , City c):Player(b,c){};
    virtual Player &discover_cure(Color c)override;
    virtual Player& fly_charter(City c)override;
    virtual string role()override;
};
