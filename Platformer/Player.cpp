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
#include "GameManager.hpp"
#include "Game.hpp"

Player::Player(sf::Vector2f position, std::string name) :Object(position){
    setHitbox(sf::FloatRect(position.x - 110,position.y - 225,215,470));
    jumpTime = 0;
    movementFrame = 0;
    idleFrame = 0;
    idleTexture  = new sf::Texture();
    jumpStartTexture  = new sf::Texture();
    if (!jumpStartTexture->loadFromFile(resourcePath() + "JumpStart.png"))
    {
        std::cout << "Player jumpstart texture not loaded";
    }
    if (!idleTexture->loadFromFile(resourcePath() + "Idle.png"))
    {
        std::cout << "Player texture not loaded";
    }
    movementTexture  = new sf::Texture();
    if (!movementTexture->loadFromFile(resourcePath() + "Run.png"))
    {
        std::cout << "Player texture not loaded";
    }
    
    fallingTexture  = new sf::Texture();
    fallingSprite = new sf::Sprite();
    if (!fallingTexture->loadFromFile(resourcePath() + "JumpFall.png"))
    {
        std::cout << "Player texture not loaded";
    }
    jumpTexture  = new sf::Texture();
    jumpSprite = new sf::Sprite();
    if (!jumpTexture->loadFromFile(resourcePath() + "Jump.png"))
    {
        std::cout << "Player texture not loaded";
    }
    jumpSprite->setTexture(*jumpTexture);
    jumpSprite->setTextureRect(sf::IntRect(0,0,459,525));
    fallingSprite->setTexture(*fallingTexture);
    fallingSprite->setTextureRect(sf::IntRect(0,0,631,639));
    
    
//    jumpSprite= new sf::Sprite();
//    jumpSprite->setTexture(*idleTexture);
//    jumpSprite->setTextureRect(sf::IntRect(75,19,16,27));
//    for (int i = 0; i < 13; i++) {
//        
//        if(i < 6)
//        {
//            movementSprite.push_back(new sf::Sprite());
//            movementSprite[i]->setTexture(*movementTexture);
//            movementSprite[i]->setTextureRect(sf::IntRect(540*i,0,540,579));
//        }
//        if(i < 12 && i > 5)
//        {
//            movementSprite.push_back(new sf::Sprite());
//            movementSprite[i]->setTexture(*movementTexture);
//            movementSprite[i]->setTextureRect(sf::IntRect(540*(i-6),579,540,579));
//        }
//        
//        if(i == 12)
//        {
//            movementSprite.push_back(new sf::Sprite());
//            movementSprite[i]->setTexture(*movementTexture);
//            movementSprite[i]->setTextureRect(sf::IntRect(0,1158,540,579));
//        }
//    }
    int icount = 0;
    for(int height = 0; height < 3; height++){
        for(int width = 0; (width < 6) && icount < 13; width++, icount++){
//            std::cout << icount << " " << width << " " << height << "\n";
            movementSprite.push_back(new sf::Sprite());
            movementSprite[icount]->setTexture(*movementTexture);
            movementSprite[icount]->setTextureRect(sf::IntRect(540 * width, height * 579, 540, 579));
        }
    }
    int count = 0;
    for(int height = 0; height < 2; height++){
        for(int width = 0; (width < 8) && count < 12; width++, count++){
//            std::cout << count << " " << width << " " << height << "\n";
            idleSprite.push_back(new sf::Sprite());
            idleSprite[count]->setTexture(*idleTexture);
            idleSprite[count]->setTextureRect(sf::IntRect(537 * width, height * 531, 537, 531));
        }
    }
    int scount = 0;
    for(int height = 0; height < 2; height++){
        for(int width = 0; (width < 8) && scount < 10; width++, scount++){
            jumpStartSprite.push_back(new sf::Sprite());
            jumpStartSprite[scount]->setTexture(*jumpStartTexture);
            jumpStartSprite[scount]->setTextureRect(sf::IntRect(950 * width, height * 916, 950, 916));
        }
    }
    
    

    
    
    maxHp = PLAYER_MAX_HP;
    hp = maxHp;
};

