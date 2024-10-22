#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include "polynom.h"

class interface : public QWidget
{
    Q_OBJECT

    TPolynom polynom;

    //названия и строки
    QLabel *name_root, *delimeter_root;//
    QLineEdit *root_re, *root_im;//

    QLabel *name_An, *delimeter_An;//
    QLineEdit *An_re, *An_im;//

    QLabel *setSize_name;//
    QLineEdit *setSize_val;//


    QLabel *name_X, *delimeter_X;//
    QLineEdit *X_re, *X_im;//

    QLabel *numRoot;
    QLabel *pos_root;
    QLineEdit *index_of_pos;

    //кнопки для меню
    QPushButton *enter_polynom_btn;//
    QPushButton *setAn_btn;//
    QPushButton *setRoot_btn;//
    QPushButton *calcul_X_btn;//
    QPushButton *print_mode_class_btn;
    QPushButton *print_mode_canon_btn;
    QPushButton *set_size_btn;//
    QPushButton *exit_btn;//

    //кнопки для подтверждения
    QPushButton *OK_setAn_btn;
    QPushButton *OK_setSize_btn;
    QPushButton *OK_calcul_X_btn;
    QPushButton *OK_enter_polynom_btn;
    QPushButton *OK_changeRoot_btn;
    QPushButton *OK_goEnter_root_btn;

    //выводим полином
    QLabel *output;//

public:
    interface(QWidget *parent = nullptr);
    ~interface();
    int currRootIndex = 0;
public slots:
    void setSize_of_polynom();
    void OK_setSize_of_polynom();

    void setAn_of_polynom();
    void OK_setAn_of_polynom();

    void setRoot_of_polynom();
    void OK_setRoot_of_polynom();

    void enterPolynom();
    void OK_enterPolynom();


    void calcul_X_polynom();
    void OK_calcul_X_polynom();


    void printModeClass_of_polynom();
    void printModeCanon_of_polynom();

    void goEnter_root();
    void OK_goEnter_root_of_polynom();

};
#endif // INTERFACE_H
