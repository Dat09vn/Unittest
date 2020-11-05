QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        googlemock/src/gmock-cardinalities.cc \
        googlemock/src/gmock-internal-utils.cc \
        googlemock/src/gmock-matchers.cc \
        googlemock/src/gmock-spec-builders.cc \
        googlemock/src/gmock.cc \
        googletest/src/gtest-death-test.cc \
        googletest/src/gtest-filepath.cc \
        googletest/src/gtest-matchers.cc \
        googletest/src/gtest-port.cc \
        googletest/src/gtest-printers.cc \
        googletest/src/gtest-test-part.cc \
        googletest/src/gtest-typed-test.cc \
        googletest/src/gtest.cc \
        main.cpp

INCLUDEPATH += \
            googletest/include \
            googletest/        \
            googlemock/include \
            googlemock/


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    googletest/src/gtest-internal-inl.h
