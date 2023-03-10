#ifndef POPUPDIALOGUE_H
#define POPUPDIALOGUE_H

#include <QDialog>

namespace Ui {
class PopupDialogue;
}

class PopupDialogue : public QDialog
{
    Q_OBJECT

public:
    explicit PopupDialogue(QWidget *parent = nullptr);
    ~PopupDialogue();

private:
    Ui::PopupDialogue *ui;
};

#endif // POPUPDIALOGUE_H
