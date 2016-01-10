//
//  Game.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#include "Game.hpp"
#include "Board.hpp"
#include "PLayer.hpp"

Game::Game(){
    board = new Board();
    player = new Player(sf::Vector2f(500,750), "Andrzej");
}

void Game::update(){
    board->update();
    player->update();
}

void Game::draw(sf::RenderWindow* window){
    board->draw(window);
    player->draw(window);
}