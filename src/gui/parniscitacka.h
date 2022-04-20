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
	void customActionTest();
    void on_btnNum0_clicked();
    void on_btnNum1_clicked();

private:
	Ui::ParniScitacka *ui;
};
#endif // PARNISCITACKA_H
