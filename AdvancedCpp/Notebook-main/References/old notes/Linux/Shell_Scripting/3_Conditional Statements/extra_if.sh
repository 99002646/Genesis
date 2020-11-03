#!/bin/bash

: '
Checking for multiple conditions
' 
n=2
 
if [ $n -eq 1 ]; then
    echo value of n is 1
elif [[ $n -eq 2 && $n -lt 5 ]]; then
    echo value of n is less than threshold
fi
