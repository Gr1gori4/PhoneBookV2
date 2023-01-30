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

namespace Ui {
class PhoneBook;
}

class PhoneBook : public QMainWindow
{
    Q_OBJECT

public:
    explicit PhoneBook(QWidget *parent = nullptr);
    ~PhoneBook();

private:
    Ui::PhoneBook *ui;
    //void СreatureMenuDirIndividual();

private slots:
    void AddRecord();
    void EditRecord();
    void DeleteRecord();
    void SearchRecordName();
    void SearchRecordSurname();
    void SearchRecordNumber();
    void DisplayRecordList();
    void SearcheRecordMap();

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

};

#endif // PHONEBOOK_H
