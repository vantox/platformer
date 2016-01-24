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
    player = new Player(sf::Vector2f(1000,700), "Andrzej");
    block = new Block(sf::Vector2f(1000,200));
    block2 = new Block(sf::Vector2f(1500,700));
    block3 = new Block(sf::Vector2f(1700,700));
    addCollidable(block);addCollidable(block2);addCollidable(block3);
}

void Game::update(){
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