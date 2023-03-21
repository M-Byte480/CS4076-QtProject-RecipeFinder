#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "filehandler.h"
#include "food.h"
#include "helper.h"
#include <QDesktopServices>
#include <forward_list>
#include <stdlib.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "consumable.h"
#include "QListWidget"
#include "popup.h"

using namespace std;
using namespace helper;

QString text;
QAbstractButton* checkedButton;
int minutes = 0;
string path = "..//cs4076//recipes//";
forward_list<Food> foodList;

// create inline method here

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui -> setupUi(this);
//    ui -> resultList -> addItem("Test");
    // Algint text in the labels to center
    ui -> timeDisplay -> setAlignment(Qt::AlignCenter);
    ui -> difficultyLabel -> setAlignment(Qt::AlignCenter);
    ui -> allergyLabel -> setAlignment(Qt::AlignCenter);

    // Default tick the radio button
    ui -> difficultyAny -> setChecked(true);

    //
    // Pre-processing data
    fileHandler data;
    data.readFile(path + "data.data");

    // Initialize the foods
    int numberOfFood;
    numberOfFood = data.getData().capacity() - 1;


    cout << "Number of food: " << numberOfFood << endl;
    int tracker = 1;
    try{
        for(tracker = 1 ; tracker <  data.getData().capacity(); tracker++ ){
            string line = data.getData().at(tracker);

            string name; string fileName; int difficulty; int numberOfIngredients; int time;
            string listOfIngredients; string listOfAllergies; string listOfMethods;

            vector<string> splitLine = split(line, ',');
            //        for(string s : splitLine){
            //            cout << s << endl;
            //        }
            fileName = splitLine.at(0);
            name = split(fileName, '.').at(0);
            cout <<"Difficulty read: " << splitLine.at(1) << endl;
            difficulty = stoi(splitLine.at(1));
            cout << "Difficulty Caste; " << difficulty << endl;
            //        cout << "Pizza Dif " << difficulty << endl;
            time = stoi(splitLine.at(2));

            numberOfIngredients = stoi(split(splitLine.at(3), ';').at(0));
            listOfIngredients = split(splitLine.at(3),';').at(1);

            listOfAllergies = split(splitLine.at(4), ';').at(1);
            fileHandler recipe(path + fileName);
            listOfMethods = recipe.getDataToString();

            //        cout << listOfMethods << endl;
            Food newFood(name,
                         difficulty,
                         numberOfIngredients,
                         time,
                         listOfIngredients,
                         listOfAllergies,
                         listOfMethods);

//            cout << "Pizza difficulty : " << newFood.getDifficulty() << endl;
            //        newFood.setTime(time);
            //        Food temp;

            foodList.push_front(newFood);
            //        delete newFood;
        }
    }catch(exception& e){
        cout << e.what() << endl;
    }
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



    forward_list<Food>::iterator it;

    for(it = foodList.begin(); it != foodList.end(); it++){
        cout << it->getName() << endl;
        cout << it->getTime() << endl;
    }
    // Check for radio buttons
    QAbstractButton* buttons[] = {
        ui -> difficultyAny,
        ui -> difficultyEasy,
        ui -> difficultyMedium,
        ui -> difficultyHard
    } ;

    QAbstractButton* checkedButton;

    for(int i = 0; i < 4; i++){
        if(buttons[i]->isChecked()){
            checkedButton = buttons[i];
        }
    }

    QString checkedDiff = checkedButton -> objectName();

    // Check for tickedBox
    QAbstractButton* buttonBox[] = {
        ui -> fish,
        ui -> milk,
        ui -> nuts,
        ui -> wheat
    };
    map<string, bool> allergies;
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
    map<string, bool>::iterator iterator;
    ui -> resultList -> clear();
    string diff[3] = {"difficultyEasy",
                      "difficultyMedium",
                      "difficultyHard"};
    for(Food f : foodList){
        bool bad = false;
        bool timeTakes = f.getTime() <= minutes;
        string difficult = checkedDiff.toStdString();
        cout << "\n\n DIFFICULTY RETURNED :" << f.getDifficulty() << endl;
        bool dif = (difficult == "difficultyAny" || diff[f.getDifficulty() - 1] == difficult);
        if(timeTakes && dif){
            Allergy* allergy = f.getAllergies();
            string al = *f.getAllergiesString();

            for(int i = 0; i < f.getNoAllergies(); i++){
                string temp = (allergy + i)->toString();
                iterator = allergies.find(temp);
                if(iterator -> second == true){
                    bad = true;
                    break;
                }
            }
            if(!bad){
                QString qstr = QString::fromStdString(f.toString());
                ui -> resultList -> addItem( qstr );
            }
        }
    }
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

void MainWindow::on_resultList_itemDoubleClicked(QListWidgetItem *item)
{
    cout << "Clicked" << endl;
    this->hide();
    Popup *popupWindow = new Popup();
    popupWindow -> setModal(true);

    connect(this, SIGNAL(sendMethod(QString)), popupWindow, SLOT(displayMethod(QString)));
    emit sendMethod("Hello World, by Milan");

    popupWindow -> exec();
    this->show();
}

