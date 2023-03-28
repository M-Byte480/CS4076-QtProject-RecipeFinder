#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "allergybitstruct.h"
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
#include "error.h"

using namespace std;
using namespace helper;

// Global variables
QString text;
QAbstractButton* checkedButton;
int minutes = 0;
string path = ".//recipes//";
forward_list<Food> foodList;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);

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
        for( int tracker = 1 ; tracker <  data.getFileLine().capacity(); tracker++ ){// First line of the file is the file template

            string name; string fileName;
            string listOfIngredients; string listOfAllergies; string listOfMethods;
            int difficulty; int numberOfIngredients; int time;

            string line = data.getFileLine().at(tracker); // We get the string of the database per line

            vector<string> splitLine = split(line, ','); // Split accordingly

            fileName =  splitLine.at(0);        // Now we follow the convention set out by me
            name = split(fileName, '.').at(0);

            difficulty = stoi(splitLine.at(1));  // stoi = string to int
            time       = stoi(splitLine.at(2));

            numberOfIngredients = stoi(split(splitLine.at(3), ';').at(0));
            listOfIngredients =        split(splitLine.at(3), ';').at(1);

            listOfAllergies =          split(splitLine.at(4), ';').at(1);

            fileInputReader recipe(path + fileName); // Now we find the file based on the fileName and the relative Path
            listOfMethods = recipe.dataToFormattedString();

            Food newFood(name,
                         difficulty,
                         numberOfIngredients,
                         time,
                         listOfIngredients,
                         listOfAllergies,
                         listOfMethods);

            foodList.push_front(newFood); // Copy constructor invoked
        }

        MainWindow::on_searchButton_clicked();
    }catch(myException& e){
        cout << e.what() << endl;
    }catch(exception& e){
        cout << e.what() << endl;
    }


//    println("Size of food: "); println(distance(foodList.begin(), foodList.end()));
}


