#include <iostream>
#include "Ambassador.hpp"
#include "Game.hpp"
#include <string>
#include "Captain.hpp"
using namespace std;
using namespace coup;

Ambassador::Ambassador(Game& g,const string& name){
    this->name = name;
    this->game=&g;
    this->checkstarted();
    this->balance=0;
    this->id=g.playersize;
    this->game->addPlayer(name);
    this->fa=false;   
    this->proffesion="Ambassador";
}

void Ambassador::transfer(Player& p1, Player& p2){
    this->mustcoup();
    if(!this->isMyturn()){
        throw invalid_argument("not your turn");
    }
    if(p1.balance<=0){
        throw invalid_argument("not enough money");
    }
    this->fa=false;
    --(p1.balance);
    ++(p2.balance);
    this->game->nexturn();
}

void Ambassador::block(Captain& c){
    if(!c.activesteal){
        throw invalid_argument("C's last action was not steal");
    }
    c.activesteal = false;
    this->fa=false;
    c.balance-=2;
    c.laststole->balance+=2;
    // this->game->nexturn();
}


string Ambassador::role(){
    return this->proffesion;
}