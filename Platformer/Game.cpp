//
//  Game.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#include "Game.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Block.hpp"
#include "Config.hpp"
#include <iostream>

Game::Game(){
    board = new Board();
    player = new Player(sf::Vector2f(1000,500), "Andrzej");
    block = new Block(sf::Vector2f(1000,900));
    block2 = new Block(sf::Vector2f(1200,900));
    block3 = new Block(sf::Vector2f(1400,900));
    addCollidable(block);addCollidable(block2);addCollidable(block3);
    addGravitable(player);
}

void Game::update(){
    updateGravitables();
    board->update();
    player->update();
    block->update();
    block2->update();
    block3->update();
    
}

void Game::draw(sf::RenderWindow* window){
    board->draw(window);
    block->draw(window);block2->draw(window);block3->draw(window);
    player->draw(window);
}

std::vector<Collidable*>& Game::getCollidables(){
    return collidables;
}

void Game::addCollidable(Collidable* collidable){
    collidables.push_back(collidable);
}

void Game::addGravitable(Collidable *gravitable){
    gravitables.push_back(gravitable);
}

std::vector<Collidable*>& Game::getGravitables(){
    return gravitables;
}

void Game::updateGravitables(){
    for(Collidable* gravitable : gravitables){
        gravitable->move(sf::Vector2f(0, GRAVITY));
    }
}




