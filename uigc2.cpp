#include "uigc2.h"
#include "ui_uigc2.h"

UIGC2::UIGC2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UIGC2)
{
    ui->setupUi(this);
}

UIGC2::~UIGC2()
{
    delete ui;
}
