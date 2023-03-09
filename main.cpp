#include "mainwindow.h"
#include "filehandler.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QDesktopServices>

int main(int argc, char *argv[])
{
    fileHandler fl;
    fl.readFile();

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
}
