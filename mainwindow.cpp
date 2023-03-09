#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDesktopServices>
#include <stdlib.h>
#include <string>
#include <stdlib.h>

using namespace std;

QString text;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui -> setupUi(this);
    ui -> timeDisplay -> setAlignment(Qt::AlignCenter);
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


void MainWindow::on_actionApplication_triggered()
{

}


void MainWindow::on_searchButton_clicked()
{

}


void MainWindow::on_dropDownBox_triggered(QAction *arg1)
{

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

