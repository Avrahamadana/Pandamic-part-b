#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Player.hpp"
#include <iostream>

using namespace  pandemic;
class OperationsExpert :  public Player
{
    public:
    OperationsExpert(Board b ,City c);
    virtual Player &discover_cure(Color c) override;
    virtual Player &build()override;
    virtual string role()override;
};
