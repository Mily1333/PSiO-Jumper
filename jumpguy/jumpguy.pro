TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        block.cpp \
        coin.cpp \
        game.cpp \
        main.cpp \
        player.cpp \
        przepis.cpp
        przepis.cpp
        INCLUDEPATH += "C:/SFML-2.5.1/include"
              LIBS += -L"C:/SFML-2.5.1/lib"
              CONFIG(debug, debug|release){
                  LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
              } else {
                  LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
              }

HEADERS += \
    block.h \
    coin.h \
    game.h \
    player.h \
    przepis.h
