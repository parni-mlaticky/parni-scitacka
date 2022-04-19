TEMPLATE = subdirs

SUBDIRS = steammath gui mathtest GoogleTest
gui.depends = steammath
mathtest.depends = steammath
mathtest.depends = GoogleTest
