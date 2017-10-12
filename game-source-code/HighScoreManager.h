#ifndef HIGHSCOREMANAGER_H
#define HIGHSCOREMANAGER_H

#include <fstream>
#include <string>

using std::string;
using std::fstream;
using std::ios;

/**
* HighScoreManager class - Reads a text file containing the highscore and sets the highscore in the textfile
*/
class HighScoreManager
{
    public:
        /**
        * Default constructor. Creates HighScoreManager object
        */
        HighScoreManager();
        /**
	    * Default destructor. Deletes HighScoreManager object
	    */
        ~HighScoreManager();
        /**
        * Returns the highscore that is stored in the textfile
        * @returns _highscore of type int
	    */
        int getHighScore();
        /**
        * Writes the highscore to the highscore textfile
        * @returns _highscore of type int
	    */
        void setHighScore(int highScore);
    
    private:
        int _highScore;
        fstream _file;
        string _filePath;
};

#endif // HIGHSCOREMANAGER_H