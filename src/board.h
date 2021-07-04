#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <iostream>
#include <array>
#include "settings.h"
#include <SFML/Graphics.hpp>

class Board
{
    sf::Texture walltex;         ///< Texture of a wall
    sf::Texture grasstex;        ///< Texture of a grass
    sf::Texture warehousetex;    ///< Texture of a warehouse
    sf::Texture finishtex;       ///< Texture of a finish
    sf::Sprite wall;             ///< Wall sprite, it contains a wall texture
    sf::Sprite grass;            ///< Grass sprite, it contains a grass texture
    sf::Sprite warehouse;        ///< Warehouse sprite, it contains a warehouse texture
    sf::Sprite finish;           ///< Finish sprite, it contains a finish texture
    sf::Vector2f finishposition; ///< Position of a finish tile. Used to check win condition.

public:
    /** 
     * Default Constructor
     */
    Board();
    /**
     * @brief Construct a new Board object
     * 
     * @param levelname name of the file, that contains a level
     */
    Board(std::string levelname);

    /**
     * @brief Get the finishposition object
     * 
     * @return sf::Vector2f returns finish position tile
     */
    sf::Vector2f getFinishPosition();

    /**
     * @brief Texture of map without movables.
     * 
     *  Texture of whole map after loading. In this way, we dont generate whole map each frame, which is a neat optimisation.
     */
    sf::RenderTexture location_texture;

    /**
     * @brief here are stored all positions, where boxes should be placed.
     * 
     */
    std::vector<sf::Vector2f> warehousepositions;

    /**
     * @brief Stored location in the form of array of array of integers.
     * 
     */
    std::array<std::array<int, rects_in_X_dimension>, rects_in_Y_dimension> location;
};
