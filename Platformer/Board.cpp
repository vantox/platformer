//
//  Board.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#include "Board.hpp"
#include "ResourcePath.hpp"
#include<iostream>

Board::Board(){
    background_texture = new sf::Texture();
    if(!background_texture->loadFromFile(resourcePath()+"cute_image.jpg")){
        std::cout << "nie załadowało się";
    }
    background = new sf::Sprite();
    background->setTexture(*background_texture);
}

void Board::draw(sf::RenderWindow* window){
    //std::cout << "draw z boarda" << "\n";
    window->draw(*background);
    //background->setPosition(500, 500);

}

void Board::update(){
    
}