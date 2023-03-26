#include "popup.h"
#include "ui_popup.h"

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
}

// This function takes in a QString from the signal of mainwindow
void Popup::displayMethod(QString s){
    ui->textBrowser->setText(s);
}

Popup::~Popup()
{
    delete ui;
}

void Popup::on_exitButton_clicked()
{
    this->close();
}

