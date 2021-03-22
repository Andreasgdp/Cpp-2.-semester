#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <string>
#include <iostream>

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
    // load file

    Receipt r;

    ui->textEdit->setText(r.getText().c_str());
}
