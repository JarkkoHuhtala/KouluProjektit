#include "message_window.h"
#include "ui_message_window.h"
#include <random>
#include <QDebug>

message_window::message_window(MainWindow *window, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::message_window)
    , pWindow(window)
{
    ui->setupUi(this);
    timer = new QTimer(this);
    connect(ui->goBack, &QPushButton::clicked, this, &message_window::buttonHandler);
    connect(ui->newMessage, &QPushButton::clicked, this, &message_window::buttonHandler);
    connect(timer, &QTimer::timeout, this, &message_window::updateConfetti);
    ui->messagesviewed->setMinimum(0);
    ui->messagesviewed->setMaximum(91);
    std::random_device ran;
    std::mt19937 rng(ran());
    std::uniform_int_distribution<std::mt19937::result_type> rand(0, 91);

    int num = rand(rng);
    ui->actualMessage->setText(messages[num]);
    ui->whoSent->setText(whoSent[num]);
    if(num == pastNumbers.contains(QString::number(num))){
        return;
    }else{
        pastNumbers.append(QString::number(num));
        ui->messagesviewed->setValue(std::size(pastNumbers));
    }
}

message_window::~message_window()
{
    delete ui;
}

void message_window::buttonHandler()
{
    QPushButton* pushButton=qobject_cast<QPushButton*>(sender());
    if(pushButton->objectName()=="goBack"){
        delete this;
    }else{
        std::random_device ran;
        std::mt19937 rng(ran());
        std::uniform_int_distribution<std::mt19937::result_type> rand(0, 91);
        int num = rand(rng);

        while(bool check = pastNumbers.contains(QString::number(num)) == true){
            std::random_device ran;
            std::mt19937 rng(ran());
            std::uniform_int_distribution<std::mt19937::result_type> rand(0, 91);
            num = rand(rng);
            check = pastNumbers.contains(QString::number(num));

            if(std::size(pastNumbers) >= 92){
                num = rand(rng);
                break;
            }
        }

        ui->actualMessage->setText(messages[num]);
        ui->whoSent->setText(whoSent[num]);
        if(std::size(pastNumbers) >= 92){
            return;
        }else{
            pastNumbers.append(QString::number(num));
            ui->messagesviewed->setValue(std::size(pastNumbers));
            //qDebug()<<std::size(pastNumbers); // Debug code.
            if(std::size(pastNumbers) == 91){ // Start confetti show at 100% progress bar.
                startConfetti();
            }
        }
    }
}

void message_window::startConfetti()
{
    timer->start(16);
    confettiVect.clear();
    for(int i = 0; i < 200; ++i){
        confettiVect.append(confettiList{
            QRandomGenerator::global()->bounded(width()),
            -QRandomGenerator::global()->bounded(1000),
            QRandomGenerator::global()->bounded(6) + 2,
            QRandomGenerator::global()->bounded(4) + 1,
            2,
            QColor(QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256), QRandomGenerator::global()->bounded(256))
        });
    }
}

void message_window::updateConfetti()
{
    for(auto &piece : confettiVect){
        piece.y += piece.speed;
        if(piece.y > height()){
            piece.y = -10;
            piece.x = QRandomGenerator::global()->bounded(width()) - 1;
        }
    }
    update();
}

void message_window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    for(const auto &piece : confettiVect){
        painter.setBrush(piece.color);
        painter.drawRect(piece.x, piece.y, piece.width, piece.height);
    }
}
