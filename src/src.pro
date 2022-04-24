TEMPLATE = subdirs

SUBDIRS = steammath gui mathtest GoogleTest standard-deviation
gui.depends = steammath
mathtest.depends = steammath
standard-deviation.depends = steammath
mathtest.depends = GoogleTest
