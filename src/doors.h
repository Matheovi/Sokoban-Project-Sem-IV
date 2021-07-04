#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class Doors
{
public:
    /**
     * @brief Construct a new Doors object
     * 
     */
    Doors();

    std::vector<sf::Vector2f> doorPositions; ///< stores positon of all bricks
    sf::Texture doortex;                     ///< Texture of a door
    sf::Sprite door_sprite;                  ///< Door sprite, it contains a door texture
};