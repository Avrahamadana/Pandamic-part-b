#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;
class Scientist : public Player
{
    public:
    Scientist(Board b , City c ,int a);
    virtual Player &discover_cure(Color c ,int n);
    virtual Player &discover_cure(Color c )override;
    virtual string role()override;
};
