#!/bin/bash

: '
This example loops through the content of file.
Make Sure the file already exists in folder.
'

FILE_PATH="../test_files/myfile"
line_num=1
while read f
do
	echo "Line $line_num = $f"
	line_num=$(( line_num+1 ))
	
done < "${FILE_PATH}"