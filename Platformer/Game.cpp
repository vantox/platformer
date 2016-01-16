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
#include <iostream>

Game::Game(){
    board = new Board();
    player = new Player(sf::Vector2f(500,750), "Andrzej");
    block = new Block(sf::Vector2f(1000,700));
    addCollidable(block);
}

void Game::update(){
    board->update();
    player->update();
    block->update();
    
}

void Game::draw(sf::RenderWindow* window){
    board->draw(window);
    player->draw(window);
    block->draw(window);
}

std::vector<Collidable*>& Game::getCollidables(){
    return collidables;
}

void Game::addCollidable(Collidable* collidable){
    collidables.push_back(collidable);
}