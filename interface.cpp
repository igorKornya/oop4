#include "interface.h"
#include "ui_interface.h"
#include <QDebug>

interface::interface(QWidget *parent)
    : QWidget(parent)
{
    polynom.setSizePolynom(2);
    polynom.setAn(number(1, 0));
    polynom.setRoot(number(2, 0), 0);
    polynom.setRoot(number(3, 0), 1);

    setWindowTitle("Работа №4");
    setFixedSize(750, 500);
    //кнопки
    enter_polynom_btn = new QPushButton("Enter polynom", this);
    enter_polynom_btn->setGeometry(550, 50, 150, 50);
    set_size_btn = new QPushButton("Change size of polynom", this);
    set_size_btn->setGeometry(550, 100, 150, 50);
    setAn_btn = new QPushButton("Set An", this);
    setAn_btn->setGeometry(550, 150, 75, 50);
    setRoot_btn = new QPushButton("Set root", this);
    setRoot_btn->setGeometry(625, 150, 75, 50);
    calcul_X_btn = new QPushButton("Calculate X", this);
    calcul_X_btn->setGeometry(550, 200, 150, 50);
    print_mode_class_btn = new QPushButton("Classic print", this);
    print_mode_class_btn->setGeometry(550, 250, 75, 50);
    print_mode_canon_btn = new QPushButton("Canon print", this);
    print_mode_canon_btn->setGeometry(625, 250, 75, 50);
    exit_btn = new QPushButton("Exit", this);
    exit_btn->setGeometry(550, 300, 150, 50);
    output = new QLabel(this);
    output->setGeometry(50, 350, 350, 150);
    numRoot = new QLabel("№" + QString::number(currRootIndex), this);
    numRoot->setGeometry(50, 75, 100, 50);

    //названия и строки

    //An
    name_An = new QLabel("An = ", this);
    name_An->setGeometry(50, 100, 100, 50);
    An_re = new QLineEdit(this);
    An_re->setGeometry(80, 115, 35, 20);
    delimeter_An = new QLabel("+           i",this);
    delimeter_An->setGeometry(120, 100, 100, 50);
    An_im = new QLineEdit(this);
    An_im->setGeometry(135, 115, 35, 20);
    name_An->hide();
    An_re->hide();
    An_im->hide();
    delimeter_An->hide();

    //X
    name_X = new QLabel("X = ", this);
    name_X->setGeometry(50, 100, 100, 50);
    X_re = new QLineEdit(this);
    X_re->setGeometry(80, 115, 35, 20);
    delimeter_X = new QLabel("+           i",this);
    delimeter_X->setGeometry(120, 100, 100, 50);
    X_im = new QLineEdit(this);
    X_im->setGeometry(135, 115, 35, 20);
    name_X->hide();
    X_re->hide();
    X_im->hide();
    delimeter_X->hide();

    //SetSize
    setSize_name = new QLabel("new size = ", this);
    setSize_name->setGeometry(50, 100, 100, 50);
    setSize_val = new QLineEdit(this);
    setSize_val->setGeometry(120, 115, 35, 20);
    setSize_name->hide();
    setSize_val->hide();

    //root
    name_root = new QLabel("root = ", this);
    name_root->setGeometry(50, 100, 100, 50);
    root_re = new QLineEdit(this);
    root_re->setGeometry(90, 115, 35, 20);
    delimeter_root = new QLabel(" +          i",this);
    delimeter_root->setGeometry(120, 100, 100, 50);
    root_im = new QLineEdit(this);
    root_im->setGeometry(135, 115, 35, 20);
    pos_root = new QLabel("Position of new root", this);
    pos_root->setGeometry(50, 75, 125, 50);
    index_of_pos = new QLineEdit(this);
    index_of_pos->setGeometry(170, 90, 35, 20);
    root_im->hide();
    root_re->hide();
    numRoot->hide();
    delimeter_root->hide();
    name_root->hide();
    pos_root->hide();
    index_of_pos->hide();

    //кнопки записи
    OK_enter_polynom_btn = new QPushButton("Enter data", this);
    OK_enter_polynom_btn->setGeometry(50, 140, 125, 50);
    OK_enter_polynom_btn->hide();

    OK_setSize_btn = new QPushButton("Enter data", this);
    OK_setSize_btn->setGeometry(50, 140, 125, 50);
    OK_setSize_btn->hide();

    OK_setAn_btn = new QPushButton("Enter data", this);
    OK_setAn_btn->setGeometry(50, 140, 125, 50);
    OK_setAn_btn->hide();

    OK_calcul_X_btn = new QPushButton("Enter data", this);
    OK_calcul_X_btn->setGeometry(50, 140, 125, 50);
    OK_calcul_X_btn->hide();

    OK_goEnter_root_btn = new QPushButton("Enter data", this);
    OK_goEnter_root_btn->setGeometry(50, 140, 125, 50);
    OK_goEnter_root_btn->hide();

    OK_changeRoot_btn = new QPushButton("Enter data", this);
    OK_changeRoot_btn->setGeometry(50, 140, 125, 50);
    OK_changeRoot_btn->hide();

    connect(set_size_btn, SIGNAL(pressed()), this, SLOT(setSize_of_polynom()));
    connect(OK_setSize_btn, SIGNAL(pressed()), this, SLOT(OK_setSize_of_polynom()));

    connect(setAn_btn, SIGNAL(pressed()), this, SLOT(setAn_of_polynom()));
    connect(OK_setAn_btn, SIGNAL(pressed()), this, SLOT(OK_setAn_of_polynom()));


    connect(setRoot_btn, SIGNAL(pressed()), this, SLOT(setRoot_of_polynom()));
    connect(OK_changeRoot_btn, SIGNAL(pressed()), this, SLOT(OK_setRoot_of_polynom()));

    connect(enter_polynom_btn, SIGNAL(pressed()), this, SLOT(enterPolynom()));
    connect(OK_enter_polynom_btn, SIGNAL(pressed()), this, SLOT(OK_enterPolynom()));


    connect(calcul_X_btn, SIGNAL(pressed()), this, SLOT(calcul_X_polynom()));
    connect(OK_calcul_X_btn, SIGNAL(pressed()), this, SLOT(OK_calcul_X_polynom()));


    connect(print_mode_canon_btn, SIGNAL(pressed()), this, SLOT(printModeCanon_of_polynom()));
    connect(print_mode_class_btn, SIGNAL(pressed()), this, SLOT(printModeClass_of_polynom()));

    connect(OK_enter_polynom_btn, SIGNAL(pressed()), this, SLOT(goEnter_root()));
    connect(OK_goEnter_root_btn, SIGNAL(pressed()), this, SLOT(OK_goEnter_root_of_polynom()));

    connect(exit_btn, &QPushButton::clicked, this, &QWidget::close);
}

