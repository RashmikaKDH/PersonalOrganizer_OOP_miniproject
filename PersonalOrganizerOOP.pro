QT       += core gui sql charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    budgetcreating.cpp \
    expense.cpp \
    financialreports.cpp \
    incomeui.cpp \
    main.cpp \
    loginwindow.cpp \
    organizerui.cpp \
    shedulemaneger.cpp \
    signup.cpp

HEADERS += \
    budgetcreating.h \
    expense.h \
    financialreports.h \
    incomeui.h \
    loginwindow.h \
    organizerui.h \
    shedulemaneger.h \
    signup.h

FORMS += \
    budgetcreating.ui \
    expense.ui \
    financialreports.ui \
    incomeui.ui \
    loginwindow.ui \
    organizerui.ui \
    shedulemaneger.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src.qrc
