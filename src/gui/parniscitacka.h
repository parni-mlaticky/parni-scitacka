#ifndef PARNISCITACKA_H
#define PARNISCITACKA_H

#define ABOUT_STRING "<p>Ikonka aplikace pochází z balíčku Breeze Icons, distribuovaný pod licencí GPLv3\n</p>"
#define ICON_LINK "<a href=https://github.com/KDE/breeze-icons>Icon source Link</a>"
#define ABOUT_MESSAGE ABOUT_STRING ICON_LINK

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
    void on_ButtonEqual_clicked();
    void on_ButtonSin_clicked();
    void on_actionAbout_triggered();
    void on_actionHistory_triggered();

private:
	Ui::ParniScitacka *ui;
};
#endif // PARNISCITACKA_H
