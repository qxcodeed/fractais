TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    frac_arvore.cpp \
    frac_quadrados.cpp \
    frac_gelo.cpp \
    pen.cpp

HEADERS += \
    cpen.h \
    sfLine.h \
    pen.h


CONFIG += c++11
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
