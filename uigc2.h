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
    int activeLight;
    bool finished, finished2;
    QString name;
    double newX, newY, newZ;
    double newR, newG, newB, newA;

private slots:
    void on_actionAcaba_Ruta_triggered();
    void on_actionComen_a_Ruta_triggered();
    void on_controlsButton_released();
    void on_visitantButton_released();
    void on_editorButton_released();
    void on_rotationSlider_valueChanged(int value);
    void on_sizeSlider_valueChanged(int value);
    void on_deleteObjectButton_clicked();
    void on_nameEdit_textChanged(QString );
    void on_createNewObjectButton_clicked();
    void on_aLight_valueChanged(double a);
    void on_bLight_valueChanged(double b);
    void on_gLight_valueChanged(double g);
    void on_rLight_valueChanged(double r);
    void on_zPos_valueChanged(double z);
    void on_yPos_valueChanged(double y);
    void on_xPos_valueChanged(double x);
    void on_lightList_activated(int index);
    void on_paintLight_clicked();
    void on_moveLight_clicked();
    void on_deleteLight_clicked();
    void on_addLight_clicked();
    void on_comboBoxObjectes_currentIndexChanged(const QString &arg1);
    void on_comboBoxObjectes_highlighted(const QString &arg1);
    void on_loadMuseumButton_clicked();
    void on_saveMuseumButton_clicked();


    void on_tabWidget_currentChanged(int index);
    void on_lightList_currentIndexChanged(int index);
    void on_lightList_highlighted(int index);
};

#endif // UIGC2_H
