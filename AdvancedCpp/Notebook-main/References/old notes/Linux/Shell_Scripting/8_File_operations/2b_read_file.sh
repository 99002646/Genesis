#!/bin/bash
FILE_PATH="../test_files/myfile"

while read line; do 
    echo Line $i : $line 
    i=$(( i + 1 ))    
done < $FILE_PATH


<<NOTE1
To prevent backslash escapes while reading file line by line in bash,
use -r option of read command

while read -r line; do 
    echo $line    
 done < fileName
NOTE1

<<NOTE2
 To prevent trimming of leading or trailing white-spaces while reading file line by line in bash,
 use IFS command in conjunction with read command
   
   while IFS= read line; do 
      echo $line    
  done < fileName
<<NOTE2