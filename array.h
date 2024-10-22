#ifndef CARRAY_H
#define CARRAY_H

#include <iostream>
#include "number.h"

using namespace std;

class CArray
{
    number* arr;
    int lenght;

public:
    CArray();
    CArray(int);
    friend istream& operator>> (istream&, CArray&);
    friend ostream& operator<< (ostream&, CArray&);
    number& operator[](int);
    void changeLenght(int);
    void sortUpDown(bool);
    void changeValue(int, number);
    number SKO();
    number avg();
    ~CArray();
};

#endif // TARRAY_H
