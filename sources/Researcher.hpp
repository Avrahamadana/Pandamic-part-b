#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
using namespace pandemic;
class Researcher : public Player
{
public:
    Researcher(Board b, City c):Player(b,c){};
    virtual Player &discover_cure(Color c) override;
    virtual string role() override;
};
