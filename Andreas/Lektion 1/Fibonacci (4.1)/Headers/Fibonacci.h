#ifndef FIBONACCI_h
#define FIBONACCI_h

class Fibonacci
{
private:
	int mTimePeroid;
	int mInitialSize;
	int mUpdateDay;

public:
	Fibonacci();
	Fibonacci(int initialSize, int timePeriod, int updateDay);
	~Fibonacci();

	void setUpdateDay(int updateDay);
	void setInitialSize(int initialSize);
	void setTimePeroid(int timePeroid);

	void calcCrud();
	int getCurrSize() const;
};

#endif // !FIBONACCI_h