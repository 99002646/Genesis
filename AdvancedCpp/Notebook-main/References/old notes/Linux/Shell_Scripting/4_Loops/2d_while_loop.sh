#!/bin/bash

: '
This is an example to feed output of command to while loop
'

while read -r line
do
    echo $line
done < <(ls -lt)