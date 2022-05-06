#pragma once
#include <iostream>
#include "Game.hpp"
#include "Player.hpp"
#include "Captain.hpp"
#include <string>
namespace coup{
    class Ambassador : public Player{
        public:
            Ambassador(Game& g,const string& name);
            void transfer(Player& p1,Player& p2);
            void block(Captain& c);
            string role();
    };
}