#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <string>
#include <iostream>
#include <QSqlTableModel>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnShow_clicked()
{
    const QString inputVal = ui->leReceipt->text();
    // ui->textEdit->setText(inputVal);

    QSqlTableModel *model = new QSqlTableModel;
    model->setTable("employee");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, tr("Age"));
    model->setHeaderData(3, Qt::Horizontal, tr("Married"));

    qDebug() << "addRecord";
    QSqlRecord newRecord = model->record();
    newRecord.setValue("Id", 0);
    newRecord.setValue("Name", "Name");
    newRecord.setValue("Age", 0);
    newRecord.setValue("Married", 0);
    qDebug() << "Row Count: " << model->rowCount();

    if (model->insertRecord(model->rowCount(), newRecord)) {
        qDebug() << "New record inserted";
    }

    model->insertRows(2,1);
    model->setData(model->index(0,2), "temp");

    QTableView *view = new QTableView;
    view->setModel(model);
    // view->hideColumn(0); // don't show the ID
    ui->tableView->setModel(model);
}
