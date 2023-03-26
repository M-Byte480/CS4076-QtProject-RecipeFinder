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
#include <QBoxLayout>
#include "QListWidget"
#include "popup.h"
#include "fileinputreader.h"

using namespace std;
using namespace helper;

// Global variables
QString text;
QAbstractButton* checkedButton;
int minutes = 0;
string path = "..//cs4076//recipes//";
forward_list<Food> foodList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

//    QBoxLayout qBox(QBoxLayout::TopToBottom);
//    qBox.addItem(ui ->milk);

    // Align text in the labels to their relative center
    ui -> timeDisplay -> setAlignment(Qt::AlignCenter);
    ui -> difficultyLabel -> setAlignment(Qt::AlignCenter);
    ui -> allergyLabel -> setAlignment(Qt::AlignCenter);

    // Default radio button selected
    ui -> difficultyAny -> setChecked(true);

    // Pre-data handling
    try{
        fileInputReader data;
        data.readFile(path + "data.data");
        print("Now reading: "); data.printName();

        // We will now iterate through the file and intilize the foods

        int tracker = 1; // First line of the file is the file template
        for( ; tracker <  data.getFileLine().capacity(); tracker++ ){
            string line = data.getFileLine().at(tracker);

            string name; string fileName;
            string listOfIngredients; string listOfAllergies; string listOfMethods;
            int difficulty; int numberOfIngredients; int time;

            vector<string> splitLine = split(line, ',');

            fileName =  splitLine.at(0);
            name = split(fileName, '.').at(0);

            difficulty = stoi(splitLine.at(1));
            time       = stoi(splitLine.at(2));

            numberOfIngredients = stoi(split(splitLine.at(3), ';').at(0));
            listOfIngredients =        split(splitLine.at(3), ';').at(1);

            listOfAllergies =          split(splitLine.at(4), ';').at(1);

            fileInputReader recipe(path + fileName);
            listOfMethods = recipe.dataToFormattedString();

            Food newFood(name,
                         difficulty,
                         numberOfIngredients,
                         time,
                         listOfIngredients,
                         listOfAllergies,
                         listOfMethods);

            foodList.push_front(newFood);
        }
    }catch(myException& e){
        cout << e.what() << endl;
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
    QString link = "https://github.com/M-Byte480/CS4076-QtProject-RecipeFinder";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_actionApplication_triggered()
{
    QString link = "https://www.linkedin.com/in/milan-kovacs-cs/?originalSubdomain=ie";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_searchButton_clicked()
{
    vector<Food> validFood;

    string searchBar = ui -> userInput -> displayText()
                      .QString::toStdString(); // We get the user search input

    searchBar = trim(searchBar);
    // cout << searchBar << endl;


    forward_list<Food>::iterator it;

    for(it = foodList.begin(); it != foodList.end() ; it++){

        if( split( it->getName() , searchBar ).capacity() > 1 ){ // My own contains
//        if(it->getName().find(searchBar) != string::npos){ // Simplified
            validFood.push_back(*it);
        }
    }

    /* Prints out the name that is found up above
    {
        print("The capacity of Validfood: "); println(validFood.capacity());
        vector<Food>::iterator it;
        for(it = validFood.begin(); it != validFood.end(); it++){
            cout << it->getName() << endl;
        }
    }
    //*/

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

    QString checkedDifficulty = checkedButton -> objectName();

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

    for(Food f : validFood){
        bool bad = false;
        bool timeTakes = f.getTime() <= minutes;
        string difficult = checkedDifficulty.toStdString();
//        cout << "\n\n DIFFICULTY RETURNED :" << f.getDifficulty() << endl;
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
    QString hour = (value / 60 >= 10) ? QString::number(value / 60) : QString::fromStdString("0") + QString::number(value / 60);
    QString min = (value % 60 >= 10) ? QString::number(value % 60) : QString::fromStdString("0") + QString::number(value % 60);
    QString time = "<" + hour + ":" + min;

    text = time + " Hour";

    if(value / 60 == 0 && value % 60 == 0) text = "No Preference";

    ui -> timeDisplay -> setText(text);

    minutes = value;
}

void MainWindow::on_resultList_itemDoubleClicked(QListWidgetItem *item)
{
    this->hide();
    Popup *popupWindow = new Popup();
    popupWindow -> setModal(true);

    QString *method = new QString;
    string title = item -> text().toStdString();
//    cout << title.toStdString() << endl;
    forward_list<Food>::iterator ptr;
    for(ptr = foodList.begin(); ptr != foodList.end() ; ptr++){
        if(ptr->getName() == title){
            *method = QString::fromStdString(ptr->getMethods());
        }
    }

    connect(this, SIGNAL(sendMethod(QString)), popupWindow, SLOT(displayMethod(QString)));
    emit sendMethod(*method);

    popupWindow -> exec();
    this->show();
    delete method;
}


void MainWindow::on_dropDownBox_clicked()
{
    string file = "tmp";
    try{
//        println("Looking for " + f.getName()) ; cout << endl;
        fileInputReader f(file);
    }catch(myException& e){
        cout << e.what() << endl;
        cout << file << endl;
    }
}


void MainWindow::on_userInput_returnPressed()
{
    MainWindow::on_searchButton_clicked();
}

