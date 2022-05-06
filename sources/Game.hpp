#pragma once
#include <iostream>
#include <vector>
using namespace std;
namespace coup{
    class Game{
        protected:
            vector<string> player_list;
        public:
            Game();
            size_t currturn;
            size_t playersize;
            vector<string> players();
            string turn();
            void nexturn();
            void addPlayer(const string& name);
            void removePlayer(size_t id);
            void assassinate(size_t id);
            void revive(size_t id,string& name);
            string winner();
            bool gamehasstarted;
    };
}