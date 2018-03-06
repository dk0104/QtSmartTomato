include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS +=     tst_timer_completetomato_completenotificationreceived.h

SOURCES +=     main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../Logic/release/ -lLogic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../Logic/debug/ -lLogic
else:unix: LIBS += -L$$OUT_PWD/../Logic/ -lLogic

INCLUDEPATH += $$PWD/../Logic
DEPENDPATH += $$PWD/../Logic
