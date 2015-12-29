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
    jumpTime = 0;
    movementFrame = 0;
    idleTexture  = new sf::Texture();
    if (!idleTexture->loadFromFile(resourcePath() + "player1.png"))
    {
        std::cout << "Player texture not loaded";
    }
    idleSprite = new sf::Sprite();
    idleSprite->setTexture(*idleTexture);
//    idleSprite->setOrigin(idleSprite->getGlobalBounds().width / 2, idleSprite->getGlobalBounds().height / 2);
    idleSprite->setTextureRect(sf::IntRect(19,19,15,27));
    jumpSprite= new sf::Sprite();
    jumpSprite->setTexture(*idleTexture);
    jumpSprite->setTextureRect(sf::IntRect(75,19,16,27));
    movementSprite.push_back(jumpSprite);
    movementSprite.push_back(new sf::Sprite());
    movementSprite[1]->setTexture(*idleTexture);
    movementSprite[1]->setTextureRect(sf::IntRect(131,19,15,27));
    
    maxHp = PLAYER_MAX_HP;
    hp = maxHp;
};

void Player::update()
{
    if(position.x < 100)
        std::cout << position.x << "," << position.y << "\n";
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position.x -= 1;
        if(direction == Direction::Right){
            changedDirection = true;
            position.x += idleSprite->getGlobalBounds().width;
            idleSprite->scale(-1.f, 1.f);
            for(sf::Sprite* sprite : movementSprite){
                sprite->scale(-1.f, 1.f);
            }
               
            
        }
        direction = Direction::Left;
        isMoving = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position.x += 1;
        if(direction == Direction::Left){
            changedDirection = true;
            position.x -= idleSprite->getGlobalBounds().width;
            idleSprite->scale(-1.f, 1.f);
            for(sf::Sprite* sprite : movementSprite){
                sprite->scale(-1.f, 1.f);
            }
        }
        direction = Direction::Right;
        isMoving = true;
    }
    else {
        isMoving = false;
    }
        
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
        
        if (jumpTime == 0) {
            jumpTime = 60;
        }
    }
    if (jumpTime > 0) {
        jumpTime -= 1;
        position.y -= 1;
        isJumping = true;
    }
    if (jumpTime == 0) {
        isJumping = false;
    }
    if (isMoving) {
        ++movementFrame %= movementSprite.size();
    }
}


