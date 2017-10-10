#include "Presentation.h"

using std::string;

Presentation::Presentation() : _window(sf::VideoMode(800, 600),"Cosmic Journey", sf::Style::Default)
{
    loadTextures();
	_backgroundTexture.loadFromFile("Resources/Background.png");
	_backgroundTexture.setSmooth(true);
	_backgroundSprite.setTexture(_backgroundTexture);
	drawBackground();
    
    font.loadFromFile("Resources/Font.ttf");
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
				gameObjectSprite.setOrigin(i.texture.getSize().x/2,i.texture.getSize().y/2);
                gameObjectSprite.setPosition(gameObject->getPosition().getXpos(), gameObject->getPosition().getYpos());
                
                if(gameObject->getEntityType() != EntityType::SATELLITE)
				{
					gameObjectSprite.setRotation(gameObject->getPosition().getAngle() * -0.5);
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

void Presentation::loadTextures()
{
    for(unsigned int i = 0; i != _paths.size(); i++)
	{
		ResourceManager resource{static_cast<EntityType>(i), _paths.at(i)};
		_entityTextures.push_back(resource);
	}
    
	for (auto entityTexture : _entityTextures)
	{
		sf::Texture texture;
		texture.loadFromFile(entityTexture.getResourcePath());
		texture.setSmooth(true);
		
		textureIdentifier currentTex;
		currentTex.entityType = entityTexture.getEntityID();
		currentTex.texture = texture;
		_textureslList.push_back(currentTex);
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
     font.loadFromFile("Resources/Font.ttf");
    
    string numberOfLives = std::to_string(lives-1) +" lives remaining"; 
    sf::Text sfLives(numberOfLives, font);
    sfLives.setCharacterSize(24);
    sfLives.setPosition(20, 20);
    sfLives.setColor(sf::Color::Yellow);
    
    string scoreText = "Score: " + std::to_string(score);  
    sf::Text sfScore(scoreText, font);
    sfScore.setCharacterSize(24);
    sfScore.setPosition(680, 20);
    sfScore.setColor(sf::Color::Yellow);
    
    string highscoreText = "High Score: " + std::to_string(highscore);  
    sf::Text sfHighScore(highscoreText, font);
    sfHighScore.setCharacterSize(24);
    sfHighScore.setPosition(650, 550);
    sfHighScore.setColor(sf::Color::Yellow);
    
    string enemiesLeft = "Enemies left: " + std::to_string(enemies);  
    sf::Text sfEnemiesLeft(enemiesLeft, font);
    sfEnemiesLeft.setCharacterSize(24);
    sfEnemiesLeft.setPosition(20, 550);
    sfEnemiesLeft.setColor(sf::Color::Yellow);
    
    _window.draw(sfScore);
    _window.draw(sfHighScore);
    _window.draw(sfLives);
    _window.draw(sfEnemiesLeft);
}