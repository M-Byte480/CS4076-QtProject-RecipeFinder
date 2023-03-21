#ifndef POPUP_H
#define POPUP_H

#include <QDialog>

namespace Ui {
class Popup;
}

class Popup : public QDialog
{
    Q_OBJECT

public:
    explicit Popup(QWidget *parent = nullptr);
    ~Popup();

private:
    Ui::Popup *ui;

private slots:
    void displayMethod(QString);
    void on_exitButton_clicked();
};

#endif // POPUP_H
