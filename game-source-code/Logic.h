#ifndef LOGIC_H
#define LOGIC_H

#include <memory>
#include <stdlib.h>
#include <ctime> 
#include <vector>

#include "stopwatch.h"
#include "Presentation.h"
#include "Player.h"
#include "Enemy.h"
#include "PlayerBullet.h"
#include "CollisionHandler.h"
#include "GameState.h"
#include "Satellite.h"
#include "HighScoreManager.h"
#include "LaserField.h"
#include "LaserGenerator.h"
#include "EnemySpawner.h"

using std::shared_ptr;
using std::unique_ptr;
using std::make_shared;
using std::make_unique;
class Logic
{
public:
    Logic();
    ~Logic();
    void run();
    void renderEntities();
	void spawnEnemyNormal();
    void updatePlayerPosition();
	void updateEntities();
	void inputCommands();
    void drawSplashScreen();
    void drawWinnerScreen();
    void drawGameOverScreen();
    void spawnSatellites();
    void spawnLaserGenerators();
    void spawnAsteroids();
    void collisions();
    void updateScores();
    void entitiesShoot();
	void deleteDeadEntities();
    
private: 
    Presentation _presentation;
    GameState _gameState;
    const Grid _grid{800, 600};
    HighScoreManager _highScoreManager;
    shared_ptr<PlayerBullet> _playerBullet;
    shared_ptr<Player> _player;
    vector<shared_ptr<IMovingEntity>> _gameObjects;
    CollisionHandler _collisionHandler;
    EnemySpawner _enemySpawner;
    int _highScore;
    int _enemiesRemaining;
    bool _debounce = false; 
};

#endif // LOGIC_H