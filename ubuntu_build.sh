#!/bin/bash

dir="build"
project_dir="IQuizt"


#delete, create and move to dir
cd ..
#if [ -d "$dir" ] eq false; then
#    rm -rf $dir
    mkdir $dir
#fi
cd $dir

#build project
cmake ../$project_dir
#cmake --build . --
make

#run tests
#./tests/QuizItemTest

#run the app
#./$project_dir