void interface::setSize_of_polynom()
{
    setSize_name->show();
    setSize_val->show();
    OK_setSize_btn->show();
}
void interface::OK_setSize_of_polynom()
{
    polynom.setSizePolynom(setSize_val->text().toInt());
    setSize_name->hide();
    setSize_val->hide();
    OK_setSize_btn->hide();
}


void interface::setAn_of_polynom()
{
    name_An->show();
    An_re->show();
    delimeter_An->show();
    An_im->show();
    OK_setAn_btn->show();
}
void interface::OK_setAn_of_polynom()
{
    polynom.setAn(number(An_re->text().toDouble(), An_im->text().toDouble()));
    name_An->hide();
    An_re->hide();
    delimeter_An->hide();
    An_im->hide();
    OK_setAn_btn->hide();
}

void interface::setRoot_of_polynom()
{
    name_root->show();
    pos_root->show();
    index_of_pos->show();
    root_re->show();
    root_im->show();
    delimeter_root->show();
    OK_changeRoot_btn->show();
}
void interface::OK_setRoot_of_polynom()
{
    polynom.setRoot(number(root_re->text().toDouble(), root_im->text().toDouble()), index_of_pos->text().toInt());
    pos_root->hide();
    index_of_pos->hide();
    root_re->hide();
    name_root->hide();
    root_im->hide();
    delimeter_root->hide();
    OK_changeRoot_btn->hide();
}


void interface::enterPolynom()
{
    name_An->show();
    An_re->show();
    delimeter_An->show();
    An_im->show();
    OK_enter_polynom_btn->show();
}
void interface::OK_enterPolynom()
{
    polynom.setAn(number(An_re->text().toDouble(), An_im->text().toDouble()));
    name_An->hide();
    An_re->hide();
    delimeter_An->hide();
    An_im->hide();
    OK_enter_polynom_btn->hide();
}

void interface::goEnter_root()
{
    name_root->show();
    root_re->show();
    root_im->show();
    numRoot->show();
    delimeter_root->show();
    OK_goEnter_root_btn->show();
}
void interface::OK_goEnter_root_of_polynom()
{
    polynom.setRoot(number(root_re->text().toDouble(), root_im->text().toDouble()), currRootIndex);
    if (currRootIndex < polynom.getSize() - 1)
    {
        currRootIndex++;
        numRoot->setText("№" + QString::number(currRootIndex));
        root_re->clear();
        root_im->clear();
    }
    else {
        name_root->hide();
        root_re->hide();
        root_im->hide();
        numRoot->hide();
        delimeter_root->hide();
        OK_goEnter_root_btn->hide();
        return;
    }
}

void interface::calcul_X_polynom()
{
    OK_calcul_X_btn->show();
    name_X->show();
    X_re->show();
    X_im->show();
    delimeter_X->show();
}
void interface::OK_calcul_X_polynom()
{
    polynom.calculateX(number(X_re->text().toDouble(), X_im->text().toDouble()));
    OK_calcul_X_btn->hide();
    name_X->hide();
    X_re->hide();
    X_im->hide();
    delimeter_X->hide();
}


void interface::printModeClass_of_polynom()
{
    polynom.setPrintMode(EPrintModeClassic);
    QString outputText;
    outputText << polynom;
    output->setText(outputText);
}

void interface::printModeCanon_of_polynom()
{
    polynom.setPrintMode(EPrintModeCanonic);
    QString outputText;
    outputText << polynom;
    output->setText(outputText);
}


interface::~interface()
{
    delete pos_root;
    delete index_of_pos;
    delete name_root;
    delete delimeter_root;
    delete root_re;
    delete root_im;
    delete name_An;
    delete delimeter_An;
    delete An_re;
    delete An_im;
    delete setSize_name;
    delete setSize_val;

    delete name_X;
    delete delimeter_X;
    delete X_re;
    delete X_im;

    //кнопки для меню
    delete enter_polynom_btn;
    delete setAn_btn;
    delete setRoot_btn;
    delete calcul_X_btn;
    delete print_mode_class_btn;
    delete print_mode_canon_btn;
    delete set_size_btn;
    delete exit_btn;

    //кнопки для подтверждения
    delete OK_setAn_btn;
    delete OK_setSize_btn;
    delete OK_calcul_X_btn;
    delete OK_enter_polynom_btn;
    delete OK_changeRoot_btn;

    //выводим полином
    delete output;
}

