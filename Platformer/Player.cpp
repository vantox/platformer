//
//  Player.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//
#include <iostream>
#include "Player.hpp"
#include "ResourcePath.hpp"
#include "Config.hpp"

Player::Player(sf::Vector2f position, std::string name) : Object(position){
    
    idleTexture  = new sf::Texture();
    if(!idleTexture->loadFromFile(resourcePath() + "player.png")){
        std::cout << "player texture not loaded\n";
    }
    idleSprite = new sf::Sprite();
    idleSprite->setTexture(*idleTexture);
    maxHp = PLAYER_MAX_HP;
    hp = maxHp;
};

void Player::update(){
    
}