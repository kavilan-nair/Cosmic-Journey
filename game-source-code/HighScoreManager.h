#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ios;

class HighScoreManager
{
public:
    HighScoreManager();
    ~HighScoreManager();
   int getHighScore();
   void setHighScore(int highScore);
   
private:
   int _highScore;
   fstream _file;
   string _filePath;
};

#endif // HIGHSCOREMANAGER_H