#ifndef STOPWATCH_H
#define STOPWATCH_H

/**
* StopWatch class - times the speed at which the CPU executes instructions.
*/

class StopWatch 
{
    public:
        /**
        * @brief Default constructor. Creates StopWatch object.
        */
        StopWatch();
        /**
        * @brief Default destructor. Deletes StopWatch object.
        */
        ~StopWatch();
        /**
        * @brief Starts the stopwatch timer.
        */
        void startTimer();
        /**
        * @brief Stops the stopwatch timer.
        * @return double containing the time elapsed.
        */
        double stopTimer();
        /**
        * @brief Returns the clock value of the CPU.
        * @return double containing the clock value.
        */
        double getProcessTime();
        /**
        * @brief Returns the duration of the CPU process by calling the getProcessTime() function.
        * @return double containing the process time.
        */
        double getDuration();	
        
    private:
        double timeInitial;
        double timeFinal;
};
  
#endif //STOPWATCH_H