#pragma once
#include "Game.hpp"
#include "Player.hpp"
#include "Assassin.hpp"
using namespace std;
namespace coup{
    class Duke : public Player{  
        public:
            Duke(Game& g,const string& name);
            void block(Player& p);
            void tax();       
            string role();
    };
}
