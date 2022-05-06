#include <iostream>
#include <string>
#include "Player.hpp"
#include "Game.hpp"
#include "Assassin.hpp"
#include "Duke.hpp"
using namespace std;
using namespace coup;

Duke::Duke(Game& g,const string& name){
    this->name=name;
    this->balance=0;
    this->id=g.playersize;
    g.addPlayer(name);
    this->game=&g;
    this->checkstarted();
    this->fa=false;
    this->proffesion="Duke";
}

void Duke::block(Player& p){
    // if(!this->isMyturn()){
    //     throw invalid_argument("not your turn");
    // }
    this->fa=false;
    if(p.fa){
        p.balance-=2;
    }else{
        throw invalid_argument("player did not take foreign aid");
    }

    // this->game->nexturn();
}

void Duke::tax(){
    this->mustcoup();
    if(!this->isMyturn()){
        throw invalid_argument("not your turn");
    }
    this->fa=false;
    this->balance+=3;
    this->game->nexturn();
}

string Duke::role(){
    return this->proffesion;
}