// Search Button Event Listener
void MainWindow::on_searchButton_clicked()
{
    // Temporary Food Vector
    vector<Food> validFood;

    string searchBar = ui -> userInput -> displayText()
                      .QString::toStdString(); // We get the user search input

    searchBar = trim(searchBar); // Trim leading spaces

    // We will iterate through the linked List of type Food
    forward_list<Food>::iterator it;

    for(it = foodList.begin(); it != foodList.end() ; it++){

        if( split( it->getName() , searchBar ).capacity() > 1 ){    // My own contains vs
        // if(it->getName().find(searchBar) != string::npos){       // Simplified contains
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
    };

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

    AllergyBitStruct bitStructArr[] = {
        AllergyBitStruct::fish,
        AllergyBitStruct::milk,
        AllergyBitStruct::nuts,
        AllergyBitStruct::wheat
    };

    AllergyFlag allergyFlag;
    map<string, bool> allergies;

    map<string, bool>::iterator itr;

    // We create a map from string -> bool
    // For each allergy button selected
    for (int i = 0; i < sizeof(buttonBox) / sizeof(QAbstractButton*); ++i) {

        allergies.insert(pair<string, bool> ((buttonBox[i] -> objectName()).toStdString() ,false));

        if(buttonBox[i]->isChecked()){
            // Set flag accordingly
            allergyFlag .setFlag(buttonBox[i] -> objectName().toStdString());
            // Find the map key
            itr = allergies.find(buttonBox[i] -> objectName().toStdString());
            // Set the map value
            if(itr != allergies.end())
                itr -> second = true;
        }
    }

    if(minutes == 0){
        minutes = INT_MAX;
    }

    // We have value of slider, allergies, and difficulty

//    map<string, bool>::iterator iterator;

    ui -> resultList -> clear(); // Clear the list

    string diff[3] = {"difficultyEasy",
                      "difficultyMedium",
                      "difficultyHard"};


    // Iterate through each food to see if they meet the criteria
    for(Food f : validFood){
        bool bad = false; // Is food valid?

        bool timeTakes = f.getTime() <= minutes; // Time it takes less than slider
        string difficult = checkedDifficulty.toStdString(); // Radio button Selected
        bool dif = (difficult == "difficultyAny" || diff[f.getDifficulty() - 1] == difficult);

        // We check for the allergy if these criterias are met
        if(timeTakes && dif){
            // Return the pointer to the array
            Allergy* allergy = f.getAllergies();
            int iterations = f.getNoAllergies();
            for(int i = 0; i < iterations; i++){

                string temp = (allergy + i)->toString(); // Pointer arithmetic

                if(allergyFlag.hasFlag(temp)){
                    bad = true;
                    break;
                }

                /*iterator = allergies.find(temp);
                if(iterator -> second == true){
                    bad = true;
                    break;
                }//*/

            }

            // If good: Add it to the display list
            if(!bad)
            {
                QString qstr = QString::fromStdString(f.toString());
                ui -> resultList -> addItem( qstr );
            }
        }
    }
}

void MainWindow::on_timeSlider_valueChanged(int value)
{
    // We are checking for leading zeros
    QString hour = (value / 60 >= 10) ? QString::number(value / 60) :
                                        QString::fromStdString("0") + QString::number(value / 60);

    QString min =  (value % 60 >= 10) ? QString::number(value % 60) :
                                        QString::fromStdString("0") + QString::number(value % 60);

    QString time = "<" + hour + ":" + min;

    text = time + " Hour";

    if(value / 60 == 0 && value % 60 == 0) text = "No Preference";

    ui -> timeDisplay -> setText(text);

    // Global variable
    minutes = value;

    MainWindow::on_searchButton_clicked();

}

// When the list item is double clicked
void MainWindow::on_resultList_itemDoubleClicked(QListWidgetItem *item)
{
    this->hide();

    Popup *popupWindow = new Popup();
    popupWindow -> setModal(true); // Take full control

    QString *method = new QString;
    string title = item -> text().toStdString(); // Get the text written in the list element

    forward_list<Food>::iterator ptr; // Iterator through the linked list

    for(ptr = foodList.begin(); ptr != foodList.end() ; ptr++){
        // If the name of food matches the title, we are going to send its method to the other window
        if(ptr->getName() == title) {
            *method = QString::fromStdString(ptr->getMethods());
            *method = QString::fromStdString(!*ptr).append("Method : \n") + *method;
        }
    }

    // We create a connection between the two windows and send data through the sendMethod signal
    connect(this, SIGNAL(sendMethod(QString)), popupWindow, SLOT(displayMethod(QString)));
    connect(this, SIGNAL(sendTitle(QString)), popupWindow, SLOT(setTitle(QString)));
    emit sendTitle(QString::fromStdString(title));
    emit sendMethod(*method);

    popupWindow -> exec();

    this->show();
    delete method; // Memory management
}

// Demonstrate the exception handling
void MainWindow::on_dropDownBox_clicked()
{
    string file = "tmp";
    try{
        println("Looking for " + file) ; cout << endl;
        fileInputReader f(file);
    }catch(myException& e){
        cout << e.what() << endl;
        cout << file << endl;
        error* err = new error();
        err->exec();
    }
}

// When the enter key is pressed, act as if the search button was clicked.
void MainWindow::on_userInput_returnPressed()
{
    MainWindow::on_searchButton_clicked();
}


MainWindow::~MainWindow()
{
    delete ui;
}

// Dropdown buttons from the header bar
void MainWindow::on_actionQuit_triggered(){
    QApplication::quit();
}

void MainWindow::on_actionLinkedIn_triggered(){
    QString link = "https://www.linkedin.com/in/milan-kovacs-cs/?originalSubdomain=ie";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_actionGitHub_triggered(){
    QString link = "https://github.com/M-Byte480/CS4076-QtProject-RecipeFinder";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_actionApplication_triggered(){
    QString link = "https://www.linkedin.com/in/milan-kovacs-cs/?originalSubdomain=ie";
    QDesktopServices::openUrl(QUrl(link));
}

void MainWindow::on_difficultyEasy_clicked()
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_difficultyMedium_clicked()
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_difficultyHard_clicked()
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_fish_stateChanged(int arg1)
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_milk_stateChanged(int arg1)
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_nuts_stateChanged(int arg1)
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_wheat_stateChanged(int arg1)
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_difficultyAny_clicked()
{
    MainWindow::on_searchButton_clicked();
}


void MainWindow::on_userInput_textChanged(const QString &arg1)
{
    MainWindow::on_searchButton_clicked();
}




