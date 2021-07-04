#pragma once

#include <SFML/Graphics.hpp>

/**
 * Sophisticated class, on which collision is based.
 * 
 */
class Probe
{
public:
    /**
     * @brief Construct a new Probe object
     * @param pos position of new probe
     */
    Probe(sf::Vector2f &pos);

    sf::Vector2f position;

        void move(int x, int y);
};