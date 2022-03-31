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

private:
    Ui::ParniScitacka *ui;
};
#endif // PARNISCITACKA_H
