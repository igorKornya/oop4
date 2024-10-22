#ifndef TPOLYNOM_H
#define TPOLYNOM_H
#include "iostream"
#include "number.h"
#include <QString>
#include "array.h"

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolynom
{
    EPrintMode printMode;
    CArray root;
    CArray koef;
    int n;
public:
    TPolynom();
    TPolynom(number, number*, int);
    friend ostream& operator <<(ostream&, TPolynom&);
    friend istream& operator >>(istream&, TPolynom&);
    friend QString& operator<< (QString&, TPolynom&);
    void setPrintMode(EPrintMode mode);
    int getSize();
    EPrintMode getPrintMode() const;
    number calculateX(number);
    void setAn(number);
    void setRoot(number, int);
    void setSizePolynom(int);
    void calculateKoef(number);
};

#endif // TPOLYNOM_H
