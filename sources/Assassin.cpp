#include <iostream>
#include "Assassin.hpp"
#include "Game.hpp"
#include <string>
using namespace std;
using namespace coup;

const int COUP_COST = 7;

Assassin::Assassin(Game& g,const string& name){
    this->name = name;
    this->game=&g;
    this->checkstarted();
    this->balance=0;
    this->id=g.playersize;
    this->game->addPlayer(name);
    this->fa=false;
    this->lastaction="";
    this->proffesion="Assassin";  
}
string Assassin::role(){
    return this->proffesion;
}

void Assassin::coup(const Player& p){
    if(!this->isMyturn()){
        throw invalid_argument("not your turn");
    }
    this->fa=false;
    if(this->balance<3){
        throw invalid_argument("not enough coins");
    }
    if(this->balance>COUP_COST){
       this->lastaction="";
        game->removePlayer(p.id);
        this->balance-=COUP_COST;
        this->game->nexturn(); 
    }else{
        this->lastaction="coup";
        game->assassinate(p.id);
        this->balance-=3;
        this->killed=p;
        this->game->nexturn();
    }

}
