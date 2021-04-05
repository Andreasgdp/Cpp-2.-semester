#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector {
public:
    Vector(int n = 0);
    Vector(const Vector& v);

    virtual ~Vector();

    Vector& operator=(const Vector& rhs);
    bool operator==(const Vector& rhs);
    bool operator!=(const Vector& rhs);

    Vector operator+(const Vector& rhs);
    Vector operator-(const Vector& rhs);

    Vector &operator+=(const Vector& rhs);
    Vector &operator-=(const Vector& rhs);

    double &operator[](int i);
    const double &operator[](int i) const;

    friend std::istream& operator>>(std::istream& input, Vector& a);
    friend std::ostream& operator<<(std::ostream& output, const Vector& a);

    friend double dot(const Vector& l, const Vector& r); // Dotproduct

private:
    int mSize;
    double* mElems;
};

#endif // VECTOR_H
