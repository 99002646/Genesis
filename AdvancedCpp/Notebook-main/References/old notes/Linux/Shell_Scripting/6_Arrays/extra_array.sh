#!/bin/bash
 
# declare names as an indexed array
declare -a Days
 
# initialize the array
Days=( Mon Tue Wed Thu Fri Sat Sun )
 
# access elements of array using index
echo ${Days[2]}
 
# you may display the atrributes and value of each element of array
declare -p Days
