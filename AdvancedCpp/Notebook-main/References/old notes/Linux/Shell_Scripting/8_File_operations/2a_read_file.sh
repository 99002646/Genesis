#!/bin/sh

FILE1_PATH="../test_files/myfile"
FILE2_PATH="../test_files/emp.lst"
value=`cat $FILE1_PATH`
echo "File1 content:"
echo "$value"

value1=$(<"$FILE2_PATH")
echo "File2 content:"
echo  "$value1"
