#include "StopWatch.h"
#include <ctime>

using namespace std;

StopWatch::StopWatch() : timeInitial(0), timeFinal(0)
{
}

StopWatch::~StopWatch()
{
}

void StopWatch::startTimer()
{
	timeInitial = getProcessTime();
}

double StopWatch::stopTimer()
{
	return getProcessTime() - timeInitial;
}

double StopWatch::getDuration()
{	
	return getProcessTime();
}

double StopWatch::getProcessTime()
{
	clock_t time = clock();
	return static_cast<double>(time)/CLOCKS_PER_SEC;
}