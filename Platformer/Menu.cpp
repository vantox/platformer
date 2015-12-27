//
//  Menu.cpp
//  Platformer
//
//  Created by Michał Kiełek on 27.12.2015.
//  Copyright © 2015 Michał Kiełek. All rights reserved.
//

#include "Menu.hpp"
#include "Config.hpp"
#include <iostream>
#include "ResourcePath.hpp"
Menu::Menu()
{
    toNextChange = 0;
    
    if (!font.loadFromFile(resourcePath() + "sansation.ttf"))
    {
        std::cout << "Font not loaded";
    }
    state = MenuState::newGame;
    for (int i = 3; i > -1;i-- ) {
        text[i].setFont(font);
        text[i].setCharacterSize(200);
        text[i].setColor(sf::Color::White);
    }
    text[0].setString("NEW GAME");
    text[1].setString("LOAD GAME");
    text[2].setString("OPTION");
    text[3].setString("EXIT");
    
}

void Menu::draw(sf::RenderWindow* window)
{
    window->setKeyRepeatEnabled(false);
    for (int i = 3; i > -1; i--) {
        text[i].setColor(sf::Color::White);
    }
    switch (state) {
        case MenuState::newGame:
            text[0].setColor(sf::Color::Red);
            break;
        case MenuState::loadGame:
            text[1].setColor(sf::Color::Red);
            break;
        case MenuState::option:
            text[2].setColor(sf::Color::Red);
            break;
        case MenuState::Exit:
            text[3].setColor(sf::Color::Red);
            break;
            
        default:
            break;
    }
    
    for (int i = 3; i > -1; i--) {
     window->draw(text[i]);
    }
    text[0].setPosition(437, 62);
    text[1].setPosition(387, 311);
    text[2].setPosition(601, 555);
    text[3].setPosition(762, 800);
}

void Menu::update()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
    {
        switch (state) {
            case MenuState::newGame:
                //odpal gre
               GameManager::get()->setGameState(GameState::game);
                break;
            case MenuState::loadGame:
                //wczytaj gre
                break;
            case MenuState::option:
                //pokaż opcje
                break;
            case MenuState::Exit:
                exit(0);
        }
    }
    toNextChange--;
    if (toNextChange < 0)
    {
    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            state = MenuState( (state + 1) % 4);
            toNextChange = TO_NEXT_CHANGE;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            state = MenuState( (state + 3) % 4);
            toNextChange = TO_NEXT_CHANGE;
        }
    }
}








