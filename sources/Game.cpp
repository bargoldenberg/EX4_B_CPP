#include <iostream>
#include "Game.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace coup;

const size_t MAX_PLAYERS = 6;
const size_t MIN_PLAYERS = 2;

Game::Game(){
    this->player_list.resize(0);
    this->playersize=0;
    this->currturn=0;
    this->gamehasstarted=false;
}
vector<string> Game::players(){
    vector<string> cpy = this->player_list; 
    vector<string> player;
    for(size_t i=0;i<cpy.size();i++){
        if(cpy[i]!="dead"&&cpy[i]!="assassinated"){
            player.push_back(cpy[i]);
        }
    }
    return player;
} 

string Game::turn(){
    return this->player_list.at(this->currturn%this->playersize);
}

void Game::nexturn(){
    this->currturn = (this->currturn+1)%this->playersize;
    if(this->player_list[currturn]=="assassinated"){
        this->player_list[currturn]="dead";
    }
    while(this->player_list[currturn]=="dead"){
        this->currturn=(this->currturn+1)%this->playersize;
    }
}

void Game::removePlayer(size_t id){
    if(this->player_list[id]=="dead"){
        throw invalid_argument("already dead");
    }
    this->player_list[id]="dead";
}
void Game::assassinate(size_t id){
    if(this->player_list[id]=="assassinated"||this->player_list[id]=="dead"){
        throw invalid_argument("already dead");
    }
    this->player_list[id]="assassinated";
}
void Game::addPlayer(const string& name){
    if(this->playersize==MAX_PLAYERS){
        throw invalid_argument("game is full");
    }
    this->player_list.push_back(name);
    this->playersize++;
}

void Game::revive(size_t id,string& name){
    this->player_list[id]=name;
}

string Game::winner(){
    if(!this->gamehasstarted){
        throw invalid_argument("cant win if game hasnt begun");
    }
    int deathcount =0;
    for(size_t i=0;i<this->playersize;i++){
        if(this->player_list[i]=="dead"||this->player_list[i]=="assassinated"){
            deathcount++;
        }
    }
    if(deathcount!=playersize-1){
        throw invalid_argument("game is not over");
    }
    string winner;
    for(size_t i=0;i<this->playersize;i++){
        if(this->player_list[i]!="dead"&&this->player_list[i]!="assassinated"){
            winner = this->player_list.at(i);
            i=this->playersize;
        }
    }
    return winner;
}