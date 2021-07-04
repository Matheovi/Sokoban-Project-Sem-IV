#include "key.h"

Key::Key()
{
    keytex.loadFromFile("textures/key.png");
    key_sprite.setTexture(keytex);
}