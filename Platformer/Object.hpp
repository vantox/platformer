//
//  Object.hpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>
#include "GameManager.hpp"
#include <vector>

enum Direction{
    Left = 0,
    Right = 1
};

class Object{
protected:
    int movementFrame;
    sf::Texture* idleTexture;
    std::vector<sf::Texture*> movementTexture;
    sf::Texture* jumpTexture;
    sf::Sprite* idleSprite;
    std::vector<sf::Sprite*> movementSprite;
    sf::Sprite* jumpSprite;
    
    bool isMoving;
    bool isJumping;
    Direction direction;
    sf::Vector2f position;
    
    
public:
    Object(sf::Vector2f position);
    
    void draw(sf::RenderWindow* window);
    
};

#endif /* Object_hpp */
