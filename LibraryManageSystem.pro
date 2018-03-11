#-------------------------------------------------
#
# Project created by QtCreator 2018-03-07T11:35:23
#
#-------------------------------------------------

QT       += core gui
QT		 += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LibraryManageSystem
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        login.cpp \
    linerlist.cpp \
    nodetype.cpp \
    user.cpp \
    userbook.cpp \
    userinterface.cpp \
    admininterface.cpp \
    book.cpp \
	bookinfo.cpp \
    form.cpp \
    borrowbook.cpp \
    returnbook.cpp \
    addbook.cpp \
    deletebook.cpp \
    adduser.cpp \
    deleteuser.cpp

HEADERS += \
        login.h \
    linerlist.h \
    nodetype.h \
    user.h \
    userbook.h \
    userinterface.h \
    admininterface.h \
    book.h \
	bookinfo.h \
    form.h \
    borrowbook.h \
    returnbook.h \
    addbook.h \
    deletebook.h \
    adduser.h \
    deleteuser.h

FORMS += \
        login.ui \
    userinterface.ui \
	admininterface.ui \
    bookinfo.ui \
    form.ui \
    addbook.ui \
    adduser.ui
