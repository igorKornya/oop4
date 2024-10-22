#include "polynom.h"
#include <QString>
TPolynom::TPolynom()
{
    n = 0;
    printMode = EPrintModeClassic;
}

std::istream& operator>>(std::istream& is, TPolynom& polynom)
{
    std::cout << "Enter coefficient An: ";
    number An ;
    is >> An;
    polynom.setAn(An);

    std::cout << "Enter roots: ";
    for (int i = 0; i < polynom.n; i++)
    {
        is >> polynom.root[i];
    }
    polynom.calculateKoef(polynom.koef[polynom.n]);
    return is;
}

void TPolynom::setPrintMode(EPrintMode mode)
{
    printMode = mode;
}

EPrintMode TPolynom::getPrintMode() const
{
    return printMode;
}

void TPolynom::setSizePolynom(int new_size)
{
    root.changeLenght(new_size);
    koef.changeLenght(new_size + 1);
    n = new_size;
}

void TPolynom::setRoot(number roots, int ind)
{
    if (ind >= 0 && ind < n)
    {
        root[ind] = roots;
        calculateKoef(koef[n]);
    }
    else
    {
        std::cout << "Error: index out of bounds" << std::endl;
    }
}

void TPolynom::setAn(number An)
{
    koef[n] = An;
    calculateKoef(koef[n]);
}

TPolynom::TPolynom(number An, number* roots, int size_polynom)
{
    n = size_polynom;
    root.changeLenght(size_polynom);
    koef.changeLenght(size_polynom + 1);
    for (int i = 0; i < size_polynom; i++)
    {
        root[i] = roots[i];
    }
    calculateKoef(An);
}

void TPolynom::calculateKoef(number An)
{
    for (int i = 0; i < n; i++)
        koef[i] = 0;
    koef[n] = An;
    koef[0] = -root[0];
    koef[1] = number(1, 0);
    for (int i = 2; i <= n; i++)
    {
        koef[i] = koef[i-1];
        for (int j = i-1; j > 0; j--)
            koef[j] = koef[j-1] - koef[j] * root[i-1];
        koef[0] = -koef[0] * root[i-1];
    }
    for (int y = 0; y <= n; y++)
        koef[y] = koef[y] * An;
}

std::ostream& operator <<(std::ostream& os, TPolynom& polynom)
{
    if (polynom.printMode == EPrintModeCanonic)
    {
        for (int i = polynom.n; i > 0; i--)
            os << polynom.koef[i] << " x^" << i << " + ";
        os << polynom.koef[0] << std::endl;
    }
    else
    {
        os << polynom.koef[polynom.n] << " * ";
        for (int i = 0; i < polynom.n - 1; i++)
            os << "(x - " << polynom.root[i] << ") * ";
        os << "(x - " << polynom.root[polynom.n - 1] << ")" << std::endl;
    }
    return os;
}

int TPolynom::getSize()
{
    return n;
}

QString& operator<< (QString& os, TPolynom& polynom)
{
    if (polynom.printMode == EPrintModeCanonic)
    {
        for (int i = polynom.n; i > 0; i--)
        {
            os << polynom.koef[i];
            os += " x^";
            os += QString().setNum(i);
            os += " + ";
        }
        os << polynom.koef[0];
        os += "\n";
    }
    else
    {
        os << polynom.koef[polynom.n];
        os += " * ";
        for (int i = 0; i < polynom.n - 1; i++)
        {
            os += "(x - ";
            os << polynom.root[i];
            os +=  ") * ";
        }
        os += "(x - ";
        os << polynom.root[polynom.n - 1];
        os += ")";
        os += "\n";
    }
    return os;
}

number TPolynom::calculateX(number X)
{
    number val = koef[n];
    for (int i = 0; i < n; i++)
        val = (X - root[i]) * val;
    return val;
}
