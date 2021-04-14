#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
public:
    Vector(int n = 0);
    Vector( const Vector & v);

    Vector &operator=(const Vector & rhs);
    bool operator==(const Vector & rhs);
    bool operator!=(const Vector & rhs);

    Vector operator+(const Vector & rhs);
    Vector operator-(const Vector & rhs);

    Vector& operator+=(const Vector & rhs);
    Vector& operator-=(const Vector & rhs);

    double& operator[](int i);
    const double& operator[](int i) const;

    friend std::istream& operator>>(std::istream &input , Vector &a);
    friend std::ostream& operator<<(std::ostream &output , const Vector &a);

    friend double dot(const Vector &l, const Vector &r); // Dot product

    virtual ~Vector();
private:
    int _size;
    double *_elems;
};
#endif // VECTOR_H
