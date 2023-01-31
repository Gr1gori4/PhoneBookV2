#include "formaddindividuals.h"


FormAddIndividuals::FormAddIndividuals(int i, QWidget *parent) :
    QWidget(parent)
{
    QLabel* plsurname = new QLabel(tr("Фамилия:"));
    QLabel* plname = new QLabel (tr("Имя:"));
    QLabel* plpatronymic = new QLabel (tr("Отчество:"));
    QLabel* plnumber = new QLabel (tr("Номер телефона:"));
    QLabel* pladress = new QLabel (tr("Почта:"));
    QLabel* plstatus = new QLabel (tr("Статус:"));
    QLabel* pldescription = new QLabel (tr("Описание:"));

    plename = new QLineEdit ();
    plesurname = new QLineEdit ();
    plepatronymic = new QLineEdit ();
    plenumber = new QLineEdit ();
    pleadress = new QLineEdit ();
    plestatus = new QLineEdit ();
    pledescription = new QLineEdit ();

    plesurname->setPlaceholderText(tr("Введите фамилию"));
    plename->setPlaceholderText(tr("Введите имя"));
    plepatronymic->setPlaceholderText(tr("Введите отчество"));
    plenumber->setPlaceholderText(tr("Введите номер телефона"));
    pleadress->setPlaceholderText(tr("Введите адрес почты"));
    plestatus->setPlaceholderText(tr("Введите статус"));
    pledescription->setPlaceholderText(tr("Введите описание"));

    QPushButton *ppbinsert = new QPushButton (tr("Добавить"));
    QPushButton *ppbedit = new QPushButton (tr("Редактировать"));
    QPushButton *ppbdelete = new QPushButton (tr("Удалить"));

    QVBoxLayout  *pvbxlform = new QVBoxLayout();

    QGridLayout* pgrdLayout = new QGridLayout;
    pgrdLayout->setContentsMargins(5, 5, 5, 5);
    pgrdLayout->setSpacing(15);

    pgrdLayout->addWidget(plsurname, 0, 0);
    pgrdLayout->addWidget(plesurname, 0, 1) ;
    pgrdLayout->addWidget(plname, 1, 0);
    pgrdLayout->addWidget(plename, 1, 1);
    pgrdLayout->addWidget(plpatronymic, 2, 0);
    pgrdLayout->addWidget(plepatronymic, 2, 1);
    pgrdLayout->addWidget(plnumber, 3, 0);
    pgrdLayout->addWidget(plenumber, 3, 1) ;
    pgrdLayout->addWidget(pladress, 4, 0);
    pgrdLayout->addWidget(pleadress, 4, 1);
    pgrdLayout->addWidget(plstatus, 5, 0);
    pgrdLayout->addWidget(plestatus, 5, 1) ;
    pgrdLayout->addWidget(pldescription, 6, 0);
    pgrdLayout->addWidget(pledescription, 6, 1) ;


    pvbxlform->addLayout(pgrdLayout);
    pvbxlform->addWidget(ppbinsert);
    pvbxlform->addWidget(ppbedit);
    pvbxlform->addWidget(ppbdelete);
    if(i<0)
    {
        ppbinsert->show();
        ppbedit->hide();
        ppbdelete->hide();
    }
    else if (i==0)
    {
        ppbinsert->hide();
        ppbedit->show();
        ppbdelete->hide();
    }
    else
    {
        ppbinsert->hide();
        ppbedit->hide();
        ppbdelete->show();
    }

    setLayout(pvbxlform);

    connect(ppbinsert,SIGNAL(clicked()),SLOT(AddRecord()));
    connect(ppbedit,SIGNAL(clicked()),SLOT(EditRecord()));
    connect(ppbdelete,SIGNAL(clicked()),SLOT(DeleteRecord()));
}

FormAddIndividuals::~FormAddIndividuals()
{

}

void FormAddIndividuals::AddRecord()
{
    QMessageBox msg;
    msg.setText("Запись успешно добавлена");
    if(msg.exec())
        QWidget::close();

}

void FormAddIndividuals::EditRecord()
{
    QMessageBox msg;
    msg.setText("Запись успешно отредактирована");
    if(msg.exec())
        QWidget::close();
}

void FormAddIndividuals::DeleteRecord()
{
    QMessageBox msg;
    msg.setText("Запись успешно удалена");
    if(msg.exec())
        QWidget::close();
}
