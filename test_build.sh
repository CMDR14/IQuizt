#!/bin/bash

#Makes only the given test from the test folder
#first parameter is the name of the directory in the test folder
#second parameter is a optional -ctest flag, if given, ctest will run

dir="build"
project_dir=$1

cd ..
mkdir build_test
cd build_test
cmake ../IQuizt/tests/$project_dir


if make
then
  if [[ $2 == "-ctest" ]]
  then
    ctest
  fi
else
  echo "Make failed"
  exit 1
fi