#include "level.h"

Level::Level(std::string levelname)
{
    //  board = new Board(levelname);
    board = std::make_unique<Board>(levelname);

    int tmp_val;
    std::fstream file;
    file.open(levelname);
    for (int y = 0; y < rects_in_Y_dimension; y++)
    {
        for (int x = 0; x < rects_in_X_dimension; x++)
        {
            file >> tmp_val;
            switch (tmp_val)
            {
            case 2:
                brick.brickPositions.push_back(sf::Vector2f(x, y));
                break;
            case 3:
                player.playerPosition.push_back(sf::Vector2f(x, y));
                break;
            case 4:
                door.doorPositions.push_back(sf::Vector2f(x, y));
                break;
            case 5:
                key.keyPositions.push_back(sf::Vector2f(x, y));
                break;

            default:
                break;
            }
        }
    }
    std::cerr << '[' << __BASE_FILE__ << ':' << __LINE__ << " (" << __FUNCTION__ << ")] "
              << "level constructor" << '\n';
}

void Level::draw(sf::RenderTarget &target)
{
    target.clear();
    sf::Sprite location(board->location_texture.getTexture());
    target.draw(location);

    for (auto item : brick.brickPositions)
    {
        brick.brick_sprite.setPosition(sf::Vector2f(item.x * RECTSIZE, item.y * RECTSIZE));
        target.draw(brick.brick_sprite);
    }
    player.player_sprite.setPosition(player.playerPosition.back().x * RECTSIZE, player.playerPosition.back().y * RECTSIZE);
    target.draw(player.player_sprite);

    for (auto item : door.doorPositions)
    {
        door.door_sprite.setPosition(sf::Vector2f(item.x * RECTSIZE, item.y * RECTSIZE));
        target.draw(door.door_sprite);
    }

    for (auto item : key.keyPositions)
    {
        key.key_sprite.setPosition(sf::Vector2f(item.x * RECTSIZE, item.y * RECTSIZE));
        target.draw(key.key_sprite);
    }
}

void Level::resolve_events(sf::Event ev)
{

    int diff_x = 0;
    int diff_y = 0;

    Probe tmp_probe(player.playerPosition.back());

    if (ev.type == sf::Event::KeyPressed)
    {
        switch (ev.key.code)
        {
        //left arrow
        case sf::Keyboard::Left:
            diff_x = -1;
            break;

        // up arrow
        case sf::Keyboard::Up:
            diff_y = -1;
            break;

        // right arrow
        case sf::Keyboard::Right:
            diff_x = 1;
            break;

        // down arrow
        case sf::Keyboard::Down:
            diff_y = 1;
            break;

        default:
            break;
        }
    }
    //0-grass, 1-wall, 2-brick, 3-player, 4-doors, 5-key
    tmp_probe.move(diff_x, diff_y);
    if (tileCheck(tmp_probe.position) == 1 || tileCheck(tmp_probe.position) == 4)
        return;
    else if (tileCheck(tmp_probe.position) == 2) //logic for brick
    {
        tmp_probe.move(diff_x, diff_y);
        if (tileCheck(tmp_probe.position) != 0)
            return;
        else
        {
            tmp_probe.move(-diff_x, -diff_y);
            moveMarkedBrick(tmp_probe.position, diff_x, diff_y);
        }
    }
    else if (tileCheck(tmp_probe.position) == 5) //logic for key
    {
        tmp_probe.move(diff_x, diff_y);
        if (tileCheck(tmp_probe.position) == 1 || tileCheck(tmp_probe.position) == 2 || tileCheck(tmp_probe.position) == 5)
            return;
        else
        {
            if (tileCheck(tmp_probe.position) == 4)
            {
                int counter = 0;
                for (auto item : door.doorPositions)
                {
                    if (item == tmp_probe.position)
                    {
                        door.doorPositions.erase(door.doorPositions.begin() + counter);
                    }
                    counter++;
                }
                counter = 0;
                tmp_probe.move(-diff_x, -diff_y);
                for (auto item : key.keyPositions)
                {
                    if (item == tmp_probe.position)
                    {
                        key.keyPositions.erase(key.keyPositions.begin() + counter);
                    }
                    counter++;
                }
            }
            else
            {
                tmp_probe.move(-diff_x, -diff_y);
                moveMarkedKey(tmp_probe.position, diff_x, diff_y);
            }
        }
    }

    player.move(ev); ///or not move, depends on the above

    ///resolve block collisions?
}

int Level::tileCheck(sf::Vector2f &pos)
{
    int tmp_x = pos.x;
    int tmp_y = pos.y;

    if (hereIsBrick(pos))
        return 2;
    else if (hereIsKey(pos))
        return 5;
    else if (hereIsDoor(pos))
        return 4;
    else if (board->location[tmp_y][tmp_x] == 1)
        return 1;
    else
        return 0;
}

bool Level::hereIsBrick(sf::Vector2f &pos)
{
    for (auto item : brick.brickPositions)
    {
        if (item.x == pos.x && item.y == pos.y)
            return true;
    }
    return false;
}

bool Level::hereIsDoor(sf::Vector2f &pos)
{
    for (auto item : door.doorPositions)
    {
        if (item.x == pos.x && item.y == pos.y)
            return true;
    }
    return false;
}

bool Level::hereIsKey(sf::Vector2f &pos)
{
    for (auto item : key.keyPositions)
    {
        if (item.x == pos.x && item.y == pos.y)
            return true;
    }
    return false;
}

void Level::moveMarkedBrick(sf::Vector2f &pos, int x, int y)
{
    for (int i = 0; i < brick.brickPositions.size(); i++)
    {
        if (brick.brickPositions[i] == pos)
        {
            brick.brickPositions[i].x = brick.brickPositions[i].x + x;
            brick.brickPositions[i].y = brick.brickPositions[i].y + y;
        }
    }
}

void Level::moveMarkedKey(sf::Vector2f &pos, int x, int y)
{
    for (int i = 0; i < key.keyPositions.size(); i++)
    {
        if (key.keyPositions[i] == pos)
        {
            key.keyPositions[i].x = key.keyPositions[i].x + x;
            key.keyPositions[i].y = key.keyPositions[i].y + y;
        }
    }
}

bool Level::isLevelFinished()
{
    if (player.playerPosition.back() == board->getFinishPosition())
    {
        for (auto item : board->warehousepositions)
        {
            if (!hereIsBrick(item))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}