QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 debug
# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH *= headers ../steammath

FORMS += \
    parniscitacka.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

# You can also use this to specify dependencies.  In this case, we dont want
# the build target to run until after the logic and gui targets are complete.
build.depends = libsteammath

# build.file = build.pro # This specifies the .pro file to use

LIBS += -L"$$OUT_PWD/../steammath" -lsteammath


include(files.pri)
