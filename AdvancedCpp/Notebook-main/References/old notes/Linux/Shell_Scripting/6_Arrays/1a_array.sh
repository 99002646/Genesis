#!/bin/bash

NUM[0]="zero"
NUM[1]="one"
NUM[2]="two"
NUM[3]="three"
NUM[4]="four"

echo "NUM[0] =${NUM[0]}"
echo "Last member of NUM array is ${NUM[${#NUM[@]}-1]}"

echo "Size of array NUM is ${#NUM[@]}"
echo "Size of array NUM is ${#NUM[*]}"

echo "All array members can be accessed in two methods"
echo "First Method: ${NUM[*]}"
echo "Second Method: ${NUM[@]}"