#!/bin/bash

#This example loops through the file contents and prints macthing cases
FILE_PATH="../test_files/myfile"
while read f
do
  case $f in
	1)				echo "Case 1:" $f ;;
	second)			echo "Case 2:" $f ;;
	3)				echo "Case 3:" $f ;;
	"hello world")	echo "Case 4:" $f ;;
	*)				echo "Default case: " $f;;
   esac
#done < ../test_files/myfile
done < "${FILE_PATH}"