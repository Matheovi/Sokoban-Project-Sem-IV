#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
#include <iostream>
class Player
{
public:
    /**
     * @brief Construct a new Player object
     * 
     */
    Player();

    /**
     * @brief Moves player
     * 
     * @param ev event, contains eg. keyboard presses necessary to evaluate next move
     */
    void move(sf::Event ev);

    /**
     * @brief vector of all player positions
     * 
     * if player moves, new position is pushbacked into the vector.
     */
    std::vector<sf::Vector2f> playerPosition;

    sf::Texture playertex;    ///< Texture of a player
    sf::Sprite player_sprite; ///< Player sprite
};