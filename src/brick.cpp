
#include "brick.h"

Brick::Brick()
{
    bricktex.loadFromFile("textures/box.png");
    brick_sprite.setTexture(bricktex);
}
