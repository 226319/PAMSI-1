#ifndef CLOCK_HH
#define CLOCK_HH
#include <iostream>
#include <ctime>
#include "IRunnable.hh"
class Clock
{
private:
	clock_t stopTime;
	clock_t startTime;
	double sum;
	double time;
	double average;
	
public:
	void clockStart();
	void clockStop();
	void countAverage(int numberOfMeasure, double sum);
	void start(int numberOfMeasure, int length, IRunnable *object);
Clock()
{
stopTime=0;
startTime=0;
sum=0;
time=0;
average=0;
}
};
#endif
