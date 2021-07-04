#include "board.h"

Board::Board(std::string levelname)
{
    walltex.loadFromFile("textures/stoneBlock.png");
    grasstex.loadFromFile("textures/darkDirtBlock.png");
    warehousetex.loadFromFile("textures/purpleBlock.png");
    finishtex.loadFromFile("textures/escape.png");
    wall.setTexture(walltex);
    grass.setTexture(grasstex);
    warehouse.setTexture(warehousetex);
    finish.setTexture(finishtex);
    int tmp_val;
    std::fstream file;
    file.open(levelname);
    for (int y = 0; y < rects_in_Y_dimension; y++)
    {
        for (int x = 0; x < rects_in_X_dimension; x++)
        {
            file >> tmp_val;
            if (tmp_val == 0 || tmp_val == 1 || tmp_val == 6 || tmp_val == 7)
            {
                location[y][x] = tmp_val;
            }
            else
                location[y][x] = 0;
        }
    }
    file.close();
    location_texture.create(windowSizeX, windowSizeY);
    location_texture.clear();
    for (int y = 0; y < rects_in_Y_dimension; y++)
    {
        for (int x = 0; x < rects_in_X_dimension; x++)
        {
            switch (location[y][x])
            {
            case 0:
                grass.setPosition(x * RECTSIZE, y * RECTSIZE);
                location_texture.draw(grass);
                break;

            case 1:
                wall.setPosition(x * RECTSIZE, y * RECTSIZE);
                location_texture.draw(wall);
                break;
            case 6:
                warehouse.setPosition(x * RECTSIZE, y * RECTSIZE);
                location_texture.draw(warehouse);
                warehousepositions.push_back(sf::Vector2f(x, y));
                break;
            case 7:
                finish.setPosition(x * RECTSIZE, y * RECTSIZE);
                location_texture.draw(finish);
                finishposition.x = x;
                finishposition.y = y;
                break;
            }
        }
    }
    location_texture.display();
}

sf::Vector2f Board::getFinishPosition()
{
    return finishposition;
}