#pragma once
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"

namespace coup{
    class Assassin : public Player{
        public:
            Player killed;
            Assassin(Game& g,const string& name);
            void coup(const Player& p);
            string role();
    };
}