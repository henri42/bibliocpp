QT += widgets

CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11

SOURCES += \
    main.cpp \
    adminmenu.cpp \
    logmenu.cpp \
    mainwindow.cpp \
    vueliste.cpp \
    clientmenu.cpp \
    ../mediatheque.cpp \
    ../saisie.cpp \
    ../user.cpp \
    ../admin.cpp \
    ../cd_dvd.cpp \
    ../livre.cpp \
    ../media.cpp \
    ../ressource_num.cpp \
    ../revue.cpp \
    ../VHS.cpp

HEADERS += \
    adminmenu.h \
    logmenu.h \
    mainwindow.h \
    vueliste.h \
    clientmenu.h \
    ../admin.hpp \
    ../media.hpp \
    ../mediatheque.hpp \
    ../user.hpp \
    ../cd_dvd.hpp \
    ../livre.hpp \
    ../ressource_num.hpp \
    ../revue.hpp \
    ../VHS.hpp

DISTFILES += \
    ../build_bibliozer/livre.png
