#!/bin/bash

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
fi