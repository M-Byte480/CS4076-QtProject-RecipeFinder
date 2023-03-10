#ifndef POPUPDIALOGUE_H
#define POPUPDIALOGUE_H

#include "qabstractbutton.h"
#include <QDialog>

namespace Ui {
class PopupDialogue;
}

class PopupDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit PopupDialogue(QWidget *parent = nullptr);
    PopupDialogue(QAbstractButton* checkedRadio);
    ~PopupDialogue();

private slots:
    void on_cancelButton_clicked();

    void on_applyButton_clicked();

private:
    Ui::PopupDialogue *ui;
};

#endif // POPUPDIALOGUE_H
