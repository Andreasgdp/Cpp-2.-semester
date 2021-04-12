#include "Vector.h"

Vector::Vector(int n) {
    mSize = n;
    if (n > 0) {
        mElems = new double[n];
    }
}

Vector::Vector(const Vector& v) {
    mSize = v.mSize;
    if (v.mSize > 0) {
        mElems = new double[v.mSize];
    }

    for (int i = 0; i < mSize; ++i) {
        mElems[i] = v.mElems[i];
    }
}

Vector::~Vector() {
    if (mSize > 0) {
        delete[] mElems;
    }
}

Vector& Vector::operator=(const Vector& rhs) {
    if (mSize != rhs.mSize && mSize > 0) {
        delete[] mElems;
    }

    if (mSize != rhs.mSize && rhs.mSize > 0) {
        mElems = new double[rhs.mSize];
    }

    mSize = rhs.mSize;

    for (int i = 0; i < mSize; ++i) {
        mElems[i] = rhs.mElems[i];
    }
    return *this;
}

bool Vector::operator==(const Vector& rhs){     // Check for size
    for (int i = 0; i < mSize; ++i) {
        if (mElems[i] != rhs.mElems[i])
            return false;
    }
    return true;
}

bool Vector::operator!=(const Vector& rhs) {     // Check for size
    for (int i = 0; i < mSize; ++i) {
        if (mElems[i] != rhs.mElems[i])
            return true;
    }
    return false;
}

Vector Vector::operator+(const Vector& rhs) {
    Vector v(mSize);
    for (int i = 0; i < mSize; ++i) {
        v[i] = mElems[i] + rhs.mElems[i];
    }
    return v;
}

Vector Vector::operator-(const Vector& rhs) {
    Vector v(mSize);
    for (int i = 0; i < mSize; ++i) {
        v[i] = mElems[i] - rhs.mElems[i];
    }
    return v;
}

Vector& Vector::operator+=(const Vector& rhs) {
    for (int i = 0; i < mSize; ++i) {
        mElems[i] = mElems[i] + rhs.mElems[i];
    }
    return *this;
}

Vector& Vector::operator-=(const Vector& rhs) {
    for (int i = 0; i < mSize; ++i) {
        mElems[i] = mElems[i] - rhs.mElems[i];
    }
    return *this;
}

double& Vector::operator[](int i) {
    return mElems[i];
}

const double& Vector::operator[](int i) const {
    return mElems[i];
}

std::istream& operator>>(std::istream& input, Vector& a) {
    for (int i = 0; i < a.mSize; ++i) {
        input >> a.mElems[i];
    }
    return input;
}

std::ostream& operator<<(std::ostream& output, const Vector& a) {
    output << "(";
    for (int i = 0; i < a.mSize; ++i) {
        if (i > 0)
            output << ", ";
        output << a.mElems[i];
    }
    output << ")";
    return output;
}

double dot(const Vector& l, const Vector& r) { // Dotproduct
    double dot = 0;
    for (int i = 0; i < l.mSize; ++i) {
        dot += l.mElems[i] * r.mElems[i];
    }
    return dot;
}
