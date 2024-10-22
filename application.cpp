#include "application.h"
#include <iostream>
#include "array.h"
#include "polynom.h"
#include <array>

using namespace std;

TApplication::TApplication()
{
}

int TApplication::menu()
{
    int ch;

    cout << "1. Enter polynom." << endl;
    cout << "2. Change size of polynom" << endl;
    cout << "3. Change coefficient An or root." << endl;
    cout << "4. Calculate X." << endl;
    cout << "5. Output polynom to the screen" << endl;
    cout << "0. Exit" << endl;
    cin >> ch;
    return ch;
}

int TApplication::exec()
{
    int ch;
    CArray arr;
    number root[] = {number(0,0), number(0, 0), number(0, 0)};
    TPolynom polynom(number(0, 0), root, 3);

    while (true)
    {
        ch = menu();
        switch (ch)
        {
        case 0:
        {
            return 0;
        }
        case 1:
        {
            cout << "Input element's(An and roots)" << endl;
            cin >> polynom;
            break;
        }
        case 2:
        {
            int n;
            cout << "Enter new size" << endl;
            cin >> n;
            polynom.setSizePolynom(n);
            break;
        }
        case 3:
        {
            bool choice;
            cout << "Change An or change root?(0/1)" << endl;
            cin >> choice;
            if (!choice)
            {
                number An;
                cout << "Enter new An" << endl;
                cin >> An;
                polynom.setAn(An);
            }
            else
            {
                int ind;
                cout << "Enter position to change old root to new root" << endl;
                cin >> ind;
                number root;
                cout << "Enter new root" << endl;
                cin >> root;
                polynom.setRoot(root, ind);
            }
            break;
        }
        case 4:
        {
            number X;
            cout << "Enter X for calculation" << endl;
            cin >> X;
            cout << polynom.calculateX(X) << endl;
            break;
        }
        case 5:
        {
            bool choice;
            cout << "Canonic or classic? (0/1)" << endl;
            cin >> choice;
            if (!choice)
            {
                polynom.setPrintMode(EPrintModeCanonic);
            }
            else
            {
                polynom.setPrintMode(EPrintModeClassic);
            }
            cout << polynom << endl;
            break;
        }
        default:
        {
            break;
        }
        }
    }
}