void Player::update()
{
    int y = position.y;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        move(sf::Vector2f(- PLAYER_STEP, 0));
        if(direction == Direction::Right){
            for(sf::Sprite* sprite : movementSprite){
                sprite->scale(-1.f, 1.f);
            }
            for(sf::Sprite* sprite : idleSprite){
                sprite->scale(-1.f, 1.f);
            }
               
            
        }
        direction = Direction::Left;
        isMoving = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        move(sf::Vector2f(PLAYER_STEP, 0));
        
        std::cout << " hitbox: "<< hitbox.left << " " << hitbox.top << "\n";
        if(direction == Direction::Left){
            for(sf::Sprite* sprite : movementSprite){
                sprite->scale(-1.f, 1.f);
            }
            for(sf::Sprite* sprite : idleSprite){
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
            if (jumpTime == 0 && !isFalling)
                jumpTime = 24;
            isJumping = true;
        }
        if (jumpTime > 0 && !isFalling) {
            jumpTime--;
            move(sf::Vector2f(0,-(2*PLAYER_STEP)));
        }else{
            jumpTime = 0;
            isJumping = false;
    }
    if (isJumping && jumpTime == 0) {
        isFalling = true;
        isJumping = false;
    }
        
    if (isMoving) {
//        std::cout << movementFrame;
//        std::cout << movementSprite.size();
        ++movementFrame %= movementSprite.size();
    } else {
        
        ++idleFrame %= idleSprite.size();
    }
    std::cout << "isfalling: " << isFalling << "isJumping: " << isJumping << std::endl;
}



void Player::draw(sf::RenderWindow* window){
    
//    std::cout << " position: "<< position.x << " " << position.y << "\n";
//    std::cout << " hitbox: "<< hitbox.left << " " << hitbox.top << "\n";
//
    if (isFalling) {
            fallingSprite->setPosition((sf::Vector2f(hitbox.left - 400,hitbox.top - 115)));
            window->draw(*fallingSprite);
    }else if (isJumping) {
        if (jumpTime > 14) {
            jumpStartSprite[-(jumpTime-24)]->setPosition((sf::Vector2f(hitbox.left - 315,hitbox.top - 315)));
            window->draw(*jumpStartSprite[-(jumpTime-24)]);
            
        }else
        {
            jumpSprite->setPosition((sf::Vector2f(hitbox.left - 225,hitbox.top - 45)));
            window->draw(*jumpSprite);
        }
    } else if (isMoving ) {
        //Running
        
        sf::Vector2f spritePosition;
        if(direction == Direction::Right){
            spritePosition  = sf::Vector2f(hitbox.left - 293, hitbox.top - 90);
        } else {
            spritePosition  = sf::Vector2f(hitbox.left + 508, hitbox.top - 90);
        }
        
        movementSprite[movementFrame]->setPosition(spritePosition);
        window->draw(*movementSprite[movementFrame]);
    }else {
        //Idle
        //std:: cout << "IDLE " << idleFrame << "/" <<idleSprite.size() ;
        sf::Vector2f spritePosition;
        if(direction == Direction::Right){
            spritePosition  = sf::Vector2f(hitbox.left - 250, hitbox.top - 55);
        } else {
            spritePosition  = sf::Vector2f(hitbox.left + 465, hitbox.top - 55);
        }
        
        idleSprite[idleFrame]->setPosition(spritePosition);
        window->draw(*idleSprite[idleFrame]);
        
        
    }
//    sf::RectangleShape PlayerHitbox(sf::Vector2f(215, 470));
//    PlayerHitbox.setPosition(getHitbox().left,getHitbox().top);
//    window->draw(PlayerHitbox);
    
    
    
}





