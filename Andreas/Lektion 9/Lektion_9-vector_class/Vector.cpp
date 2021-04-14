#include "Vector.h"

Vector::Vector(int n) {
    if (n >= 0) {
        this->_size = n;
        this->_elems = new double[n];
    } else {
        throw std::invalid_argument("Size is not larger than 0!");
    }
}

Vector::Vector(const Vector &v) {
    if(v._size > 0) {
        this->_elems = new double[v._size];
    }

    this->_size = v._size;

    for(int i = 0; i < this->_size; ++i) {
        this->_elems[i] = v._elems[i];
    }
	
}

Vector& Vector::operator=(const Vector &rhs) {
    if(this->_size != rhs._size) {
        delete[] this->_elems;
        _elems = new double[rhs._size];
    }

    this->_size = rhs._size;

    for(int i = 0; i < this->_size; ++i) {
        this->_elems[i] = rhs._elems[i];
    }

    return *this;
}

bool Vector::operator==(const Vector &rhs) {
    if (this->_size == rhs._size) {

        for (int i = 0; i < this->_size; i++)
		{
            if (this->_elems[i] != rhs._elems[i]) {
                return false;
            }
		}

        return true;
    }
    return false;
}

bool Vector::operator!=(const Vector &rhs) {
    return !(*this == rhs);
}

Vector Vector::operator+(const Vector &rhs) {
    if (this->_size == rhs._size) {

        for (int i = 0; i < this->_size; i++)
		{
            this->_elems[i] += rhs._elems[i];
		}
		
    }  else {
        throw std::invalid_argument("Vectors not the same size!");
    }

    return *this;
}

Vector Vector::operator-(const Vector &rhs) {
    if (this->_size == rhs._size) {

        for (int i = 0; i < this->_size; i++)
        {
            this->_elems[i] -= rhs._elems[i];
        }

    }  else {
        throw std::invalid_argument("Vectors not the same size!");
    }

    return *this;
}

Vector& Vector::operator+=(const Vector &rhs) {
    if (this->_size == rhs._size) {

        for (int i = 0; i < this->_size; i++)
        {
            this->_elems[i] += rhs._elems[i];
        }

    }  else {
        throw std::invalid_argument("Vectors not the same size!");
    }

    return *this;
}

Vector& Vector::operator-=(const Vector &rhs) {
    if (this->_size == rhs._size) {

        for (int i = 0; i < this->_size; i++)
        {
            this->_elems[i] -= rhs._elems[i];
        }

    }  else {
        throw std::invalid_argument("Vectors not the same size!");
    }

    return *this;
}

double& Vector::operator[](int i) {
    if (this->_size >= i && i >= 0) {
        return this->_elems[i];
    }
    throw std::invalid_argument("The index is not valid");
}

const double& Vector::operator[](int i) const {
    if (this->_size >= i && i >= 0) {
        return this->_elems[i];
    }
    throw std::invalid_argument("The index is not valid");
}

std::istream& operator>>(std::istream &input, Vector &a) {
    for(int i = 0; i < a._size; ++i) {
        input >> a._elems[i];
    }
    return input;
}

std::ostream& operator<<(std::ostream &output, const Vector &a) {
    output << "(";

    for(int i = 0; i < a._size; ++i) {
        if(i > 0) {
            output << ", ";
        }

        output << a._elems[i];
    }

    output << ")" << std::endl;

    return output;
}

double dot(const Vector &l, const Vector &r) {
	if(l._size != r._size) {
        throw std::invalid_argument("Error: vectors must be of same size");
    }

    double answer = 0;

    for(int i = 0; i < l._size; ++i) {
        answer += l._elems[i]*r._elems[i];
    }

    return answer;
}

Vector::~Vector() {
    delete[] this->_elems;
}
