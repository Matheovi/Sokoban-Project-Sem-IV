#include "probe.h"

Probe::Probe(sf::Vector2f &playerPosition)
{
    position = playerPosition;
}

void Probe::move(int x, int y)
{
    position.x = position.x + x;
    position.y = position.y + y;
}