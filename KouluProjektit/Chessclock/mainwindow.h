#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTimer>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void timeout();

private slots:
    void updateProgressBar();
    void setGameInfo();
    void clickHandler();

private:
    Ui::MainWindow *ui;
    float player1Time;
    float player2Time;
    short currentPlayer = 1;
    float gameTime;
    int counter = 0; //Used to wait 3 seconds before dispaying "New game via start button"
    bool flag = false; //Used to see when game ends

    QTimer * timer;
};
#endif // MAINWINDOW_H
