#include "SplashScreen.h"


SplashScreen::SplashScreen()
{

}

void SplashScreen::show(sf::RenderWindow& renderWindow)
{
    sf::Texture texture;
    texture.loadFromFile("Resources/splash.png");
    
    sf::Sprite sprite;
    sprite.setTexture(texture);
    renderWindow.draw(sprite);
    renderWindow.display();
    
    sf::Event event;
    
    while (true)
    {
        while (renderWindow.pollEvent(event))              
        {
            switch (event.type)
            {
                case sf::Event::KeyPressed:
                    return;
                    break;

                case sf::Event::MouseButtonPressed:
                    return;
                    break;

                case sf::Event::Closed:
                    renderWindow.close();
                    break;
                        
                default:
                    break;
            }
        }
    }
        
}

SplashScreen::~SplashScreen()
{

}