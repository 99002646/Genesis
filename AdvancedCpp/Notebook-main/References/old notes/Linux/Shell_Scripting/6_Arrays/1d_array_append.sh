#!/bin/bash
 
arr=( "bash" "shell" "script" )
 
arr+=("tutorial")
 
# for loop that iterates over each element in arr
for i in "${arr[@]}"
do
    echo $i
done
