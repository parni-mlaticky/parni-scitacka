TEMPLATE = lib

# By default, qmake will make a shared library.  Uncomment to make the library
# static.
CONFIG += staticlib debug

# By default, TARGET is the same as the directory, so it will make
# liblibrary.so or liblibrary.a (in linux).  Uncomment to override.
# TARGET = target

include(files.pri)
