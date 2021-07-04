/**
 * @file level.h
 * @brief Class that manages whole level environment
 * 
 * In this class we manage all things, that are seen on the screen when level is played. Board, players, doors, keys etc
 * 
 */

#pragma once
#include "brick.h"
#include "player.h"
#include "board.h"
#include "probe.h"
#include "key.h"
#include "doors.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <memory>
class Level
{
    std::unique_ptr<Board> board;
    Brick brick;
    Player player;
    Key key;
    Doors door;

public:
    /**
     * @brief Construct a new Level object
     * 
     * @param levelname name of the file, that contains a level
     */
    Level(std::string levelname);

    /**
     * @brief drawing whole level
     * 
     * @param target 
     */
    void draw(sf::RenderTarget &target);

    /**
     * @brief manages all mechanics on a level
     * 
     * This methods manages all mechanics and updates all blocks based on keyboard input
     * 
     * 
     */
    void resolve_events(sf::Event);

    /**
     * @brief function checks a tile number
     * 
     * This function checks, what tile is at given position
     * 
     * @param pos position to evaluate
     * @return int tile number: 0-grass, 1-wall, 2-brick, 3-player, 4-doors, 5-key, 6-warehouse, 7-exit
     */
    int tileCheck(sf::Vector2f &pos);

    /**
     * @name Iterators over objects in level, that help in collision and resolving events
     * @param pos position to evaluate
     * @return true if occupies given position
     * @{
     */
    bool hereIsBrick(sf::Vector2f &pos); ///< checks if there is brick at given position
    bool hereIsDoor(sf::Vector2f &pos);  ///< checks if there is door at given position
    bool hereIsKey(sf::Vector2f &pos);   ///< checks if there is key at given position
    /**@}*/

    /**
     * @name functions moving objects
     * function that moves a tile at a given position, to xy cords
     * @param pos position of interested tile
     * @param x  coordinate
     * @param y  coordinate
     * @{
     */
    void moveMarkedBrick(sf::Vector2f &pos, int x, int y);
    void moveMarkedKey(sf::Vector2f &pos, int x, int y);
    /**@}*/

    /**
     * @brief check if level is finished
     * function that checks winning conditions
     * @return true level is finished
     * @return false level is not finished
     */
    bool isLevelFinished();
};
