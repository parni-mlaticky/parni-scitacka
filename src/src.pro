TEMPLATE = subdirs

SUBDIRS = steammath gui mathtest
gui.depends = steammath
mathtest.depends = steammath
