QT = websockets
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = webserver
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += \
    main.cpp \
    webserver.cpp

HEADERS += \
    webserver.h \
    rodcheck.h

EXAMPLE_FILES += echoclient.html

target.path = $$[QT_INSTALL_EXAMPLES]/websockets/webserver
INSTALLS += target


