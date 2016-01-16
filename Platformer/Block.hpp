//
//  Block.hpp
//  Platformer
//
//  Created by Piotrek Kiełek on 13/01/16.
//  Copyright © 2016 Michał Kiełek. All rights reserved.
//

#ifndef Block_hpp
#define Block_hpp

#include <stdio.h>
#include <string>
#include "Object.hpp"
#include "Collidable.hpp"

class Block : public Object,public Collidable{
private:
    int size;
public:
    Block(sf::Vector2f position);
    void update();
    void draw(sf::RenderWindow* window);
};


#endif /* Block_hpp */
