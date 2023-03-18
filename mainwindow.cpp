#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "filehandler.h"
#include "food.h"
#include "helper.h"
#include <QDesktopServices>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;
using namespace helper;

QString text;
QAbstractButton* checkedButton;
map<string, bool> allergies;
int minutes = 0;
string path = "..//cs4076//recipes//";

// create inline method here

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui -> setupUi(this);

    // Algint text in the labels to center
    ui -> timeDisplay -> setAlignment(Qt::AlignCenter);
    ui -> difficultyLabel -> setAlignment(Qt::AlignCenter);
    ui -> allergyLabel -> setAlignment(Qt::AlignCenter);

    // Default tick the radio button
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

    // Pre-processing data
    fileHandler data;
    data.readFile(path + "data.data");

//    Food pizza("Pizza", 3, 80, "m", "m", "m");

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

    if(minutes == 0){
        minutes = INT_MAX;
    }
    // We have value of slider, allergies, and difficulty

//    cout << checkedDiff.toStdString() << endl;
//    for(itr = allergies.begin(); itr != allergies.end(); itr++){
//        cout << "Key = " << itr -> first << ", Value = " << itr -> second << endl;
//    }

//    cout << minutes << endl;

    cout << endl;
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
//    text = "None";
    QString hour = QString::number(value / 60);
    QString min = QString::number(value % 60);
    QString time = hour + ":" + min;

    text = time + " Hour";

    if(value / 60 == 0 && value % 60 == 0) text = "No Preference";

    ui -> timeDisplay -> setText(text);

    minutes = value;
}
