#include "popupdialogue.h"
#include "ui_popupdialogue.h"

PopupDialogue::PopupDialogue(QAbstractButton* checkedRadio){
     this->exec();
}

PopupDialogue::PopupDialogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PopupDialogue)
{
    ui -> setupUi(this);
    ui -> difficultyLabel -> setAlignment(Qt::AlignCenter);
    ui -> allergyLabel -> setAlignment(Qt::AlignCenter);
    ui -> anyDifficulty -> setChecked(true);

}

PopupDialogue::~PopupDialogue()
{
    delete ui;
}

void PopupDialogue::on_cancelButton_clicked()
{
    this -> hide();
    PopupDialogue::close();
}



