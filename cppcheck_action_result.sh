#!/bin/bash
filename=$1
n=1
while read line; do
  # reading each line
  echo "$n : $line"
  n=$((n+1))
done < $filename

if [[ $n -ne 1 ]]
then
  echo "There is room for improvements."
  exit 1
else
  echo "The code is correct from cppcheck's view."
fi