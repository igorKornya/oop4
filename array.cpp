#include "array.h"
#include "number.h"
#include <cmath>
CArray::CArray()
{
    arr = nullptr;
    lenght = 0;
}


CArray::CArray(int numz)
{
    number* arrz = new number[numz];
    arr = arrz;
    lenght = numz;
}


istream& operator>> (istream& ist, CArray& a)
{
    for (int i = 0; i < a.lenght; i++)
    {
        ist>>a.arr[i];
    }
    return ist;
}

ostream& operator<< (ostream& ost, CArray& b)
{
    for (int i = 0; i < b.lenght; i++)
    {
        ost<<b.arr[i]<<" ";
    }
    ost << endl;
    return ost;
}

number CArray::avg()
{
    number avg;
    for (int i = 0; i < lenght; i++)
    {
        avg = avg + arr[i];
    }
    number result;
    result = avg / lenght;
    return result;
}

void CArray::changeValue(int ind, number val)
{
    arr[ind] = val;
}

number& CArray::operator [](int i)
{
    return arr[i];
}

void CArray::changeLenght(int newLenght)
{
    number* arrx = new number[newLenght];
    if (newLenght > lenght)
    {
        for (int i = 0; i < lenght; i++)
        {
            arrx[i] = arr[i];
        }
    }
    else
    {
        for (int i = 0; i < newLenght; i++)
        {
            arrx[i] = arr[i];
        }
    }
    if (arr != nullptr)
    {
        delete[] arr;
    }
    arr = arrx;
    lenght = newLenght;
}

void CArray::sortUpDown(bool k)
{

    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght - 1; j++)
        {
            if (k == false)
            {
                if (arr[j] > arr[j+1])
                {
                    number b = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = b;
                }
            }
            else
            {
                if (arr[j] < arr[j+1])
                {
                    k = true;
                    number b = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = b;
                }
            }
        }
    }
}

number CArray::SKO()
{
    number summ;
    number average = avg();

    for (int i = 0; i < lenght; i++)
    {
        summ = summ + ((average - arr[i]) * (average - arr[i]));
    }
    number s;
    s = (summ/(lenght-1)).sqrt();
    return s;
}


CArray::~CArray()
{
    if (arr != nullptr)
    {
        delete[] arr;
    }
}
