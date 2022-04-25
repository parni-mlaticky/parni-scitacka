#ifndef PARNISCITACKA_H
#define PARNISCITACKA_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ParniScitacka; }
QT_END_NAMESPACE

class ParniScitacka : public QMainWindow
{
	Q_OBJECT

public:
	ParniScitacka(QWidget *parent = nullptr);
	~ParniScitacka();

private slots:
    void on_Button0_clicked();
    void on_Button1_clicked();
    void on_Button2_clicked();
    void on_Button3_clicked();
    void on_Button4_clicked();
    void on_Button5_clicked();
    void on_Button6_clicked();
    void on_Button7_clicked();
    void on_Button8_clicked();
    void on_Button9_clicked();
    void on_ButtonReset_clicked();
    void on_ButtonDot_clicked();
    void on_ButtonPlus_clicked();
    void on_ButtonMinus_clicked();
    void on_ButtonMultiply_clicked();
    void on_ButtonDivide_clicked();
    void on_ButtonPow_clicked();
    void on_ButtonSqrt_clicked();

private:
	Ui::ParniScitacka *ui;
};
#endif // PARNISCITACKA_H
