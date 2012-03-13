#ifndef UIGC2_H
#define UIGC2_H

#include <QMainWindow>

namespace Ui {
class UIGC2;
}

class UIGC2 : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit UIGC2(QWidget *parent = 0);
    ~UIGC2();
    
private:
    Ui::UIGC2 *ui;
};

#endif // UIGC2_H
