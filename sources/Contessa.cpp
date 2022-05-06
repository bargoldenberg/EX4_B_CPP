#include <iostream>
#include "Assassin.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
#include <string>
using namespace std;
using namespace coup;

Contessa::Contessa(Game& g,const string& name){
    this->name = name;
    this->game=&g;
    this->checkstarted();
    this->balance=0;
    this->id=g.playersize;
    this->game->addPlayer(name);
    this->fa=false;   
    this->proffesion="Contessa"; 
}

void Contessa::block(Assassin a){
    // if(!this->isMyturn()){
    //     throw invalid_argument("not your turn");
    // }
    this->fa=false;
    // this->game->nexturn();
    if(a.lastaction!="coup"){
        throw invalid_argument("cannot block assassin");
    }
    this->game->revive(a.killed.id,a.killed.name);
}

void Contessa::block(Player& p){
    // this->game->nexturn();
    this->role();
    throw invalid_argument("captain can only block captain");
}

string Contessa::role(){
    return this->proffesion;
}