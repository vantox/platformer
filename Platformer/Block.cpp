//
//  Block.cpp
//  Platformer
//
//  Created by Piotrek Kiełek on 13/01/16.
//  Copyright © 2016 Michał Kiełek. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Block.hpp"
#include "ResourcePath.hpp"
#include "Config.hpp"

Block::Block(sf::Vector2f position) : Object(position){
    size = 100;
    setHitbox(sf::FloatRect(position.x - size/2,position.y - size/2,size,size));
    
    idleTexture  = new sf::Texture();
    if (!idleTexture->loadFromFile(resourcePath() + "block.png"))
    {
        std::cout << "Block texture not loaded";
    }
    idleSprite.push_back(new sf::Sprite());
    idleSprite[0]->setTexture(*idleTexture);
    idleSprite[0]->setTextureRect(sf::IntRect(0,0,size,size));
    
};
void Block::update(){
    
    
}

void Block::draw(sf::RenderWindow* window){
  
    idleSprite[0]->setPosition(position.x -(size / 2) , position.y -(size / 2));
    window->draw(*idleSprite[0]);
}