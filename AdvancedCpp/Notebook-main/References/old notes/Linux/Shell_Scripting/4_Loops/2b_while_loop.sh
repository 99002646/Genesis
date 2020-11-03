#!/bin/bash

#This script finds factorial of a number
echo "Enter the number to find the factorial:"
read counter
num=$counter
factorial=1

#while [ $counter -gt 0 ]
#Both above and below lines do the same. Enable only one at a time.
while (( $counter > 0 ))

do
   factorial=$(( $factorial * $counter ))
   counter=$(( $counter - 1 ))
done
echo "Factorial of $num is $factorial"