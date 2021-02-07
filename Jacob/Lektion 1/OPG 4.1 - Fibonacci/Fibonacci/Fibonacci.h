#ifndef FIBONACCI_H
#define FIBONACCI_H


class Fibonacci
{
public:
    Fibonacci();
    Fibonacci(int initialSize, int days);

    int solve() const;

private:
    int mInitialSize, mDays;
};

#endif // FIBONACCI_H
