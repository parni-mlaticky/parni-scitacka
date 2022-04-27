#!/usr/bin/env bash

sudo apt update
sudo apt install git qtdeclarative5-dev qt5-qmake g++
#cd (adresar-programu)/src
make
sudo cp ../build/gui/gui /usr/bin/parni-scitacka
sudo chmod a+x /usr/bin/parni-scitacka
cp meta/parni-scitacka.desktop ~/.local/share/applications
sudo cp meta/parni-scitacka.xpm /usr/share/pixmaps/
