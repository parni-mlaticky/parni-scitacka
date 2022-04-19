TEMPLATE = subdirs

SUBDIRS = steammath mathtest GoogleTest
mathtest.depends = steammath
mathtest.depends = GoogleTest
