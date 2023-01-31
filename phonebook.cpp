#include "phonebook.h"


PhoneBook::PhoneBook(QWidget *parent) :
    QWidget(parent)

{
    CreateMenu(this);

    QVBoxLayout* pvbxlMain = new QVBoxLayout();
    pvbxlMain->setContentsMargins(10, 10, 10, 10);
    pvbxlMain->setSpacing(10);

    QGroupBox *pgbTop = new QGroupBox();
    QGroupBox *pgbMedium = new QGroupBox();
    pgbLower = new QGroupBox();

    pvbxlMain->addWidget(pgbTop);
    pvbxlMain->addWidget(pgbMedium);
    pvbxlMain->addWidget(pgbLower);

    //pgbTop
    plState = new QLabel(tr("Справочник готов к работе"));
    plDirIndividual = new QLabel(tr("Справочник физических лиц"));
    plDirEntitie = new QLabel(tr("Справочник юридических лиц"));

    QHBoxLayout* phbxlTop = new QHBoxLayout();
    phbxlTop->addWidget(plState);
    phbxlTop->addWidget(plDirIndividual);
    phbxlTop->addWidget(plDirEntitie);

    plDirIndividual->hide();
    plDirEntitie->hide();

    pgbTop->setLayout(phbxlTop);

    //pgbMedium
    QHBoxLayout  *phbxMedium = new QHBoxLayout();
    QStringList lst;
    lst << "Фамилия" << "Имя" << "Отчество"<<"Номер телефона"<<"Почта"<<"Описание"<<"Статус";
    ptable= new QTableView();
    //ptable->setHorizontalHeaderLabels(lst);

    ppbIndividuals = new QPushButton (tr("Физические лица"));
    ppbLegalEntities = new QPushButton (tr("Юридические лица"));

    phbxMedium->addWidget(ptable);
    phbxMedium->addWidget(ppbIndividuals);
    phbxMedium->addWidget(ppbLegalEntities);

    pgbMedium->setLayout(phbxMedium);

    ptable->hide();

    //pgbLower
    QHBoxLayout  *phbxlLower = new QHBoxLayout();

    QGroupBox *pgbSearch = new QGroupBox();

    QPushButton *ppbAddrecord = new QPushButton (tr("Добавить запись"));
    QPushButton *ppbEditrecord = new QPushButton (tr("Редактировать запись"));
    QPushButton *ppbDeleterecord = new QPushButton (tr("Удалить запись"));

    QVBoxLayout  *pvbxlEditing = new QVBoxLayout();

    pvbxlEditing->addWidget(ppbAddrecord);
    pvbxlEditing->addWidget(ppbEditrecord);
    pvbxlEditing->addWidget(ppbDeleterecord);

    phbxlLower->addLayout(pvbxlEditing);

    QHBoxLayout  *phbxSearch = new QHBoxLayout();

    QVBoxLayout  *pvbxlSearchRadioButton = new QVBoxLayout();
    QVBoxLayout  *pvbxlSearchInput = new QVBoxLayout();

    QRadioButton *prbname = new QRadioButton (tr("По имени"));
    QRadioButton *prbsurname = new QRadioButton (tr("По фамилии"));
    QRadioButton *prbnumber = new QRadioButton (tr("По номеру телефона"));

    pvbxlSearchRadioButton->addWidget(prbname);
    pvbxlSearchRadioButton->addWidget(prbsurname);
    pvbxlSearchRadioButton->addWidget(prbnumber);

    QLabel *plinput= new QLabel(tr("Введите критерий поиска"));
    plename = new QLineEdit();
    QPushButton *ppbsearch = new QPushButton (tr("Искать"));
    QPushButton *ppbbshow = new QPushButton (tr("Показать все записи"));

    QHBoxLayout  *phbxSearchInput = new QHBoxLayout();

    phbxSearchInput->addWidget(ppbsearch);
    phbxSearchInput->addWidget(ppbbshow);

    pvbxlSearchInput->addWidget(plinput);
    pvbxlSearchInput->addWidget(plename);
    pvbxlSearchInput->addLayout(phbxSearchInput);

    phbxSearch->addLayout(pvbxlSearchRadioButton);
    phbxSearch->addLayout(pvbxlSearchInput);

    pgbSearch->setLayout(phbxSearch);
    phbxlLower->addWidget(pgbSearch);

    QPushButton *ppbbexit = new QPushButton (tr("Выход"));
    phbxlLower->addWidget(ppbbexit);

    pgbLower->setLayout(phbxlLower);

    pgbLower->hide();

    setLayout(pvbxlMain);

    connect(ppbAddrecord,SIGNAL(clicked()),SLOT(AddRecord()));
    connect(ppbEditrecord,SIGNAL(clicked()),SLOT(EditRecord()));
    connect(ppbDeleterecord,SIGNAL(clicked()),SLOT(DeleteRecord()));
    connect(prbname,SIGNAL(clicked()),SLOT(SortName()));
    connect(prbsurname,SIGNAL(clicked()),SLOT(SortSurname()));
    connect(prbnumber,SIGNAL(clicked()),SLOT(SortNumber()));
    connect(ppbsearch,SIGNAL(clicked()),SLOT(Search()));
    connect(ppbbshow,SIGNAL(clicked()),SLOT(Show()));
    connect(ppbbexit,SIGNAL(clicked()),SLOT(Exit()));
    connect(ppbIndividuals,SIGNAL(clicked()),SLOT(OpenIndividuals()));
    connect(ppbLegalEntities,SIGNAL(clicked()),SLOT(OpenLegalEntities()));

    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("C:/Users/d.andronychev/study/Qt/PhoneBookV2/db/PhoneRecordIndividuals.db");
    if(!db.open())
        qDebug()<< "Ошибка при открытии базы данных";
    modeldb= new QSqlTableModel(this,db);
    modeldb->setTable("Records");
    modeldb->select();
    ptable->setModel(modeldb);

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::CreateMenu(QWidget *parent)
{
    QMenuBar *menuBar= new QMenuBar(this);
    QMenu * pmDirIndividual = menuBar->addMenu(tr("Справочник физических лиц"));
    QMenu * paSearchRecord = new QMenu(tr("Поиск"));
    QMenu * paDisplayRecord = new QMenu(tr("Отобразить все записи"));
    QMenu * pmDirEntitie= menuBar->addMenu(tr("Справочник юридических лиц"));
    QMenu * paSearchRecordEntitie = new QMenu(tr("Поиск"));
    QMenu * paDisplayRecordEntitie = new QMenu(tr("Отобразить все записи"));
    QAction * paExit = menuBar->addAction(tr("Выход"));

    menuBar->show();
    connect(paExit,SIGNAL(triggered()),SLOT(Exit()));

    QAction *paAddRecord = new QAction(tr("Добавить запись"), this);
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

    connect(paAddRecord,SIGNAL(triggered()),SLOT(AddRecordIndividuals()));
    connect(paEditRecord,SIGNAL(triggered()),SLOT(EditRecordIndividuals()));
    connect(paDeleteRecord,SIGNAL(triggered()),SLOT(DeleteRecordIndividuals()));
    connect(paSearchRecordName,SIGNAL(triggered()),SLOT(SearchRecordNameIndividuals()));
    connect(paSearchRecordSurname,SIGNAL(triggered()),SLOT(SearchRecordSurnameIndividuals()));
    connect(paSearchRecordNumber,SIGNAL(triggered()),SLOT(SearchRecordNumberIndividuals()));
    connect(paDisplayRecordList,SIGNAL(triggered()),SLOT(DisplayRecordListIndividuals()));
    connect(paSearcheRecordMap,SIGNAL(triggered()),SLOT(SearcheRecordMapIndividuals()));

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
}





void PhoneBook::AddRecordIndividuals()
{
    formAddIndividuals = new FormAddIndividuals(-1);
    formAddIndividuals->show();
    //delete formAddIndividuals;
}

void PhoneBook::EditRecordIndividuals()
{
    formAddIndividuals = new FormAddIndividuals(0);
    formAddIndividuals->show();
    //delete formAddIndividuals;
}

void PhoneBook::DeleteRecordIndividuals()
{
    formAddIndividuals = new FormAddIndividuals(1);
    formAddIndividuals->show();
    //delete formAddIndividuals;
}

void PhoneBook::SearchRecordNameIndividuals()
{

}

void PhoneBook::SearchRecordSurnameIndividuals()
{

}

void PhoneBook::SearchRecordNumberIndividuals()
{

}

void PhoneBook::DisplayRecordListIndividuals()
{

}

void PhoneBook::SearcheRecordMapIndividuals()
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

void PhoneBook::AddRecord()
{
    if(plDirIndividual->isVisible())
        AddRecordIndividuals();
    else
        AddRecordEntitie();
}

void PhoneBook::EditRecord()
{
    if(plDirIndividual->isVisible())
        EditRecordIndividuals();
    else
       EditRecordEntitie();
}

void PhoneBook::DeleteRecord()
{
    if(plDirIndividual->isVisible())
        DeleteRecordIndividuals();
    else
        DeleteRecordEntitie();
}

void PhoneBook::SortName()
{

}

void PhoneBook::SortSurname()
{

}

void PhoneBook::SortNumber()
{

}

void PhoneBook::Search()
{

}

void PhoneBook::Show()
{

}

void PhoneBook::OpenIndividuals()
{
    pgbLower->show();
    plDirIndividual->show();
    plState->hide();
    plDirEntitie->hide();
    ppbIndividuals->hide();
    ppbLegalEntities->hide();
    ptable->show();
}

void PhoneBook::OpenLegalEntities()
{
    pgbLower->show();
    plDirIndividual->hide();
    plState->hide();
    plDirEntitie->show();
    ppbIndividuals->hide();
    ppbLegalEntities->hide();
    ptable->show();
}

