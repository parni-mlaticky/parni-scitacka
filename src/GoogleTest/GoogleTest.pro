TEMPLATE = lib
CONFIG += c++14
CONFIG += static exceptions
CONFIG -= debug_and_release

TARGET = GoogleTest

INCLUDEPATH += \
    googletest/googletest/include \
    googletest/googletest

SOURCES = \
    googletest/googletest/src/gtest-all.cc
