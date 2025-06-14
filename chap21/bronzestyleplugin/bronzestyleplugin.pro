TEMPLATE      = lib
TARGET = bronzestyleplugin
QT += widgets
CONFIG       += plugin
HEADERS       = ../bronze/bronzestyle.h \
                bronzestyleplugin.h
SOURCES       = ../bronze/bronzestyle.cpp \
                bronzestyleplugin.cpp \
    bronzestyle.cpp
RESOURCES     = ../bronze/bronze.qrc
DESTDIR       = styles #$$[QT_INSTALL_PLUGINS]/styles
#DESTDIR       = $$[QT_INSTALL_PLUGINS]/styless

EXAMPLE_FILES += bronzestyle.json
