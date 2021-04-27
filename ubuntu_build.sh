#!/bin/bash

dir="build"
project_dir="IQuizt"

#create and move to build directory
cd ..
mkdir $dir
cd $dir

#build project
cmake ../$project_dir

if make
then
  echo "Make succeeded!"
else
  echo "Make failed!"
  exit 1
fi

