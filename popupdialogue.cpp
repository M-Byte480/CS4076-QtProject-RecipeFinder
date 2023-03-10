#include "popupdialogue.h"
#include "ui_popupdialogue.h"

PopupDialogue::PopupDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupDialogue)
{
    ui->setupUi(this);
}

PopupDialogue::~PopupDialogue()
{
    delete ui;
}
