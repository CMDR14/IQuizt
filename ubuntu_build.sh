#!/bin/bash

dir="build"
project_dir="IQuizt"


#delete, create and move to dir
cd ..
if [ -d "$dir" ] eq false; then
#    rm -rf $dir
    mkdir $dir
fi
cd $dir

#install packages
sudo apt install -y cmake
sudo apt install -y make
sudo apt install -y gcc
sudo apt install -y qt5-default

#build project
cmake ../$project_dir
cmake --build . --

#run the app
./$project_dir

