TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QT += opengl
LIBS += -lopengl32


SOURCES += \
    my_gl_lib.c \
    my_algo_lib.c \
    Lines_vs_curves.c

win32: LIBS += -L$$PWD/../../glfw.bin/lib-mingw/ -lglfw3

INCLUDEPATH += $$PWD/../../glfw.bin/lib-mingw
DEPENDPATH += $$PWD/../../glfw.bin/lib-mingw

win32: LIBS += -L$$PWD/../../glfw.bin/lib-mingw/ -lglfw3dll

INCLUDEPATH += $$PWD/../../glfw.bin/lib-mingw
DEPENDPATH += $$PWD/../../glfw.bin/lib-mingw

INCLUDEPATH += $$PWD/../../glfw.bin/include/GLFW

HEADERS += \
    ../../glfw.bin/include/GLFW/glfw3.h \
    ../../glfw.bin/include/GLFW/glfw3native.h \
    ../../glew-2.0.0/include/GL/eglew.h \
    ../../glew-2.0.0/include/GL/glew.h \
    ../../glew-2.0.0/include/GL/glxew.h \
    ../../glew-2.0.0/include/GL/wglew.h \
    ../../glutdlls36/glut.h \
    my_gl_lib.h \
    my_algo_lib.h \
    ../external_libs/glut/include/glut.h

win32: LIBS += -L$$PWD/../../QT/Tools/mingw530_32/i686-w64-mingw32/lib/ -lgdi32

INCLUDEPATH += $$PWD/../../QT/Tools/mingw530_32/i686-w64-mingw32/include
DEPENDPATH += $$PWD/../../QT/Tools/mingw530_32/i686-w64-mingw32/include

win32: LIBS += -L$$PWD/../../glew-2.0.0/lib/Release/Win32/ -lglew32

INCLUDEPATH += $$PWD/../../glew-2.0.0/lib/Release/Win32
DEPENDPATH += $$PWD/../../glew-2.0.0/lib/Release/Win32

win32: LIBS += -L$$PWD/../../glew-2.0.0/lib/Release/Win32/ -lglew32s

INCLUDEPATH += $$PWD/../../glew-2.0.0/lib/Release/Win32
DEPENDPATH += $$PWD/../../glew-2.0.0/lib/Release/Win32

INCLUDEPATH += $$PWD/../../glew-2.0.0/include/GL

DISTFILES += \
    notes.txt


win32: LIBS += -L$$PWD/../external_libs/glut/lib/ -lglut32

INCLUDEPATH += $$PWD/../external_libs/glut/include
DEPENDPATH += $$PWD/../external_libs/glut/include
