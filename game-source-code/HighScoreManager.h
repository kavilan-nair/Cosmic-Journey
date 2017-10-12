#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ios;

/**
* HighScoreManager class - Reads a text file containing the highscore and writes the highscore in the textfile
*/
class HighScoreManager
{
    public:
        /**
        * @brief Default constructor. Creates HighScoreManager object
        */
        HighScoreManager();
        /**
        * @brief Default destructor. Deletes HighScoreManager object
        */
        ~HighScoreManager();
        /**
        * @brief Retrieves the highscore that is stored in the textfile.
        * @returns int containing highScore
        */
        int getHighScore();
        /**
        * @brief Writes the highscore to the highscores textfile
        */
        void setHighScore(int highScore);
    
    private:
        int _highScore;
        fstream _file;
        string _filePath;
};

#endif // HIGHSCOREMANAGER_H