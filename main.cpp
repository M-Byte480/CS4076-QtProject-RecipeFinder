#include "allergybitstruct.h"
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDesktopServices>
#include "tmp.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    //*/
    QApplication a(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "cs4076_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;
    w.show();
    return a.exec();
    //*/

    /*/
    tmp x(1, 2, 3, 4);

    cout << x.a << x.b << x.c << x.d << endl;
    cout << x.x << x.y << endl;


    AllergyFlag a;
    a.setFlag(AllergyBitStruct::wheat);
    a.printBits();
    return 0;
    //*/
}

