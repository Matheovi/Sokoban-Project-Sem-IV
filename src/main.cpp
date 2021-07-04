#include "mainmenu.h"
#include "level.h"
#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Main.hpp>

int main()
{
    int level_value = 1;
    sf::RenderWindow window(sf::VideoMode(640, 480), "Game");
    MainMenu menu;
    sf::Texture congratstex;
    sf::Text leveltext;
    leveltext.setColor(sf::Color::Cyan);
    leveltext.setCharacterSize(50);
    leveltext.setPosition(300, 220);
    leveltext.setString("Level 1");
    congratstex.loadFromFile("textures/congratulations.jpg");
    sf::Sprite congratulations;
    congratulations.setTexture(congratstex);
    window.setKeyRepeatEnabled(false);
    enum class GameState
    {
        MenuState,
        LevelState,
        FinishState,
    };
    std::unique_ptr<Level> level;
    GameState current_game_state = GameState::MenuState;
    sf::Event ev;
    while (window.isOpen())
    {

        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::KeyPressed:
                if (current_game_state == GameState::LevelState)
                    level->resolve_events(ev);
                if (ev.key.code == sf::Keyboard::R)
                {
                    level.reset(new Level("levels/level" + std::to_string(level_value) + ".dat"));
                }
                if (level->isLevelFinished())
                {
                    std::cerr << '[' << __BASE_FILE__ << ':' << __LINE__ << " (" << __FUNCTION__ << ")] "
                              << "checking was succesfull" << '\n';
                    current_game_state = GameState::FinishState;
                }
                break;
            }
        }
        window.clear();
        if (current_game_state == GameState::MenuState)
        {
            if (menu.CheckClick(ev) == 1)
            {
                level = std::make_unique<Level>("levels/level" + std::to_string(level_value) + ".dat");
                current_game_state = GameState::LevelState;
            }
            else if (menu.CheckClick(ev) == 2)
            {
                window.close();
            }
            window.draw(menu);
        }

        else if (current_game_state == GameState::LevelState)
        {
            level->draw(window);
        }
        else if (current_game_state == GameState::FinishState)
        {
            window.clear();
            window.draw(congratulations);
            window.display();
            sf::sleep(sf::seconds(3));
            level.reset();
            level_value++;
            window.setTitle("leLevel " + level_value);
            level = std::make_unique<Level>("levels/level" + std::to_string(level_value) + ".dat");
            current_game_state = GameState::LevelState;
        }
        window.display();
    }
}
