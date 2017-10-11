#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "ResourceManager.h"
#include "Player.h"
#include "string.h"
#include "SplashScreen.h"
#include "GameOverScreen.h"
#include "WinnerScreen.h"

using std::vector;
using std::shared_ptr;
using std::make_shared;

class Presentation
{
public:
    Presentation();
    ~Presentation();
    void renderWindow(vector<shared_ptr<IMovingEntity>> &gameObjects, const int& lives, const int& score, const int& highScore, const int& enemies);
    void processInputEvents();
    void handlePlayerInput(const sf::Keyboard::Key key, const bool isPressed);
	void loadTextures();
	void drawBackground();
    void displaySplashScreen();
    void displayGameWinner(const int& score, const int& highScore);
    void displayGameOverScreen(const int& score, const int& highScore);
    void displayLivesRemaining(const int& lives, const int& score, const int& highscore, const int& enemies);
	
	bool getLeftKeyPress()  const {return _isLeftPressed;};
	bool getRightKeyPress() const {return _isRightPressed;};
	bool getSpaceKeyPress() const {return _isSpacePressed;};

private:
    sf::RenderWindow _window;
	sf::Texture _backgroundTexture;	
	sf::Sprite _backgroundSprite;
	sf::Font font;
	
	const int _halveSize;
	const float _spriteRotationFactor;
	
    bool _debounceKey;
	bool _isLeftPressed;  
	bool _isRightPressed;
	bool _isSpacePressed;
	
	struct textureIdentifier
	{
		sf::Texture texture;
		EntityType entityType;
	};
	
	vector<ResourceManager> _entityTextures;
	vector<textureIdentifier> _textureslList;
	vector<sf::Sprite> _allSprites;
    vector<string> _paths = {"Resources/PlayerAlt.png", 
							"Resources/Enemy.png", 
							"Resources/Satellite.png", 
							"Resources/LaserGenerator.png",
							"Resources/PlayerBullet.png",
							"Resources/EnemyBullet.png",
                            "Resources/LaserField.png",
                            "Resources/Asteroid.png"};
};

#endif // PRESENTATION_H