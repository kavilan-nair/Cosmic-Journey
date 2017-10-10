#ifndef STOPWATCH_H
#define STOPWATCH_H

class StopWatch 
{
public:
	StopWatch();
	void startTimer();
	double stopTimer();
	double getProcessTime();
	double getDuration();	
	
private:
	double timeInitial;
	double timeFinal;
};
  
#endif //STOPWATCH_H