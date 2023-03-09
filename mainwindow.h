#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_dropDownBox_triggered(QAction *arg1);

    void on_timeSlider_sliderMoved(int position);

    void on_timeSlider_valueChanged(int value);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
