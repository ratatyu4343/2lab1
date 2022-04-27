#include "mainwindow.h"

#include <QApplication>
#include <tests/unittests.h>
#include <QTest>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QTest::qExec(new UnitTests, argc, argv);
    return a.exec();
}
