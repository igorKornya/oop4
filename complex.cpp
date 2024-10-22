#include "complex.h"
#include "number.h"
#include "iostream"
#include <cmath>
using namespace std;

TComplex::TComplex(){}

TComplex::TComplex(double r, double i)
{
    re = r;
    im = i;

}
double TComplex::abs() const
{
    return std::sqrt(re * re + im * im);
}

double TComplex::arg() const
{
    return atan2(im, re);
}

TComplex TComplex::sqrt()
{
    double modulus = std::sqrt(re * re + im * im);
    double arg = atan2(im, re);

    double sqrt_modulus = std::sqrt(modulus);
    double sqrt_arg = arg / 2;

    double result_re = sqrt_modulus * (sqrt_arg);
    double result_im = sqrt_modulus * (sqrt_arg);

    return TComplex(result_re, result_im);
}

TComplex TComplex::operator+ (TComplex c)
{
    TComplex t;
    t.re = re + c.re;
    t.im = im + c.im;
    return t;
}

TComplex TComplex::operator-()
{
    TComplex result;
    result.re = -re;
    result.im = -im;
    return result;
}


TComplex& TComplex::operator= (int val)
{
    TComplex t;
    t.re = val;
    t.im = 0;
    return t;
}


TComplex TComplex::operator- (TComplex c)
{
    TComplex t;
    t.re = re - c.re;
    t.im = im - c.im;
    return t;
}

TComplex TComplex::operator* (TComplex c)
{
    TComplex t;
    t.re = re * c.re - im * c.im;
    t.im = im * c.re + re * c.im;
    return t;
}

TComplex TComplex::operator/ (TComplex c)
{
    TComplex t;
    t.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
    t.im = (im * c.re - re * c.im) / (c.re * c.re + c.im * c.im);
    return t;
}

TComplex TComplex::operator / (int a)
{
    TComplex t;
    t.re = re / a;
    t.im = im / a;
    return t;
}

bool TComplex::operator> (TComplex c)
{
    double abs1 = this->abs();
    double abs2 = c.abs();

    if (abs1 > abs2)
    {
        return 1;
    }
    else if (abs1 == abs2)
    {
        return this->arg() > c.arg();
    }
    return false;
}

bool TComplex::operator< (TComplex c)
{
    double abs1 = this->abs();
    double abs2 = c.abs();

    if (abs1 < abs2)
    {
        return 1;
    }
    else if (abs1 == abs2)
    {
        return this->arg() > c.arg();
    }
    return false;
}

ostream& operator<<(ostream& os, const TComplex& c)
{
    os<<"("<<c.re<<"+"<<c.im<<"i)";
    return os;
}

QString& operator<< (QString& s, TComplex c)
{
    s += "(";
    s += QString().setNum(c.re);
    s += "+";
    s += QString().setNum(c.im);
    s += "i)";
    return s;
}

istream& operator>>(istream& is, TComplex& c)
{
    is>>c.re>>c.im;
    return is;
}
