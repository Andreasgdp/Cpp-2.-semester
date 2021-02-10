#ifndef PI_H
#define PI_H

class Pi
{
private:
	int mOrder;
	double mPi;

public:
	Pi();
	Pi(int order);
	~Pi();

	double calcPi();
};

#endif // !PI_H