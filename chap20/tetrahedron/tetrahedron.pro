TEMPLATE      = app
QT +=core gui opengl


CONFIG       += console
HEADERS       = tetrahedron.h
SOURCES       = main.cpp \
                tetrahedron.cpp


LIBS+=-lopengl32 -lglu32
