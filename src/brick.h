#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <iostream>
class Brick
{

public:
    /**
    * @brief Construct a new Brick object
    * 
     */
    Brick();

    std::vector<sf::Vector2f> brickPositions; ///< stores positon of all bricks
    sf::Texture bricktex;                     ///< Texture of a brick
    sf::Sprite brick_sprite;                  ///< Brick sprite, it contains a brick texture
};