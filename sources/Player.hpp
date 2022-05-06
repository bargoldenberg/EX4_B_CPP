#pragma once
#include <iostream>
#include <string>
#include "Game.hpp"
using namespace std;
namespace coup{
    class Player{
        protected:  
      
            Game* game;
            string proffesion;
        public:
            string name;
            bool isMyturn();
            bool fa;            
            void income();
            void foreign_aid();
            void coup(Player& p);
            int coins() const;
            int balance;
            bool assasssinated;
            string lastaction;
            size_t id;
            bool activesteal;
            void mustcoup() const;
            void checkgame() const;
            void checkstarted() const;
    };
}