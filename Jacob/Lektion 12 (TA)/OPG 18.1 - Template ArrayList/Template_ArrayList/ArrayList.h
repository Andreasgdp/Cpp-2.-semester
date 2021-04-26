#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <iostream>

template <typename T>
class ArrayList {

public:
    ArrayList() {
        mSize = 0;
        mReserved = 0;
        mElems = nullptr;
    }

    // Copy constructor
    ArrayList(const ArrayList<T>& c){
        mSize = c.mSize;
        mReserved = c.mReserved;

        if (mSize > 0) {
            mElems = new T[mReserved];
        }

        for (int i = 0; i < mSize; ++i) {
            mElems[i] = c.mElems[i];
        }
    }

    // Move constructor
    ArrayList(ArrayList<T>&& c) {
        mElems = c.mElems;
        mSize = c.mSize;
        mReserved = c.mReserved;

        c.mElems = nullptr;
        c.mSize = 0;
        c.mReserved = 0;
    }

    // Constructor with initialization of "initialized" elements
    ArrayList(int initialized) {
        mSize = 0;
        mReserved = initialized;
        mElems = new T[mReserved];
    }

    virtual ~ArrayList() {
        if (mReserved > 0) {
            delete[] mElems;
        }
    }

    // Copy assignment operator
    ArrayList<T >& operator=(const ArrayList<T>& a) {
        if (mReserved > 0) {
            delete[] mElems;
        }
        mSize = a.mSize;
        mReserved = a.mReserved;

        if (mSize > 0) {
            mElems = new T[mReserved];
        }

        for (int i = 0; i < mSize; ++i) {
            mElems[i] = a.mElems[i];
        }

        return *this;
    }

    // Move assignment operator
    ArrayList <T>& operator=(ArrayList <T>&& a) {
        if (mReserved > 0) {
            delete[] mElems;
        }

        mElems = a.mElems;
        mSize = a.mSize;
        mReserved = a.mReserved;

        a.mElems = nullptr;
        a.mSize = 0;
        a.mReserved = 0;

        return *this;
    }

    // Add element to dynamic array
    void add(const T& element) {
        if (mSize == mReserved)
            extendStorage();

        mElems[mSize] = element;
        ++mSize;
    }

    /*
     * Inserts the element at placement "idx " in array and moves the remaining
     * items by one place , restoring the old element at "idx ".
     * check whether it is needed to extend the storage .
     * move all elements from mSize to idx (reverse) one element to the right in the array
     * set mElems [idx] equal to the element to be inserted
     */
    void add(int idx, const T& element) {
        if (mSize == mReserved)
            extendStorage();

        for (int i = mSize + 1; i > idx; --i) {
            mElems[i] = mElems[i - 1];
        }
        mElems[idx] = element;
        mSize += 1;
    }

    // Get a const reference to the element at idx
    const T& operator[](int idx) const { return mElems[idx]; }

    // Get a reference to the element at idx
    T& operator[](int idx) { return mElems[idx]; }

    /*
     * Removes the element at placement "idx " by moving all the remaining elements
     * by one place to the left in the array
     */
    void remove(int idx) {
        for (int i = idx; i < mSize; i++) {
            mElems[i] = mElems[i + 1];
        }
        mSize -= 1;
    }

    // Returns the number of elements stored
    int size() const { return mSize; }

    // Returns the number of items currently reserved inmemory
    int reserved() const { return mReserved; }

    // Returns true if number of elements in array is zero
    bool isEmpty() const { return (mSize == 0) ? true : false; }

    // Trims the storage array to the exact number of elements stored.
    void trimToSize() {
        mReserved = mSize;
        T* tmp = new T[mReserved];

        for (int i = 0; i < mSize; i++) {
            tmp[i] = mElems[i];
        }

        delete[] mElems;
        mElems = new T[mReserved];

        for (int i = 0; i < mSize; i++) {
            mElems[i] = tmp[i];
        }

        delete[] tmp;
    }

    /*
     * Sorts the array using insertion sort (or another algorithm)
     * You are not allowed to use standard algorithms from algorithm header.
     */
    void sort() {
        T key;
        int i, j;
            for (i = 1; i < mSize; i++) {
                key = mElems[i];
                j = i - 1;

                while (j >= 0 && mElems[j] > key) {
                    mElems[j + 1] = mElems[j];
                    j = j - 1;
                }
                mElems[j + 1] = key;
            }
    }

    // Returns a new ArrayList with elements from "fromIdx" index to "toIdx"
    ArrayList<T> subArrayList(int fromIdx, int toIdx) const {
        if (fromIdx > toIdx) {
            throw std::runtime_error("fromIdx is larger than toIdx");
        } else if (fromIdx == toIdx) {
            throw std::runtime_error("fromIdx and toIdx is equal");
        } else if (fromIdx < 0 || toIdx < 0) {
            throw std::runtime_error("fromIdx or toIdx is less than zero");
        } else if (fromIdx > mSize || toIdx > mSize) {
            throw std::runtime_error("fromIdx or toIdx is larger than the size of the ArrayList");
        }

        ArrayList<T> array((toIdx - fromIdx) + 1);

        for (int i = fromIdx, j = 0; i <= toIdx; ++i, ++j) {
            array.mElems[j] = mElems[i];
        }
        array.mSize = array.mReserved;

        return array;
    }

    // Returns a new C style array (copy created with new) with all elements
    T* toArray() {

        T* cArray = new T[mSize];

        for (int i = 0; i < mSize; i++) {
            cArray[i] = mElems[i];
        }

        return cArray;
    }


private:
    /*
     * extendStorage():
     * create new array with size 2* mReserved
     * copy old data to the new array
     * delete old array
     * update pointer mElems to point to the new array
     * (Since this method is private, the method will only be used internally,
     * but the functionality is needed).
     */
    void extendStorage() {
        mReserved = (mReserved == 0) ? 1 : mReserved * 2;
        T* tmp = new T[mReserved];

        for (int i = 0; i < mSize; i++) {
            tmp[i] = mElems[i];
        }

        delete[] mElems;
        mElems = new T[mReserved];

        for (int i = 0; i < mSize; i++) {
            mElems[i] = tmp[i];
        }

        delete[] tmp;
    }

    // Member variables
    int mReserved; // The current capacity of " mElems " array
    int mSize; // The number of elements stored

    T* mElems; // Array for storing the elements
};

# endif // ARRAYLIST_H
