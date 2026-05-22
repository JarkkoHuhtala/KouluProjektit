#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

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

private slots:
    void clearAndEnterClickHandler();
    void addSubMulDivClickHandler();
    void numbersHandler();
    void resetLineEdits();


private:
    Ui::MainWindow *ui;
    QString number1;
    QString number2;
    float sum = 0;
    bool state = false;
    short operand;
};
#endif // MAINWINDOW_H
