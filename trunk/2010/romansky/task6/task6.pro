######################################################################
# Automatically generated by qmake (2.01a) ?? ???. 31 16:53:38 2010
######################################################################

TEMPLATE = subdirs
TARGET = 
DEPENDPATH += . console view
INCLUDEPATH += . console view

# Input
HEADERS += console/Console.h \
           console/ConsoleHandler.h \
           console/State.h \
           view/Ball.h \
           view/BallWidget.h \
           view/Racket.h \
           view/View.h \
           view/ViewHandler.h
SOURCES += console/Console.cpp \
           console/ConsoleHandler.cpp \
           console/main.cpp \
           console/State.cpp \
           view/Ball.cpp \
           view/BallWidget.cpp \
           view/main.cpp \
           view/Racket.cpp \
           view/View.cpp \
           view/ViewHandler.cpp
SUBDIRS += console view