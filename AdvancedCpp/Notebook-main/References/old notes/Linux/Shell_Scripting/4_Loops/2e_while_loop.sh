#!/bin/bash

: '
This is an example to read fields in a file
'

FILE_PATH="../test_files/emp.lst"

while IFS='|' read -r f1 f2 f3 
do
    echo "F1: $f1   F2:$f2   F3: $f3"
done < "${FILE_PATH}"

IFS=' '