QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    model/math_functions.c \
    model/s21_smart_calc.c \
    model/stack.c \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    model/math_functions.h \
    model/s21_smart_calc.h \
    model/stack.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    s21_SmartCalc_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
