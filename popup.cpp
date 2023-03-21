#include "popup.h"
#include "ui_popup.h"

Popup::Popup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Popup)
{
    ui->setupUi(this);
//    displayMethod("H");
}

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

