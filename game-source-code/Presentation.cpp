#include "Presentation.h"

using std::string;

Presentation::Presentation() 
    : _window(sf::VideoMode(800, 600),"Cosmic Journey", sf::Style::Default),
    _halveSize(2),
    _spriteRotationFactor(-0.5),
    _debounceKey(false),
    _isLeftPressed(false),  
    _isRightPressed(false),
    _isSpacePressed(false)
{
}

void Presentation::drawBackground()
{
    _window.draw(_backgroundSprite);
}

Presentation::~Presentation()
{
}

void Presentation::renderWindow(vector<shared_ptr<IMovingEntity>> &gameObjects, const int& lives, const int& score, const int& highScore, const int& enemies)
{    
    _window.clear();
     _window.draw(_backgroundSprite);
     displayLivesRemaining(lives, score, highScore, enemies);
     
     
    for (auto const &gameObject : gameObjects)
    {
        for (auto const &i : _textureslList)
        {
            if (i.entityType == gameObject->getEntityType())
            {
                sf::Sprite gameObjectSprite;
                gameObjectSprite.setTexture(i.texture);
                gameObjectSprite.setOrigin(i.texture.getSize().x/_halveSize,i.texture.getSize().y/_halveSize);
                gameObjectSprite.setPosition(gameObject->getPosition().getXpos(), gameObject->getPosition().getYpos());
                
                if(gameObject->getEntityType() != EntityType::SATELLITE)
                {
                    gameObjectSprite.setRotation(gameObject->getPosition().getAngle() * _spriteRotationFactor);
                }
                _window.draw(gameObjectSprite);
            }
        }
    }    
    _window.display();
}

void Presentation::processInputEvents()
{
    sf::Event event;
    while (_window.pollEvent(event))
    {
        switch (event.type)
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
               handlePlayerInput(event.key.code, false);
                break;
            
            case sf::Event::Closed:
                _window.close();
                break;
                
            default:
                break;
        }
    }
}

void Presentation::handlePlayerInput(const sf::Keyboard::Key key, const bool isPressed)
{
    if ((key == sf::Keyboard::Right))
        _isRightPressed = isPressed;
    else if ((key == sf::Keyboard::Left))
        _isLeftPressed = isPressed;
        
    if (key == sf::Keyboard::Space && isPressed == true)
         if(_debounceKey == false)
         {
            _isSpacePressed = true;
            _debounceKey = true;;
         }
    if (key == sf::Keyboard::Space && isPressed == false)
        _isSpacePressed = false;
        _debounceKey = false;
}

void Presentation::loadTextures(vector<ResourceManager> resources)
{
    for(auto resource : resources)
    {
        if (resource.getResourceType() == ResourceType::BACKGROUND)
        {
            _backgroundTexture.loadFromFile(resource.getResourcePath());
            _backgroundTexture.setSmooth(true);
            _backgroundSprite.setTexture(_backgroundTexture);
            drawBackground();
        }
        else if (resource.getResourceType() == ResourceType::FONT)
        {
            _font.loadFromFile(resource.getResourcePath());
        }
        else
        {
            sf::Texture texture;
            texture.loadFromFile(resource.getResourcePath());
            texture.setSmooth(true);
            int entityTypeInt = static_cast<int>(resource.getResourceType());

            textureIdentifier currentTex;
            currentTex.entityType = static_cast<EntityType>(entityTypeInt);
            currentTex.texture = texture;
            _textureslList.push_back(currentTex);
        }
    }
}

void Presentation::displaySplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.show(_window);
}


void Presentation::displayGameOverScreen(const int& score, const int& highScore)
{
    GameOverScreen gameOverScreen;
    gameOverScreen.show(_window, score, highScore);
}

void Presentation::displayGameWinner(const int& score, const int& highScore)
{
    WinnerScreen gameWinnerScreen{};
    gameWinnerScreen.show(_window, score, highScore);
}

void Presentation::displayLivesRemaining(const int& lives, const int& score, const int& highscore, const int& enemies)
{  
     _font.loadFromFile("Resources/Font.ttf");
    
    string numberOfLives = std::to_string(lives-1) +" lives remaining"; 
    sf::Text sfLives(numberOfLives, _font);
    sfLives.setCharacterSize(24);
    sfLives.setPosition(20, 20);
    sfLives.setColor(sf::Color::Yellow);
    
    string scoreText = "Score: " + std::to_string(score);  
    sf::Text sfScore(scoreText, _font);
    sfScore.setCharacterSize(24);
    sfScore.setPosition(680, 20);
    sfScore.setColor(sf::Color::Yellow);
    
    string highscoreText = "High Score: " + std::to_string(highscore);  
    sf::Text sfHighScore(highscoreText, _font);
    sfHighScore.setCharacterSize(24);
    sfHighScore.setPosition(650, 550);
    sfHighScore.setColor(sf::Color::Yellow);
    
    string enemiesLeft = "Enemies left: " + std::to_string(enemies);  
    sf::Text sfEnemiesLeft(enemiesLeft, _font);
    sfEnemiesLeft.setCharacterSize(24);
    sfEnemiesLeft.setPosition(20, 550);
    sfEnemiesLeft.setColor(sf::Color::Yellow);
    
    _window.draw(sfScore);
    _window.draw(sfHighScore);
    _window.draw(sfLives);
    _window.draw(sfEnemiesLeft);
}