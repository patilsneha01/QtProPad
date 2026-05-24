#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setStyleSheet(
        "QMainWindow {"
        "    background-color: #4b4b4b;"
        "}"

        "QTextEdit {"
        "    background-color: #1e1e1e;"
        "    color: #ffffff;"
        "    border: 1px solid #3c3f41;"
        "    padding: 10px;"
        "    font-size: 14px;"
        "    selection-background-color: #4a90e2;"
        "}"

        "QMenuBar {"
        "    background-color: #313335;"
        "    color: white;"
        "}"

        "QMenuBar::item:selected {"
        "    background-color: #4a90e2;"
        "}"

        "QMenu {"
        "    background-color: #313335;"
        "    color: white;"
        "}"

        "QMenu::item:selected {"
        "    background-color: #4a90e2;"
        "}"

        "QToolBar {"
        "    background-color: #313335;"
        "    spacing: 5px;"
        "    padding: 5px;"
        "}"

        "QToolButton {"
        "    background-color: #3c3f41;"
        "    color: white;"
        "    border-radius: 4px;"
        "    padding: 5px;"
        "}"

        "QToolButton:hover {"
        "    background-color: #4a90e2;"
        "}"

        "QStatusBar {"
        "    background-color: #313335;"
        "    color: white;"
        "}"
        );

    MainWindow w;
    w.show();
    return a.exec();
}
