#include "Clock.hh"
using namespace std;
void Clock::clockStart()
{
	startTime = clock();
}
void Clock::clockStop()
{
	stopTime = clock();
}

void Clock::start(int numberOfMeasure, int lengthOfObject,IRunnable *object) 
{
	for (int j = 0; j < numberOfMeasure; j++) 
	{
		clockStart();
		
			object->run(lengthOfObject);
		
		clockStop();
		time = (double)1000. / CLOCKS_PER_SEC*(stopTime - startTime);
		sum = sum + time;
	}

	countAverage(numberOfMeasure,sum);	
}
void Clock::countAverage(int numberOfMeasure, double sum)
{
	average = sum / numberOfMeasure;
	cout << "Czas wykonania: " << average << "ms" << endl;
	sum = 0;
}
