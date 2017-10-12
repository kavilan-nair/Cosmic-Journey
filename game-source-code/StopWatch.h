#ifndef STOPWATCH_H
#define STOPWATCH_H

/**
* StopWatch class - Reads a text file containing the highscore and sets the highscore in the textfile
*/

class StopWatch 
{
    public:
        /**
        * Default constructor. Creates StopWatch object
        */
        StopWatch();
        /**
        * Default destructor. Deletes StopWatch object
        */
        ~StopWatch();
        /**
        * Starts the stopwatch timer
        */
        void startTimer();
        /**
        * Stops the stopwatch timer and 
        * @return the time elapsed
        */
        double stopTimer();
        /**
        * Returns the duration time
        * @return process time of type double
        */
        double getProcessTime();
        /**
        * Returns the duration time
        * @return duration time of type double
        */
        double getDuration();	
        
    private:
        double timeInitial;
        double timeFinal;
};
  
#endif //STOPWATCH_H