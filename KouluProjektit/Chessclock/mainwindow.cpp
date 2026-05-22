#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer(this);

    connect(ui->startgame, &QPushButton::clicked, this, &MainWindow::clickHandler);
    connect(ui->stopgame, &QPushButton::clicked, this, &MainWindow::clickHandler);
    connect(ui->player1Button, &QPushButton::clicked, this, &MainWindow::clickHandler);
    connect(ui->player2Button, &QPushButton::clicked, this, &MainWindow::clickHandler);
    connect(timer, &QTimer::timeout, this, &MainWindow::timeout);
    connect(ui->time_120, &QPushButton::clicked, this, &MainWindow::clickHandler);
    connect(ui->time_5, &QPushButton::clicked, this, &MainWindow::clickHandler);

    ui->player1Bar->setValue(0);
    ui->player2Bar->setValue(0);
    ui->gameStatus->setText("Select playtime and press start game");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeout()
{
    if(currentPlayer == 1){
        player1Time -= 1;
    }else{
        player2Time -= 1;
    }
    updateProgressBar();
}

void MainWindow::updateProgressBar()
{
    int progress1 = (player1Time / gameTime) * 100;
    int progress2 = (player2Time / gameTime) * 100;
    ui->player1Bar->setValue(progress1);
    ui->player2Bar->setValue(progress2);

    setGameInfo();
}

void MainWindow::setGameInfo()
{
    if(player1Time <= 0){
        flag = true;
        ui->gameStatus->setText("Player 2 WON!");
        counter++;
    }else if(player2Time <= 0){
        flag = true;
        ui->gameStatus->setText("Player 1 WON!");
        counter++;
    }

    if(flag == false){
        ui->gameStatus->setText("Game ongoing");
    }

    if(counter > 3){
        ui->gameStatus->setText("Select time and start a new game via start button");
        timer->stop();
    }
}

void MainWindow::clickHandler()
{
    QPushButton * button = qobject_cast<QPushButton*>(sender());

    if(button == ui->startgame){
        timer->start(1000);
        flag = false;
        counter = 0;
    }else if(button == ui->stopgame){
        timer->stop();
    }else if(button == ui->player1Button){
        currentPlayer = 2;
    }else if(button == ui->player2Button){
        currentPlayer = 1;
    }else if(button == ui->time_120){
        gameTime = 120;
        player1Time = gameTime;
        player2Time = gameTime;
        updateProgressBar();
    }else if(button == ui->time_5){
        gameTime = 300;
        player1Time = gameTime;
        player2Time = gameTime;
        updateProgressBar();
    }
}
