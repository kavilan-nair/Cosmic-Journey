#include "HighScoreManager.h"

HighScoreManager::HighScoreManager() : _filePath("Resources/Highscore.txt")
{
}

HighScoreManager::~HighScoreManager()
{
}

int HighScoreManager::getHighScore()
{
    _file.open(_filePath, ios::in);
    _file >> _highScore;
    _file.close();    
    return _highScore;
}

void HighScoreManager::setHighScore(int highScore)
{
    _highScore = highScore;
    _file.open(_filePath, ios::out);
    _file << _highScore;
    _file.close();
}