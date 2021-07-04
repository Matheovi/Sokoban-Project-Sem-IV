#include "mainmenu.h"

#define MOUSE_X ev.mouseButton.x
#define MOUSE_Y ev.mouseButton.y

MainMenu::MainMenu()
{
    playtex.loadFromFile("textures/play.png");
    exittex.loadFromFile("textures/exit.png");
    maintex.loadFromFile("textures/menu.png");
    playsprite.setTexture(playtex);
    exitsprite.setTexture(exittex);
    mainsprite.setTexture(maintex);

    playsprite.setPosition(50, 100);
    exitsprite.setPosition(50, 200);
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.clear(sf::Color(255, 255, 255));
    target.draw(mainsprite);
    target.draw(playsprite);
    target.draw(exitsprite);
}

int MainMenu::CheckClick(sf::Event &ev)
{

    if (ev.type == sf::Event::MouseButtonPressed)
    {

        if (MOUSE_X > 50 && MOUSE_X < 100)
        {
            if (MOUSE_Y > 100 && MOUSE_Y < 156)
            {
                return 1;
            }
            else if (MOUSE_Y > 200 && MOUSE_Y < 249)
            {
                return 2;
            }
        }
    }
    return 0;
}
