#include "phonebook.h"
#include "ui_phonebook.h"

PhoneBook::PhoneBook(QWidget *parent) :
    QMainWindow(parent)
  ,ui(new Ui::PhoneBook)
{

    QMenu * pmDirIndividual = menuBar()->addMenu("Справочник физических лиц");
    QMenu * paSearchRecord = new QMenu("Поиск");
    QMenu * paDisplayRecord = new QMenu("Отобразить все записи");
    QMenu * pmDirEntitie= menuBar()->addMenu("Справочник юридических лиц");
    QMenu * paSearchRecordEntitie = new QMenu("Поиск");
    QMenu * paDisplayRecordEntitie = new QMenu("Отобразить все записи");
    QAction * paExit = menuBar()->addAction("Выход");

    connect(paExit,SIGNAL(triggered()),SLOT(Exit()));

    QAction *paAddRecord = new QAction(tr("Добавить запись"));
    QAction *paEditRecord = new QAction(tr("Редактировать запись"), this);
    QAction *paDeleteRecord = new QAction(tr("Удалить запись"), this);
    QAction *paSearchRecordName = new QAction(tr("По имени"), this);
    QAction *paSearchRecordSurname = new QAction(tr("По фамилии"), this);
    QAction *paSearchRecordNumber = new QAction(tr("По номеру"), this);
    QAction *paDisplayRecordList = new QAction(tr("Списком"), this);
    QAction *paSearcheRecordMap = new QAction(tr("Картой"), this);

    paSearchRecord->addAction(paSearchRecordName);
    paSearchRecord->addAction(paSearchRecordSurname);
    paSearchRecord->addAction(paSearchRecordNumber);

    paDisplayRecord->addAction(paDisplayRecordList);
    paDisplayRecord->addAction(paSearcheRecordMap);

    pmDirIndividual->addAction(paAddRecord);
    pmDirIndividual->addAction(paEditRecord);
    pmDirIndividual->addAction(paDeleteRecord);
    pmDirIndividual->addMenu(paSearchRecord);
    pmDirIndividual->addMenu(paDisplayRecord);

    connect(paAddRecord,SIGNAL(triggered()),SLOT(AddRecord()));
    connect(paEditRecord,SIGNAL(triggered()),SLOT(EditRecord()));
    connect(paDeleteRecord,SIGNAL(triggered()),SLOT(DeleteRecord()));
    connect(paSearchRecordName,SIGNAL(triggered()),SLOT(SearchRecordName()));
    connect(paSearchRecordSurname,SIGNAL(triggered()),SLOT(SearchRecordSurname()));
    connect(paSearchRecordNumber,SIGNAL(triggered()),SLOT(SearchRecordNumber()));
    connect(paDisplayRecordList,SIGNAL(triggered()),SLOT(DisplayRecordList()));
    connect(paSearcheRecordMap,SIGNAL(triggered()),SLOT(SearcheRecordMap()));



    QAction *paAddRecordEntitie = new QAction(tr("Добавить запись"), this);
    QAction *paEditRecordEntitie = new QAction(tr("Редактировать запись"), this);
    QAction *paDeleteRecordEntitie = new QAction(tr("Удалить запись"), this);
    QAction *paSearchRecordTitle = new QAction(tr("По названию"), this);
    QAction *paSearchRecordDirector = new QAction(tr("По ФИО директора"), this);
    QAction *paSearchRecordOGRN = new QAction(tr("По ОГРН"), this);
    QAction *paSearchRecordBranch = new QAction(tr("По названию отрасли"), this);
    QAction *paDisplayRecordListEntitie = new QAction(tr("Списком"), this);
    QAction *paSearcheRecordMapEntitie = new QAction(tr("Картой"), this);

    paSearchRecordEntitie->addAction(paSearchRecordTitle);
    paSearchRecordEntitie->addAction(paSearchRecordDirector);
    paSearchRecordEntitie->addAction(paSearchRecordOGRN);
    paSearchRecordEntitie->addAction(paSearchRecordBranch);

    paDisplayRecordEntitie->addAction(paDisplayRecordListEntitie);
    paDisplayRecordEntitie->addAction(paSearcheRecordMapEntitie);

    pmDirEntitie->addAction(paAddRecordEntitie);
    pmDirEntitie->addAction(paEditRecordEntitie);
    pmDirEntitie->addAction(paDeleteRecordEntitie);
    pmDirEntitie->addMenu(paSearchRecordEntitie);
    pmDirEntitie->addMenu(paDisplayRecordEntitie);

    connect(paAddRecordEntitie,SIGNAL(triggered()),SLOT(AddRecordEntitie()));
    connect(paEditRecordEntitie,SIGNAL(triggered()),SLOT(EditRecordEntitie()));
    connect(paDeleteRecordEntitie,SIGNAL(triggered()),SLOT(DeleteRecordEntitie()));
    connect(paSearchRecordTitle,SIGNAL(triggered()),SLOT(SearchRecordTitle()));
    connect(paSearchRecordDirector,SIGNAL(triggered()),SLOT(SearchRecordDirector()));
    connect(paSearchRecordOGRN,SIGNAL(triggered()),SLOT(SearchRecordOGRN()));
    connect(paSearchRecordBranch,SIGNAL(triggered()),SLOT(SearchRecordBranch()));
    connect(paDisplayRecordListEntitie,SIGNAL(triggered()),SLOT(DisplayRecordListEntitie()));
    connect(paSearcheRecordMapEntitie,SIGNAL(triggered()),SLOT(SearcheRecordMapEntitie()));

    QHBoxLayout* phbxlMain = new QHBoxLayout();
    phbxlMain->setContentsMargins(10, 10, 10, 10);
    phbxlMain->setSpacing(20);

    QGroupBox *pgbTop = new QGroupBox();
    QGroupBox *pgbMedium = new QGroupBox();
    QGroupBox *pgbLower = new QGroupBox();

    phbxlMain->addWidget(pgbTop);
    phbxlMain->addWidget(pgbMedium);
    phbxlMain->addWidget(pgbLower);

    //pgbTop
    QLabel *plState = new QLabel("Справочник готов к работе");
    QLabel *plDirIndividual = new QLabel("Справочник физических лиц");
    QLabel *plDirEntitie = new QLabel("Справочник юридических лиц");

    QHBoxLayout* phbxlTop = new QHBoxLayout();
    phbxlTop->addWidget(plState);
    phbxlTop->addWidget(plDirIndividual);
    phbxlTop->addWidget(plDirEntitie);

    pgbTop->setLayout(phbxlTop);


    setLayout(phbxlMain);





}

