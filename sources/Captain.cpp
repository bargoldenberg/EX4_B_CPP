#include <iostream>
#include "Captain.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include <string>
using namespace std;
using namespace coup;

Captain::Captain(Game& g, const string& name){
    this->name = name;
    this->game=&g;
    this->checkstarted();
    this->balance=0;
    this->id=g.playersize;
    this->game->addPlayer(name);
    this->fa=false;
    this->activesteal=false; 
    this->proffesion="Captain"; 
    this->laststole=NULL;
}

void Captain::steal(Player& p){
    this->mustcoup();
    if(!this->isMyturn()){
        throw invalid_argument("not your turn");
    }
    if(p.balance>=2){
        p.balance-=2;
        this->balance+=2;
        this->laststole=&p;
        this->activesteal=true;
        this->fa=false;
    }else if(p.balance==1){
        p.balance--;
        this->balance++;
        this->laststole=&p;
        this->activesteal=true;
        this->fa=false;
    }else{
        throw invalid_argument("no coins to steal");
    }

    this->game->nexturn();
}

string Captain::role(){
    return this->proffesion;
}

void Captain::block(Captain& c){
    if(!c.activesteal){
        throw invalid_argument("C's last action was not steal");
    }
    this->fa=false;
    this->activesteal=false; 
    c.balance-=2;
    c.laststole->balance+=2;
    c.activesteal=false;
}

void Captain::block(Player& p){
    // this->game->nexturn();
    this->role();
    throw invalid_argument("captain can only block captain");
}
