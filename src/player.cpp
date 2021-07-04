#include "player.h"

void clearFloatVector(int amount, std::vector<sf::Vector2f> &vect)
{
    while (vect.size() > amount)
    {
        vect.erase(vect.begin());
    }
}

Player::Player()
{
    playertex.loadFromFile("textures/player.png");
    player_sprite.setTexture(playertex);
}

void Player::move(sf::Event ev)
{

    int temp_x = playerPosition.back().x;
    int temp_y = playerPosition.back().y;

    switch (ev.key.code)
    {
    case sf::Keyboard::Left:
        temp_x--;
        playerPosition.push_back((sf::Vector2f(temp_x, temp_y)));
        clearFloatVector(20, playerPosition);
        break;

    case sf::Keyboard::Right:
        temp_x++;
        playerPosition.push_back((sf::Vector2f(temp_x, temp_y)));
        clearFloatVector(20, playerPosition);
        break;

    case sf::Keyboard::Up:
        temp_y--;
        playerPosition.push_back((sf::Vector2f(temp_x, temp_y)));
        clearFloatVector(20, playerPosition);
        break;

    case sf::Keyboard::Down:
        temp_y++;
        playerPosition.push_back((sf::Vector2f(temp_x, temp_y)));
        clearFloatVector(20, playerPosition);
        break;

    case sf::Keyboard::Z:
        if (playerPosition.size() > 2)
        {
            playerPosition.pop_back();
        }
        break;

    default:
        break;
    }
}