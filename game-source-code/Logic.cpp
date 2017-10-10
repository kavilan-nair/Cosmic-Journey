#include "Logic.h"

Logic::Logic() : _presentation(), _gameState(GameState::SPLASHSCREEN),  _enemySpawner(_grid),_highScore(_highScoreManager.getHighScore()),_enemiesRemaining(0)
{
    srand(time(0));
	_player = make_shared<Player>(_grid);
	_gameObjects.push_back(_player);
}

Logic::~Logic()
{
}

void Logic::run()
{	
    if (_gameState == GameState::SPLASHSCREEN)
        drawSplashScreen();
        
    _gameState=GameState::ACTIVE;
     
    StopWatch timer;
    timer.startTimer();
	auto timeFromLastUpdate = 0.f;
	auto timePerFrame = 1.0f/6000.f;

	while(_gameState == GameState::ACTIVE)
    {
        timeFromLastUpdate += timer.stopTimer();
        timer.startTimer();
    
        while(timeFromLastUpdate > timePerFrame && _gameState == GameState::ACTIVE)
        {
            inputCommands();
            spawnSatellites();
            spawnLaserGenerators();
            updatePlayerPosition();
            updateEntities();
            spawnEnemyNormal();  
            spawnAsteroids();
			entitiesShoot();         
            collisions();            
            updateScores();
            renderEntities();
            timeFromLastUpdate -= timePerFrame;
        }
    }
    
    if(_gameState==GameState::GAME_OVER)
        drawGameOverScreen();
                
    if (_gameState==GameState::GAME_WON) 
        drawWinnerScreen();
}

void Logic::inputCommands()
{
	_presentation.processInputEvents();
}

void Logic::updatePlayerPosition()
{		
	if(_presentation.getSpaceKeyPress() && !_debounce)
	{
        for (auto &playerBullet :  _player->shoot() ) _gameObjects.push_back(playerBullet);
		_debounce = true;
	}
	if(_presentation.getLeftKeyPress())
		_player->setDirection(Direction::CLOCKWISE);
	else if(_presentation.getRightKeyPress())
		_player->setDirection(Direction::ANTICLOCKWISE);
	else
		_player->setDirection(Direction::HOVER);
	if(!_presentation.getSpaceKeyPress() && _debounce)
		_debounce=false;
}

void Logic::renderEntities()
{  
    _gameObjects.erase(remove_if
    (
        _gameObjects.begin(), 
        _gameObjects.end(), 
        []( shared_ptr<IMovingEntity>& gameObject){ return (!gameObject->isAlive()); }
    ), 
    _gameObjects.end()
    );
    
	_presentation.renderWindow(_gameObjects, _player->getLives(), _player->getScore(), _highScore, _enemiesRemaining);
}

void Logic::updateEntities()
{
	for (auto &gameObject : _gameObjects)
	{
		if(gameObject->isAlive())
			gameObject->move();
	}
}

void Logic::spawnEnemyNormal()
{
    for ( auto &enemiesNormal :  _enemySpawner.spawnEnemyNormal() ) 
        _gameObjects.push_back(enemiesNormal);
      
    for ( auto &repawnEnemiesNormal :  _enemySpawner.respawnEnemyNormal(_gameObjects) )
         _gameObjects.push_back(repawnEnemiesNormal);
}

void Logic::spawnSatellites()
{
        for ( auto &satellites :  _enemySpawner.spawnEnemySatellite() ) 
            _gameObjects.push_back(satellites);
}

void Logic::collisions()
{
     _collisionHandler.checkCollisions(_gameObjects);
     
    if (_collisionHandler.isWeaponUpgradable())
        _player->upgradeWeaponDouble();
    
    _player->addScore(_collisionHandler.getPoints());
}

void Logic::updateScores()
{
    if (_player->getScore() > _highScoreManager.getHighScore())
        _highScoreManager.setHighScore(_player->getScore());
        //total enemies to kill
    _enemiesRemaining = 50 - _collisionHandler.getEnemiesKilled();
    if (_enemiesRemaining == 0)
        _gameState = GameState::GAME_WON;
        
    if(_player->isGameOver())
    {
        _gameState=GameState::GAME_OVER;
    }
}

void Logic::spawnLaserGenerators()
{
        for ( auto &laserGenerators :  _enemySpawner.spawnLaserGenerator() ) 
            _gameObjects.push_back(laserGenerators);
            
        _enemySpawner.checkLaserGenAndSat(_gameObjects);
}

void Logic::entitiesShoot()
{
	for(auto &enemyBullets : _enemySpawner.enemyShoot(_gameObjects))
        _gameObjects.push_back(enemyBullets);

}

void Logic::spawnAsteroids()
{
    for (auto &asteroid : _enemySpawner.spawnAsteroid() )
        _gameObjects.push_back(asteroid);
}

void Logic::drawSplashScreen()
{
    _presentation.displaySplashScreen();
}

void Logic::drawWinnerScreen()
{
    _presentation.displayGameWinner( _player->getScore(), _highScore);
}

void Logic::drawGameOverScreen()
{
    _presentation.displayGameOverScreen(_player->getScore(), _highScore);
}