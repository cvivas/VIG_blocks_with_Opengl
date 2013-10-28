TEMPLATE	= app

QT       += opengl

TARGET = LUZ

INCLUDEPATH += ../widget



SOURCES += main.cpp \
	luces.cpp \
        ../widget/luz.cpp \
	../widget/point.cpp

HEADERS += luces.h \
           ../widget/luz.h \
	../widget/point.h

FORMS    +=luces.ui

