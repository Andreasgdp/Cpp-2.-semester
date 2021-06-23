#ifndef BOX_H
#define BOX_H

template <class T>
class Box {

public:
    Box(int size = 10) {
        _l = 0; _b = 0; _h = 0;
        _size = size;
        if (size > 0) {
            _array = new T[_size];
        }
    }

    int size() {
        return _size;
    }

    // Copy constructor
    Box(const Box<T>& c) {
        _l = c._l; _b = c._b; _h = c._h;
        _size = c._size;

        if (_size > 0) {
            _array = new T[_size];
        }

        for (int i = 0; i < _size; ++i) {
            _array[i] = c._array[i];
        }
    }

    // Copy assignment operator
    Box<T>& operator=(const Box<T>& a) {
        if (_size > 0) {
            delete[] _array;
        }

        _l = a._l; _b = a._b; _h = a._h;
        _size = a._size;

        if (_size > 0) {
            _array = new T[_size];
        }

        for (int i = 0; i < _size; ++i) {
            _array[i] = a._array[i];
        }
        return *this;
    }

    // Destructor
    virtual ~Box() {
        if (_size > 0) {
            delete[] _array;
        }
    }


private:
    T* _array;
    int _size;
    int _l, _b, _h;
};

#endif // BOX_H
