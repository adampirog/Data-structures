#ifndef TIMER_H
#define TIMER_H

//Klasa Timer do mierzenia czasu operacji - wynik w milisekundach
class Timer
{
	private:
		double PCFreq;
		__int64 CounterStart;
	public:
		void startCounter();
		double getCounter();
			
	
};
#endif