PhoneBook::~PhoneBook()
{
    delete ui;
}

/*void PhoneBook::СreatureMenuDirIndividual()
{

}*/

void PhoneBook::AddRecord()
{
    QMessageBox msg;
    msg.setText("Hello");
    msg.exec();
}

void PhoneBook::EditRecord()
{
    QMessageBox msg;
    msg.setText("Hello");
    msg.exec();
}

void PhoneBook::DeleteRecord()
{

}

void PhoneBook::SearchRecordName()
{

}

void PhoneBook::SearchRecordSurname()
{

}

void PhoneBook::SearchRecordNumber()
{

}

void PhoneBook::DisplayRecordList()
{

}

void PhoneBook::SearcheRecordMap()
{

}

void PhoneBook::AddRecordEntitie()
{

}

void PhoneBook::EditRecordEntitie()
{

}

void PhoneBook::DeleteRecordEntitie()
{

}

void PhoneBook::SearchRecordTitle()
{

}

void PhoneBook::SearchRecordDirector()
{

}

void PhoneBook::SearchRecordOGRN()
{

}

void PhoneBook::SearchRecordBranch()
{

}

void PhoneBook::DisplayRecordListEntitie()
{

}

void PhoneBook::SearcheRecordMapEntitie()
{

}

void PhoneBook::Exit()
{
    close();
}
