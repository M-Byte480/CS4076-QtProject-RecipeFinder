#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "popupdialogue.h"
#include "qlistwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionQuit_triggered();

    void on_actionLinkedIn_triggered();

    void on_actionGitHub_triggered();

    void on_actionApplication_triggered();

    void on_searchButton_clicked();

    void on_timeSlider_valueChanged(int value);

    void on_resultList_itemDoubleClicked(QListWidgetItem *item);

    void on_dropDownBox_clicked();

    void on_userInput_returnPressed();

    void on_difficultyEasy_clicked();

    void on_difficultyMedium_clicked();

    void on_difficultyHard_clicked();

    void on_fish_stateChanged(int arg1);

    void on_milk_stateChanged(int arg1);

    void on_nuts_stateChanged(int arg1);

    void on_wheat_stateChanged(int arg1);

    void on_difficultyAny_clicked();

    void on_userInput_textChanged(const QString &arg1);


private:
    Ui::MainWindow *ui;

    // We send the data from one window to another using a signal
signals:
    void sendMethod(QString);
    void sendTitle(QString);
};
#endif // MAINWINDOW_H
