TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    frac_arvore.cpp \
    frac_quadrados.cpp \
    frac_gelo.cpp \
    lib/pen.cpp \
    frac_exemplos.cpp

HEADERS += \
    lib/cpen.h \
    lib/sfLine.h \
    lib/pen.h


CONFIG += c++11
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
