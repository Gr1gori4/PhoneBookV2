#ifndef FORMADDINDIVIDUALS_H
#define FORMADDINDIVIDUALS_H

#include <QWidget>
//#include "phonebook.h"
#include <QLineEdit>
#include <QLabel>
#include <QGridLayout>
#include <QPushButton>
#include <QMessageBox>

namespace Ui {
class FormAddIndividuals;
}

class FormAddIndividuals : public QWidget
{
    Q_OBJECT

public:
    explicit FormAddIndividuals(int i, QWidget *parent = nullptr);
    ~FormAddIndividuals();

private:
    QLineEdit *plename;
    QLineEdit *plesurname;
    QLineEdit *plepatronymic;
    QLineEdit *plenumber;
    QLineEdit *pleadress;
    QLineEdit *plestatus;
    QLineEdit *pledescription;

private slots:
    void AddRecord();
    void EditRecord();
    void DeleteRecord();

};

#endif // FORMADDINDIVIDUALS_H
