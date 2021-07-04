#pragma once

#include "brick.h"
#include <SFML/Graphics.hpp>
#include <iostream>

class Key : public Brick
{

public:
    /**
     * @brief Construct a new Key object
     * 
     */
    Key();

    std::vector<sf::Vector2f> keyPositions; ///< stores positon of all keys
    sf::Texture keytex;                     ///< Texture of a key
    sf::Sprite key_sprite;                  ///< Key sprite, it contains a key texture
};