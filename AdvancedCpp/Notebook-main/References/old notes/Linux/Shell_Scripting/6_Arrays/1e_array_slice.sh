#!/bin/bash
 
arr=( "bash" "shell" "script" "tutorial" )
 
arr2=("${arr[@]:1:3}")
 
# for loop that iterates over each element in arr
for i in "${arr2[@]}"
do
    echo $i
done
