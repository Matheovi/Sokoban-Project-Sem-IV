#pragma once

#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>
class MainMenu : public sf::Drawable
{
    sf::Texture playtex;   ///< Play button texture
    sf::Texture exittex;   ///< Exit button texture
    sf::Texture maintex;   ///< Main button texture
    sf::Sprite playsprite; ///< Play button
    sf::Sprite exitsprite; ///< Exit button
    sf::Sprite mainsprite; ///< Background image sprite

    /**
     * @brief draw mainmenu to the screen
     */
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    MainMenu();

    /**
     * @brief function checking what was clicked
     * 
     * @param ev events to evaluate
     * @note we are only interested in mouse clicks events
     * @return int what was clicked
     */
    int CheckClick(sf::Event &ev);
};