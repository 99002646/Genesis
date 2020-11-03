#!/bin/bash
: '
This is a for loop inside for loop example
'
for x in $(seq 1 3); do
	for y in A B C; do
	  echo "$x:$y"
	done
done