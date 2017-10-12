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

/**
* Presentation class - Uses the SFML library to display all game sprites
*/
class Presentation
{
    public:
        /**
        * @brief Default constructor. Creates Presentation object.
        */
        Presentation();
        /**
        * @brief Default destructor. Destroys Presentation object.
        */
        ~Presentation();
        /**
        * @brief Draws and displays the game sprites, and calls displayLivesRemaining function.
        * @param gameObjects is a vector of shared pointers of type IMovingEntity.
        * @param lives is of type const int containing the number of lives of the players.
        * @param score is of type const int containing the current score.
        * @param highscore is of type const int containing the highscore.
        * @param enemies is of type const int and is the number of enemies remaining to kill.
        */
        void renderWindow(vector<shared_ptr<IMovingEntity>> &gameObjects, const int& lives, const int& score, const int& highScore, const int& enemies);
        /**
        * @brief Checks whether a key is pressed or released by the user and calls handlePlayerInput.
        */
        void processInputEvents();
        /**
        * @brief Detect what key has been pressed and sets a private variable accordingly.
        * @param key is of type sf::Keyboard::Key and holds what keyboard key is pressed.
        * @param isPressed is of type const bool and indicates whether the key is pressed or released.
        */
        void handlePlayerInput(const sf::Keyboard::Key key, const bool isPressed);
        /**
        * @brief Assigns the correct texture to the sprite depending on the type of entity it is.
        */
        void loadTextures();
        /**
        * @brief Draws the background sprite for the game.
        */
        void drawBackground();
        /**
        * @brief Displays the SplashScreen to the user/
        */
        void displaySplashScreen();
        /**
        * @brief Displays the GameWinnerScreen to the user with their score and the HighScore.
        * @param score is of type const int and holds the Player score.
        * @param highScore is of type const int and holds the highscore for the game.
        */
        void displayGameWinner(const int& score, const int& highScore);
        /**
        * @brief Displays the GameOverScreen to the user with their score and the HighScore.
        * @param score is of type const int and holds the Player score.
        * @param highScore is of type const int and holds the highscore for the game.
        */
        void displayGameOverScreen(const int& score, const int& highScore);
        /**
        * @brief Draws the text onscreen to show the number of lives, current score, previous high score and number of enemies remaining.
        * @param lives is of type const int containing the number of lives of the players.
        * @param score is of type const int containing the current score.
        * @param highscore is of type const int containing the highscore.
        * @param enemies is of type const int and is the number of enemies remaining to kill.
        */
        void displayLivesRemaining(const int& lives, const int& score, const int& highscore, const int& enemies);
        /**
        * @brief Returns a bool indicating whether the left key is pressed or not.
        * @return bool with value of whether input was captured or not.
        */		
        bool getLeftKeyPress()  const {return _isLeftPressed;};
        /**
        * @brief Returns a bool indicating whether the right key is pressed or not.
        * @return bool with value of whether input was captured or not.
        */	
        bool getRightKeyPress() const {return _isRightPressed;};
        /**
        * @brief Returns a bool indicating whether the space key is pressed or not.
        * @return bool with value of whether input was captured or not.
        */	
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
        
		/**
		* TextureIdentifier struct - contains the sf::texture relating to its corresponding EntityType
		*/
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