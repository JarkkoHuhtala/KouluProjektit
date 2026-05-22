#include "message.h"
#include "message_window.ui"

message::message(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::message)
{
    ui->setupUi(this);
}
