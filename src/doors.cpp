#include "doors.h"

Doors::Doors()
{
    doortex.loadFromFile("textures/doors.png");
    door_sprite.setTexture(doortex);
}