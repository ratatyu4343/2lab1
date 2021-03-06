QT       += core gui testlib
QT += widgets printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

SOURCES += \
    main.cpp \
    mainwindow.cpp\
    qcustomplot.cpp\
    tests/unittests.cpp \
    tree_node.cpp

HEADERS += \
    mainwindow.h \
    tree.h\
    qcustomplot.h\
    tests/unittests.h \
    tree_node.h

FORMS += \
    mainwindow.ui

SUBDIRS += tests

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
