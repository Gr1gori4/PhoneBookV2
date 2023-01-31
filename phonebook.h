#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include <QMainWindow>
#include <QMenuBar>
#include <QVBoxLayout>
#include <QAction>
#include <QMessageBox>
#include <QGroupBox>
#include <QFile>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QLineEdit>
#include <QTableWidget>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QTableView>
#include "formaddindividuals.h"

namespace Ui {
class PhoneBook;
}

class PhoneBook : public QWidget
{
    Q_OBJECT

public:
    explicit PhoneBook(QWidget *parent = nullptr);
    ~PhoneBook();

private:
    Ui::PhoneBook *ui;
    QGroupBox *pgbLower;
    QLabel *plDirIndividual;
    QLabel *plState;
    QLabel *plDirEntitie;
    QPushButton *ppbIndividuals;
    QPushButton *ppbLegalEntities;
    QTableView *ptable;
    QLineEdit* plename;

    QSqlDatabase db;
    QSqlTableModel *modeldb;

    void CreateMenu(QWidget *parent);

    FormAddIndividuals *formAddIndividuals;


private slots:
    void AddRecordIndividuals();
    void EditRecordIndividuals();
    void DeleteRecordIndividuals();
    void SearchRecordNameIndividuals();
    void SearchRecordSurnameIndividuals();
    void SearchRecordNumberIndividuals();
    void DisplayRecordListIndividuals();
    void SearcheRecordMapIndividuals();

    void AddRecordEntitie();
    void EditRecordEntitie();
    void DeleteRecordEntitie();
    void SearchRecordTitle();
    void SearchRecordDirector();
    void SearchRecordOGRN();
    void SearchRecordBranch();
    void DisplayRecordListEntitie();
    void SearcheRecordMapEntitie();

    void Exit();

    void AddRecord();
    void EditRecord();
    void DeleteRecord();
    void SortName();
    void SortSurname();
    void SortNumber();
    void Search();
    void Show();
    void OpenIndividuals();
    void OpenLegalEntities();


};

#endif // PHONEBOOK_H
