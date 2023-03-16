#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDesktopServices>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

QString text;
QAbstractButton* checkedButton;
map<string, bool> allergies;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    ui -> timeDisplay -> setAlignment(Qt::AlignCenter);
    ui -> difficultyLabel -> setAlignment(Qt::AlignCenter);
    ui -> allergyLabel -> setAlignment(Qt::AlignCenter);
    ui -> difficultyAny -> setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionQuit_triggered()
{
    QApplication::quit();
}


void MainWindow::on_actionLinkedIn_triggered()
{
    QString link = "https://www.linkedin.com/in/milan-kovacs-cs/?originalSubdomain=ie";
    QDesktopServices::openUrl(QUrl(link));
}


void MainWindow::on_actionGitHub_triggered()
{
    QString link = "https://github.com/M-Byte480/CS4076-Project/tree/main";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_searchButton_clicked()
{
    // Check for radio buttons
    QAbstractButton* buttons[] = {
                                 ui -> difficultyAny,
                                 ui -> difficultyHard,
                                 ui -> difficultyMedium,
                                 ui -> difficultyEasy } ;

    QAbstractButton* checkedButton;

    for(int i = 0; i < 4; i++){
        if(buttons[i]->isChecked()){
            checkedButton = buttons[i];
        }
    }

    QString checkedDiff = checkedButton -> objectName();
    cout << checkedDiff.toStdString() << endl;

    // Check for tickedBox
    QAbstractButton* buttonBox[] = {
        ui -> allergyFish,
        ui -> allergyMilk,
        ui -> allergyNuts,
        ui -> allergyWheat
    };

    map<string, bool>::iterator itr;

    for (int i = 0; i < sizeof(buttonBox) / sizeof(QAbstractButton*); ++i) {

        allergies.insert(pair<string, bool> ((buttonBox[i] -> objectName()).toStdString() ,false));

        if(buttonBox[i]->isChecked()){
            itr = allergies.find(buttonBox[i] -> objectName().toStdString());
            if(itr != allergies.end())
                itr -> second = true;
        }
    }

    for(itr = allergies.begin(); itr != allergies.end(); itr++){
        cout << "Key = " << itr -> first << ", Value = " << itr -> second << endl;
    }
}

void MainWindow::on_timeSlider_sliderMoved(int position)
{

    if(position <= 0){
        text = "None";
    }else{

    }
}


void MainWindow::on_timeSlider_valueChanged(int value)
{
    text = "None";
    QString hour = QString::number(value / 60);
    QString min = QString::number(value % 60);
    QString time = hour + ":" + min;

    text = time + " Hour";

    if(value / 60 == 0 && value % 60 == 0) text = "No Preference";

    ui -> timeDisplay -> setText(text);
}
