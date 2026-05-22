#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "message_window.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->button, &QPushButton::clicked, this, &MainWindow::windowchange);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::windowchange()
{
    message_window * pMessage = new message_window(this);
    connect(pMessage, &message_window::destroyed, this, &MainWindow::childWindowDestroyed);
    pMessage->show();
    this->hide();
}

void MainWindow::childWindowDestroyed()
{
    this->show();
}
