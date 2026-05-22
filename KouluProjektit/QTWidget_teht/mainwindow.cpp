#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <qstring.h>

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->N0, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N1, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N2, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N3, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N4, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N5, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N6, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N7, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N8, &QPushButton::clicked, this, &MainWindow::numbersHandler);
    connect(ui->N9, &QPushButton::clicked, this, &MainWindow::numbersHandler);

    connect(ui->add, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->sub, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->mul, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);
    connect(ui->div, &QPushButton::clicked, this, &MainWindow::addSubMulDivClickHandler);

    connect(ui->enter, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
    connect(ui->clear, &QPushButton::clicked, this, &MainWindow::clearAndEnterClickHandler);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::clearAndEnterClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if(button == ui->enter){
        switch(operand){

        case 0:{
            sum = number1.toFloat() + number2.toFloat();
            ui->result->setText(QString::number(sum));
            break;}
        case 1:{
            sum = number1.toFloat() - number2.toFloat();
            ui->result->setText(QString::number(sum));
            break;}
        case 2:{
            sum = number1.toFloat() * number2.toFloat();
            ui->result->setText(QString::number(sum));
            break;}
        case 3:{
            sum = number1.toFloat() / number2.toFloat();
            ui->result->setText(QString::number(sum));
            break;}
        }
    }else{
        resetLineEdits();
    }
}

void MainWindow::addSubMulDivClickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    state = true;
    if(button == ui->add){
        operand = 0;
    }else if(button == ui->sub){
        operand = 1;
    }else if(button == ui->mul){
        operand = 2;
    }else{
        operand = 3;
    }
}

void MainWindow::numbersHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());
    if(state == false){
        QString text = ui->Num1->text();
        ui->Num1->setText(text+button->text());
        number1 = text + button->text();
    }else{
        QString text2 = ui->Num2->text();
        ui->Num2->setText(text2+button->text());
        number2 = text2 + button->text();
    }
}

void MainWindow::resetLineEdits()
{
    ui->Num1->setText("");
    ui->Num2->setText("");
    ui->result->setText("");
    number1 = 0;
    number2 = 0;
    operand = 5;
    sum = 0;
    state = false;
}
