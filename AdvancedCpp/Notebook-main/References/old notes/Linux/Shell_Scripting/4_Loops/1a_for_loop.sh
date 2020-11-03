#!/bin/sh

: '
This is an example for loop
'
for i in 2 3 4 5 1
do
  echo "Looping ... number $i"
done

for i in hello 1 * 2 goodbye 
do
  echo "Looping ... i is set to $i"
done