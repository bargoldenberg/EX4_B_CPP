#include <iostream>
#include "Player.hpp"
using namespace std;
using namespace coup;

const size_t COUP_COST = 7;
const size_t MAX_COUP = 10;
const size_t MAX_PLAYERS = 6;
const size_t MIN_PLAYERS = 2;

bool Player::isMyturn(){
    return this->id==this->game->currturn;
}

void Player::mustcoup() const{
    if(this->balance>=MAX_COUP){
        throw invalid_argument("you must coup");
    }
    this->checkgame();
    this->game->gamehasstarted=true;
}

void Player::income(){
    this->mustcoup();
    if(!this->isMyturn()){
        throw invalid_argument("not your turn");
    }
    this->activesteal=false; 
    this->fa=false;
    this->balance++;
    this->game->nexturn();
}

void Player::foreign_aid(){
    this->mustcoup();
    if(!this->isMyturn()){
        throw invalid_argument("not your turn");
    }
    this->activesteal=false; 
    this->fa=true;
    this->balance+=2;
    this->game->nexturn();
}

void Player::coup(Player& p){
    if(!this->isMyturn()){
        throw invalid_argument("not your turn");
    }
    this->activesteal=false; 
    this->fa=false;
    if(this->balance<COUP_COST){
        cout<<this->balance<<endl;
        throw invalid_argument("not enough coins");
    }
    game->removePlayer(p.id);
    this->balance-=COUP_COST;
    this->game->nexturn();
}


int Player::coins() const{
    return this->balance;
}

void Player::checkgame() const{
    if(this->game->playersize<MIN_PLAYERS||this->game->playersize>MAX_PLAYERS){
        throw invalid_argument("problem with player amount");
    }
}

void Player::checkstarted() const{
    if(this->game->gamehasstarted){
        throw invalid_argument("game has already started");
    }
}


