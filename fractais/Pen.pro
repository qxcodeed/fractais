TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    lib/pen.cpp \
    lib/cpen.cpp \
    prof/main.cpp \
    aluno/frac_exemplos_cpp.cpp \
    aluno/frac_exemplos_c.cpp

HEADERS += \
    prof/frac_dragao.h \
    prof/frac_gelo.h \
    prof/frac_quadrados.h \
    prof/frac_trigo.h \
    prof/frac_arvore.h \
    prof/frac_circulos.h \
    prof/frac_triangulos.h \
    lib/cpen.h \
    lib/sfLine.h \
    lib/pen.h


CONFIG += c++11
LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
