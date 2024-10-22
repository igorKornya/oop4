#ifndef TCOMPLEX_H
#define TCOMPLEX_H
#include "iostream"
#include <QString>
using namespace std;

class TComplex
{
public:
    double re, im;
    TComplex();
    TComplex(double, double);
    friend ostream& operator<<(ostream&, const TComplex&);
    friend istream& operator>>(istream&, TComplex&);
    friend QString& operator<< (QString&, TComplex);
    TComplex operator+ (TComplex);
    TComplex operator- (TComplex);
    TComplex operator/ (TComplex);
    TComplex operator* (TComplex);
    TComplex& operator= (int val);
    TComplex operator / (int a);
    bool operator > (TComplex);
    bool operator < (TComplex);
    double abs() const;
    double arg() const;
    TComplex sqrt();
    TComplex operator-();

};

#endif // TCOMPLEX_H
